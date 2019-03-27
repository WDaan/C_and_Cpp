#include <stdio.h>

int fac(int n);
int fac_rec(int n);

int main() {
    int a, b;
    a = fac(3);
    b = fac_rec(3);
    printf("\n fac : %d", a);
    printf("\n fac_rec : %d", b);
    return 0;
}

int fac(int n) {
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}

int fac_rec(int n) {
    if (n < 2)
        return 1;
    else
        return fac(n - 1) * n;
}