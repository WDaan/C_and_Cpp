#include <ctype.h>
#include <stdio.h>

void verwijder(char *);

int main() {
    char s[] =
        "8d’a7!<t-)>+. -)4h&!e9)b*( )j’(e)!4\n8g|’92o!43e5d/.’ 2 3g*(e(’d22a’(a25n’(";
    printf("Before remove : %s", s);
    verwijder(s);
    printf("\nAfter remove : %s", s);

    char z[50];
    printf("\nMET INPUT, Geef maar in : ");
    fgets(z, 49, stdin);
    printf("\nBefore remove : %s", z);
    verwijder(z);
    printf("\nAfter remove : %s", z);
    printf("\n%s", (z + 7)); /*je kan dus wel nog aan character achter het nieuw ingevoegde 0-karakter*/

    return 0;
}

void verwijder(char *s) {
    char *new_s = s;
    while (*s) {
        if ((*s >= 'a' && *s <= 'z') || isspace(*s)) {
            *new_s++ = *s;
        }
        s++;
    }
    *new_s = '\0';
}