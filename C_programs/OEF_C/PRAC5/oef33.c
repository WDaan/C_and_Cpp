#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

char* lees() {
    char* lijn;
    char buf[MAX + 1];
    fgets(buf, MAX + 1, stdin);
    /* indien 4+1 karaktervelden voorzien , en ’ aap \n ’ ingelezen */
    if (buf[strlen(buf) - 1] == '\n') {
        buf[strlen(buf) - 1] = '\0';
        /* indien 4+1 karaktervelden voorzien , en ’ noot ’ ingelezen :
        alles ok ; niets doen of lege lus */
        /* indien 4+1 karaktervelden voorzien , en ’ appelmoes ’ ingelezen :
        ’ appe \0 ’ bewaard ; ’ lmoes ’ moet nog weg*/
    } else {
        while (getchar() != '\n')
            ;
    }

    lijn = malloc((strlen(buf) + 1) * sizeof(char));
    strcpy(lijn, buf);
    return lijn;
}

char** lees_meerdere() {
    int i = 0;
    char** t;
    char* s = lees();
    char* buf[6];
    /*in buffer steken*/
    while (i < 5 && strcmp(s, "STOP") != 0) {
        buf[i] = s;
        i++;
        s = lees();
    }
    /* laatste toevoegen als het geen stop is*/
    if (i == 5 && strcmp(s, "STOP") != 0) {
        buf[i] = s;
        i++;
    }

    /* definitieve array aanmaken*/
    t = malloc((i + 1) * sizeof(char*)); /*voor nullpointer*/
    /* vullen */
    int a;
    for (a = 0; a < i; a++) {
        *(t + a) = buf[a];
    }
    *(t + i) = 0;
    return t;
}

void geef_vrij(char** s) {
    printf("\nVrijmaken : ");
    while (*s) {
        printf("x");
        free(*s);
        s++;
    }
}

int main() {
    char** lijnen = lees_meerdere();
    char** l = lijnen;
    int i = 0;
    while (*l) {
        printf("\nLijn %d : %s", i + 1, *l++);
    }
    geef_vrij(lijnen); /*elementen in array wissen */
    free(lijnen);      /* array zelf wissen */
    return 0;
}
