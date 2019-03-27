#include <stdio.h>

void schrijf(const char *, const char *);
void schrijf_aantal(char *, int);

int main() {
    char letters[] = {'p', 'o', 'r', 'e', 'o', 'i', 'f', 'o', 'i', 'e', 'c', 'i', 'i', ':', 'a', '-', 't', '('};

    int grootte = sizeof(letters) / sizeof(char);

    const char *p = letters;

    int grootte2 = sizeof(p) / sizeof(char);

    printf("Grootte  : %d", grootte);
    printf("\nGrootte2  : %d", grootte2);

    schrijf_aantal(letters + 3, 4);
    printf("\n");
    schrijf(p + 10, p + 12);
    printf("\n");

    /* voeg onderstaande code toe in het hoofdprogramma: */
    printf("Aantal elementen in array : %d\n", sizeof(letters) / sizeof(char));
    printf("Aantal elementen via pointer: %d\n", sizeof(p) / sizeof(char));

    /* sizeof pointer is altijd 8 !*/
    printf("sizeof pointer to letter %d: \n", sizeof(p));
    printf("sizeof char* : %d  \n", sizeof(char *));
    printf("sizeof int* : %d  \n", sizeof(int *));
    printf("sizeof double* : %d  \n", sizeof(double *));
    printf("sizeof void* : %d \n", sizeof(void *));

    return 0;
}

void schrijf_aantal(char *p, int a) {
    printf("\n");
    int i;
    for (i = 0; i < a; i++) {
        printf("%c", *(p + i));
    }
}

void schrijf(const char *b, const char *e) {
    while (b < e) {
        printf("%c", *b);
        b++;
    }
}
