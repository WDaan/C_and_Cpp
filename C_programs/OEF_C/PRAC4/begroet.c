#include <stdio.h>

void my_toupper(char *);

int main(int argc, char **argv) {
    if (argc > 1) {
        int i;
        for (i = 1; i < argc; i++) {
            my_toupper(argv[i]);
            printf("\nDag %s!", argv[i]);
        }
    } else {
        printf("Dag allemaal!");
    }

    return 0;
}

void my_toupper(char *s) {
    char *b = s;
    while (*s) {
        if (*s >= 'A' && *s <= 'Z') {
            *s += 'a' - 'A';
        }
        s++;
    }
    *b += 'A' - 'a';
}
