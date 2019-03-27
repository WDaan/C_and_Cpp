#include <stdio.h>

int main() {
    int i = 0;
    int getal = 0, som = 0;
    printf("Geef een getal in : ");
    //scanf("%d", &getal);
    while (i < 5 && getal >= 0) {
        scanf("%d", &getal);
        som += getal;
        i++;
    }

    if (i == 5 && getal > 0)
        printf("U gaf %d positieve getallen in", i);
    else
        printf("Nope.");

    printf("\nDe som is : %d  ", som);

    return 0;
}
