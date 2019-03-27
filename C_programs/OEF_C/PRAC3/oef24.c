#include <stdio.h>

void schrijf(const char *, const char *);
void pivoteer(char *, char *, char *);

int main() {
    char tekst[] = {'b', 'd', '?', 'z', 'g', 'o', 'e', 'z', 'e', 'b', ' ', 'd', 'i', 'g', '!', 'h', 'o', 's', 'v'};
    pivoteer(tekst + 7, tekst + 12, tekst + 9);
    schrijf(tekst + 4, tekst + 15);

    printf("\n");
    char alfa[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    pivoteer(alfa, alfa + 7, alfa + 2);
    schrijf(alfa, alfa + 8);

    return 0;
}

void schrijf(const char *b, const char *e) {
    int i;
    for (i = 0; i < (e - b); i++) {
        printf("%c", *(b + i));
    }
}

void pivoteer(char *b, char *e, char *pivot) {
    char hulp;
    int i;
    for (i = 1; i <= pivot - b; i++) {
        hulp = *(pivot - i);
        *(pivot - i) = *(pivot + i);
        *(pivot + i) = hulp;
    }
}
