#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { AVAILABLE, BORROWED } BookStatus;

typedef struct Book {
    char *title;
    char *author;
    int year;
    BookStatus status;
    struct Book *next;
} Book;

typedef struct { Book *head; } Library;

Book *create_book(const char *title, const char *author, int year) {
    Book *b = malloc(sizeof(Book));
    b->title = strdup(title);
    b->author = strdup(author);
    b->year = year;
    b->status = AVAILABLE;
    b->next = NULL;
    return b;
}

void add_book(Library *lib, Book *b) {
    b->next = lib->head;
    lib->head = b;
}

Book *find_book(Library *lib, const char *title) {
    for (Book *cur = lib->head; cur; cur = cur->next)
        if (strcmp(cur->title, title) == 0) return cur;
    return NULL;
}

void borrow_book(Library *lib, const char *title) {
    Book *b = find_book(lib, title);
    if (!b) { printf("Book not found: %s\n", title); return; }
    if (b->status == BORROWED)
        printf("Book already borrowed: %s\n", b->title);
    else { b->status = BORROWED; printf("You borrowed: %s\n", b->title); }
}

void return_book(Library *lib, const char *title) {
    Book *b = find_book(lib, title);
    if (!b) { printf("Book not found: %s\n", title); return; }
    if (b->status == AVAILABLE)
        printf("Book already returned: %s\n", b->title);
    else { b->status = AVAILABLE; printf("You returned: %s\n", b->title); }
}

void list_books(const Library *lib) {
    printf("\n--- Library Catalog ---\n");
    for (const Book *b = lib->head; b; b = b->next)
        printf("%-30s | %-20s | %d | %s\n",
               b->title, b->author, b->year,
               b->status == AVAILABLE ? "Available" : "Borrowed");
    printf("------------------------\n\n");
}

void free_library(Library *lib) {
    Book *cur = lib->head;
    while (cur) {
        Book *next = cur->next;
        free(cur->title); free(cur->author); free(cur);
        cur = next;
    }
    lib->head = NULL;
}

int main(void) {
    Library lib = {NULL};
    add_book(&lib, create_book("The C Programming Language", "Kernighan & Ritchie", 1988));
    add_book(&lib, create_book("Clean Code", "Robert C. Martin", 2008));
    add_book(&lib, create_book("Algorithms in C", "Sedgewick", 1998));
    list_books(&lib);
    borrow_book(&lib, "Clean Code");
    borrow_book(&lib, "Clean Code");
    return_book(&lib, "Clean Code");
    borrow_book(&lib, "Algorithms in C");
    list_books(&lib);
    free_library(&lib);
    return 0;
}
