#include <stdio.h>

int ggd(int a, int b);
int ggd_fix(int a, int b);

int main() {
    int i, n;
    i = ggd(-24, 18);
    printf("\nantwd : %d", i);

    n = ggd_fix(18, 0);
    printf("\nantwd met fix : %d", n);

    return 0;
}

int ggd(int a, int b) {  //kan negatieve ggd's geven
    if (b == 0)
        return a;
    else
        return ggd(b, a % b);
}

int ggd_fix(int a, int b) {
    if (b == 0)
        return a < 0 ? -a : a;
    else
        return ggd_fix(b, a % b);
}
