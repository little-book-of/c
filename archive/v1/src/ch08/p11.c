#include <stdio.h>

enum ErrorCode { OK=0, FAIL=1, TIMEOUT=2 };

int main(void) {
    enum ErrorCode e;
    int x; scanf("%d", &x);
    e = (x==0)?OK : (x==1)?FAIL : TIMEOUT;

    switch (e) {
        case OK: puts("OK"); break;
        case FAIL: puts("FAIL"); break;
        case TIMEOUT: puts("TIMEOUT"); break;
    }
    return 0;
}
