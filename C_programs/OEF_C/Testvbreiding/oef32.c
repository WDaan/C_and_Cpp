#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4

char *lees() {
    char buf[MAX + 1];
    char *s;
    printf("\nInput: ");
    fgets(buf, MAX + 1, stdin);
    if (buf[strlen(buf) - 1] == '\n') {
        buf[strlen(buf) - 1] = 0;
    } else {
        while (getchar() != '\n')
            ;
    }
    s = (char *)malloc(strlen(buf) + 1);
    strcpy(s, buf);
    return s;
}

int main() {
    char *s = lees();
    printf("%s", s);
    free(s);
    s = lees();
    printf("%s", s);
    free(s);
    return 0;
}