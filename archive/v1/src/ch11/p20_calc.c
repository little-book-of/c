#include "p20_calc.h"
int add(int a,int b){return a+b;}
int sub(int a,int b){return a-b;}
int mul(int a,int b){return a*b;}
int div_int(int a,int b){return b? a/b:0;}
int mod(int a,int b){return b? a%b:0;}
int pow_int(int base,int exp){
    if(exp<0) return 0;
    int r=1; while(exp--) r*=base; return r;
}
