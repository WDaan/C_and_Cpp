#include <stdio.h>

int main() {
    int macht = 1;
    while (macht < 100) {
        macht *= 2;
        printf("%d \n", macht);
    }

    return 0;
}