#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* s;
    s = malloc(10 * sizeof(char));
    scanf("%s", s);
    int i = strlen(s);
    printf("%d", i);
    printf("\n%s", s);

    free(s);
}
