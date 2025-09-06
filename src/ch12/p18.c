#include <stdio.h>
#include <stdlib.h>
#include <time.h>
static int r6(void){ return 1 + rand()%6; }
int main(void){
    srand((unsigned)time(NULL));
    int cnt=0;
    for(int i=0;i<1000;i++) if (r6()+r6()==7) cnt++;
    printf("sevens=%d\n", cnt);
    return 0;
}
