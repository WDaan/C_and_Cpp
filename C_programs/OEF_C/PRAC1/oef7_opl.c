#include <math.h>
#include <stdio.h>

int main() {
    double x = 0.23;
    double term = x;
    double som;
    int n = 2 * 10;
    int i;
    som = x;
    for (i = 2; i <= n; i += 2) {
        term *= -x * x / (i * (i + 1));
        som += term;
    }
    printf("sin (%.2f) = %.16f \n", x, som);
    printf("controle %.16f \n", sin(x));
    return 0;
}