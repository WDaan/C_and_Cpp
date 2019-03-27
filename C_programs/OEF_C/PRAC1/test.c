#include <stdio.h>

/*
int main() {

    if(2>3){
        printf("yesssss");
    }
    else {
        printf("nooo");
    }

    return 0;
}

*/

int main() {
    int x;
    double sum = 0, v;
    printf("Enter an integer: ");
    if (scanf("%d", &x) == 0)
        printf("Error: not an integer\n");
    else
        printf("Read in %d\n", x);
    while (scanf("%lf", &v) == 1) printf("\t%.2f\n", sum += v);
    return 0;
}
