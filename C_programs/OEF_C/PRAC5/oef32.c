#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 4

char* lees();

int main() {
    int i;
    for (i = 0; i < 5; i++) {
        char* tekst = lees();
        printf("Ik las in %s.\n", tekst);
        free(tekst);
    }
    return 0;
}

char* lees() {
    char* lijn;
    char s[MAX + 1]; /*voor nullkarakter*/
    fgets(s, MAX + 1, stdin);
    /* indien 4+1 karaktervelden voorzien , en ’ aap \n ’ ingelezen */
    if (s[strlen(s) - 1] == '\n') {
        s[strlen(s) - 1] = '\0';
        /* indien 4+1 karaktervelden voorzien , en ’ noot ’ ingelezen :
            alles ok ; niets doen of lege lus */
        /* indien 4+1 karaktervelden voorzien , en ’ appelmoes ’ ingelezen :
            ’appe\0 ’ bewaard ; ’ lmoes ’ moet nog weg*/
    } else {
        while (getchar() != '\n')
            ;
    }
    lijn = malloc(strlen(s) + 1);  // +1 voor het nullkarakter
    strcpy(lijn, s);

    return lijn;
}