#include <stdio.h>

void my_toupper(char *);

int main() {
    char *woord = "snEEuwwITJE<3!!";  //werkt niet!!
    char s[50] = "snEEuwwITJE<3!!";   //werkt wel
    printf("\n%s", s);
    my_toupper(s);
    printf("\n%s", s);

    return 0;
}

void my_toupper(char *s) {
    if (*s >= 'a' && *s <= 'z') {
        *s += -'a' + 'A';
    }
    s++;
    while (*s) {
        if (*s >= 'A' && *s <= 'Z') {
            *s += 'a' - 'A';
        }
        s++;
    }
}