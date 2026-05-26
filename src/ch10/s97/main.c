// file: tiny_interp.c
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* ----- tiny arena ----- */
typedef struct { unsigned char *base; size_t cap, off; } Arena;
static Arena *arena_new(size_t cap){ Arena*a=malloc(sizeof(*a)); if(!a)return NULL; a->base=malloc(cap); if(!a->base){free(a);return NULL;} a->cap=cap; a->off=0; return a;}
static void *arena_alloc(Arena*a,size_t n,size_t al){ size_t p=(a->off+(al-1))&~(al-1); if(p+n>a->cap)return NULL; void*ptr=a->base+p; a->off=p+n; return ptr; }
static void arena_free(Arena*a){ if(!a)return; free(a->base); free(a); }

/* ----- tokens ----- */
typedef enum { TOK_INT, TOK_PLUS, TOK_MINUS, TOK_STAR, TOK_SLASH,
               TOK_LPAREN, TOK_RPAREN, TOK_IDENT, TOK_EQ, TOK_EOF, TOK_ERR } TokKind;

typedef struct { TokKind kind; long ival; const char *s,*e; char *lexeme; } Token;

typedef struct { const char *src,*cur; Token look; } Lexer;

static void skip_ws(Lexer*L){ while(isspace((unsigned char)*L->cur)) L->cur++; }
static Token make_tok(TokKind k,const char*s,const char*e,long v,char*lex){ return (Token){k,v,s,e,lex}; }

static Token next_raw(Lexer*L){
    skip_ws(L); const char*s=L->cur; if(*L->cur==0) return make_tok(TOK_EOF,s,s,0,NULL);
    char c=*L->cur++;
    if (c=='+') return make_tok(TOK_PLUS, s,L->cur,0,NULL);
    if (c=='-') return make_tok(TOK_MINUS,s,L->cur,0,NULL);
    if (c=='*') return make_tok(TOK_STAR, s,L->cur,0,NULL);
    if (c=='/') return make_tok(TOK_SLASH,s,L->cur,0,NULL);
    if (c=='(') return make_tok(TOK_LPAREN,s,L->cur,0,NULL);
    if (c==')') return make_tok(TOK_RPAREN,s,L->cur,0,NULL);
    if (c=='=') return make_tok(TOK_EQ,    s,L->cur,0,NULL);
    if (isdigit((unsigned char)c)) {
        long v = c - '0'; const char*p=L->cur;
        while (isdigit((unsigned char)*p)) { v = v*10 + (*p - '0'); p++; }
        L->cur = p; return make_tok(TOK_INT, s,p,v,NULL);
    }
    if (isalpha((unsigned char)c) || c=='_') {
        const char*p=L->cur; while (isalnum((unsigned char)*p) || *p=='_') p++;
        size_t n = (size_t)(p - (L->cur-1)); // include first char
        char *lex = malloc(n+1);
        memcpy(lex, s, n); lex[n] = 0;
        L->cur = p; return make_tok(TOK_IDENT,s,p,0,lex);
    }
    return make_tok(TOK_ERR, s,L->cur,0,NULL);
}
static void lex_init(Lexer*L,const char*src){ L->src=src; L->cur=src; L->look=next_raw(L); }
static Token peek(Lexer*L){ return L->look; }
static Token take(Lexer*L){ Token t=L->look; L->look=next_raw(L); return t; }

/* ----- AST ----- */
typedef enum { N_INT, N_ADD, N_SUB, N_MUL, N_DIV, N_IDENT, N_ASSIGN } NodeKind;
typedef struct Node { NodeKind k; struct Node *l,*r; long v; const char*name; } Node;

static Node* new_int(Arena*A,long v){ Node*n=arena_alloc(A,sizeof(*n),_Alignof(Node)); if(!n)return NULL; n->k=N_INT; n->l=n->r=NULL; n->v=v; n->name=NULL; return n; }
static Node* new_ident(Arena*A,const char*name){ Node*n=arena_alloc(A,sizeof(*n),_Alignof(Node)); if(!n)return NULL; n->k=N_IDENT; n->l=n->r=NULL; n->v=0; n->name=name; return n; }
static Node* new_bin(Arena*A,NodeKind k,Node*l,Node*r){ Node*n=arena_alloc(A,sizeof(*n),_Alignof(Node)); if(!n)return NULL; n->k=k; n->l=l; n->r=r; n->v=0; n->name=NULL; return n; }
static Node* new_assign(Arena*A,Node*name,Node*expr){ Node*n=arena_alloc(A,sizeof(*n),_Alignof(Node)); if(!n)return NULL; n->k=N_ASSIGN; n->l=name; n->r=expr; n->v=0; n->name=NULL; return n; }

/* ----- parser ----- */
typedef struct { Lexer*L; Arena*A; int ok; } Parser;
static void fail(Parser*P,const char*msg,Token t){ P->ok=0; size_t pos=(size_t)(t.s - P->L->src); fprintf(stderr,"Parse error at %zu: %s\n", pos, msg); }

static Node* parse_expr(Parser*P); // forward

static Node* parse_factor(Parser*P){
    Token t = peek(P->L);
    if (t.kind==TOK_INT){ take(P->L); return new_int(P->A, t.ival); }
    if (t.kind==TOK_IDENT){ take(P->L); return new_ident(P->A, t.lexeme); }
    if (t.kind==TOK_LPAREN){ take(P->L); Node*e=parse_expr(P); if(peek(P->L).kind!=TOK_RPAREN){ fail(P,"expected ')'",peek(P->L)); return NULL;} take(P->L); return e; }
    fail(P,"expected number, name, or '('", t); return NULL;
}
static Node* parse_term(Parser*P){
    Node*n=parse_factor(P);
    while(P->ok){
        TokKind k = peek(P->L).kind;
        if(k!=TOK_STAR && k!=TOK_SLASH) break;
        take(P->L);
        Node*r=parse_factor(P); if(!r) return NULL;
        n=new_bin(P->A, k==TOK_STAR?N_MUL:N_DIV, n, r);
    }
    return n;
}
static Node* parse_expr(Parser*P){
    Node*n=parse_term(P);
    while(P->ok){
        TokKind k = peek(P->L).kind;
        if(k!=TOK_PLUS && k!=TOK_MINUS) break;
        take(P->L);
        Node*r=parse_term(P); if(!r) return NULL;
        n=new_bin(P->A, k==TOK_PLUS?N_ADD:N_SUB, n, r);
    }
    return n;
}
static Node* parse_stmt(Parser*P){
    if (peek(P->L).kind==TOK_IDENT){
        // look ahead for '='
        Token save = P->L->look;
        Token ident = take(P->L);
        if (peek(P->L).kind==TOK_EQ){
            take(P->L); // consume '='
            Node*rhs = parse_expr(P);
            if (!rhs) return NULL;
            return new_assign(P->A, new_ident(P->A, ident.lexeme), rhs);
        }
        // no '=', rewind
        P->L->look = save;
    }
    return parse_expr(P);
}

/* ----- environment ----- */
typedef struct { const char*name; long value; } Binding;
typedef struct { Binding *items; size_t count, cap; } Env;
static long* env_get(Env*E,const char*name){ for(size_t i=0;i<E->count;i++) if(strcmp(E->items[i].name,name)==0) return &E->items[i].value; return NULL; }
static int env_set(Env*E,const char*name,long v){
    long*p=env_get(E,name); if(p){*p=v; return 1;}
    if(E->count==E->cap){ size_t ncap=E->cap?E->cap*2:16; Binding*n=realloc(E->items,ncap*sizeof(*n)); if(!n)return 0; E->items=n; E->cap=ncap; }
    E->items[E->count++] = (Binding){ strdup(name), v };
    return 1;
}

/* ----- evaluator ----- */
static int eval(Node*n, Env*E, long *out){
    if(!n) return 0;
    switch(n->k){
        case N_INT: *out = n->v; return 1;
        case N_IDENT: {
            long *p = env_get(E, n->name);
            if(!p){ fprintf(stderr,"Name not found: %s\n", n->name); return 0; }
            *out = *p; return 1;
        }
        case N_ADD: { long a,b; if(!eval(n->l,E,&a)||!eval(n->r,E,&b)) return 0; *out=a+b; return 1; }
        case N_SUB: { long a,b; if(!eval(n->l,E,&a)||!eval(n->r,E,&b)) return 0; *out=a-b; return 1; }
        case N_MUL: { long a,b; if(!eval(n->l,E,&a)||!eval(n->r,E,&b)) return 0; *out=a*b; return 1; }
        case N_DIV: {
            long a,b; if(!eval(n->l,E,&a)||!eval(n->r,E,&b)) return 0;
            if(b==0){ fprintf(stderr,"Divide by zero\n"); return 0; }
            *out=a/b; return 1;
        }
        case N_ASSIGN: {
            long v; if(!eval(n->r,E,&v)) return 0;
            if(!n->l || n->l->k != N_IDENT){ fprintf(stderr,"Left side of '=' must be a name\n"); return 0; }
            if(!env_set(E, n->l->name, v)){ fprintf(stderr,"Env set failed\n"); return 0; }
            *out = v; return 1;
        }
    }
    return 0;
}

/* ----- simple REPL ----- */
int main(void){
    char *line = NULL; size_t n = 0;
    Env env = {0};
    puts("tiny repl. enter expressions or assignments. Ctrl D to exit.");
    while (1){
        printf("> "); fflush(stdout);
        ssize_t m = getline(&line, &n, stdin);
        if (m <= 0) break;

        // strip newline
        if (m>0 && line[m-1]=='\n') line[m-1]=0;

        Arena *A = arena_new(1<<16);
        if(!A){ fprintf(stderr,"arena failed\n"); break; }

        Lexer L; lex_init(&L, line);
        Parser P = { .L=&L, .A=A, .ok=1 };
        Node* root = parse_stmt(&P);

        long result = 0;
        if (P.ok && root && eval(root, &env, &result))
            printf("%ld\n", result);
        else
            fprintf(stderr,"Error\n");

        arena_free(A);
    }
    free(line);
    // free env bindings
    for(size_t i=0;i<env.count;i++) free((void*)env.items[i].name);
    free(env.items);
    return 0;
}
