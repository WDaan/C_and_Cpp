#include <stdio.h>
#include <string.h>

void my_toupper(char *);
const char *alfab_kleinste(const char *const *, int n);

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("Dag allemaal!");
    } else if (argc > 1) {
        const char *eerste = alfab_kleinste((const char *const *)argv + 1, argc - 1);
        printf("Dag %s!", eerste);
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

const char *alfab_kleinste(const char *const *s, int n) {
    const char *kleinste = *s++;  // eerste erin steken en al opschuiven
    int i;
    for (i = 1; i < n; i++) {
        if (strcmp(*s, kleinste) < 0) {
            kleinste = *s;  // 1x * is het woord, ** is de letter!
        }
        s++;  // pointer naar het volgende woord opschuiven
    }
    return kleinste;
}
