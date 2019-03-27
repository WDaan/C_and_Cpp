#include <stdio.h>

void schrijf_even_posities(const char t[], int size);

int main() {
    char letters[] = {'p', 'o', 'r', 'e', 'o', 'i', 'f', 'o', 'i', 'e', 'c', 'i', 'i', ':', 'a', '-', 't', '('};

    int grootte = sizeof(letters) / sizeof(char);

    printf("De grootte is : %d \n", grootte);

    /* even letters uitprinten */
    int i;
    for (i = 0; i < grootte; i += 2) {
        printf("%c", letters[i]);
    }

    /* --- met procedure --- */
    schrijf_even_posities(letters, grootte);

    return 0;
}

void schrijf_even_posities(const char t[], int size) {
    printf("\n");
    int i;
    for (i = 0; i < size - 1; i += 2) {
        printf("%c", t[i]);
    }
}
