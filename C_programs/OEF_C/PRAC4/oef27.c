#include <stdio.h>

void schrijf(const char *, const char *);
const char *pointer_naar_eerste_kleine_letter(const char *);
void verzet_naar_eerste_hoofdletter(const char **);

int main() {
    const char zus1[50] = "sneeuwWITje";
    const char zus2[50] = "rozeROOD";
    const char *begin;
    const char *eind;
    begin = zus1;
    verzet_naar_eerste_hoofdletter(&begin);
    eind = pointer_naar_eerste_kleine_letter(begin);
    schrijf(begin, eind); /* schrijft ’WIT’ uit */
    printf("\n");
    begin = zus2;
    verzet_naar_eerste_hoofdletter(&begin);
    eind = pointer_naar_eerste_kleine_letter(begin);
    schrijf(begin, eind); /* schrijft ’ROOD’ uit */
    return 0;
}

void schrijf(const char *b, const char *e) {
    int i;
    for (i = 0; i < (e - b); i++) {
        printf("%c", *(b + i));
    }
}

const char *pointer_naar_eerste_kleine_letter(const char *p) {
    while (*p != '\0' && !(*p >= 'a' && *p <= 'z')) {
        p++;
    }
    return p;
}

void verzet_naar_eerste_hoofdletter(const char **p) {
    while (**p != '\0' && !(**p >= 'A' && **p <= 'Z')) {
        (*p)++;
    }
}
