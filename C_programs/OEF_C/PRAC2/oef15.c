#include <stdio.h>

void schuif_op(char rij[], int size);
void print_array(const char rij[], int size);

int main() {
    char rij[] = {'s', 'a', 'p', 'a', 'p', 'p', 'e', 'l'};
    int size = sizeof(rij) / sizeof(char);

    print_array(rij, size);
    schuif_op(rij, size);
    print_array(rij, size);
    schuif_op(rij, size);
    print_array(rij, size);
    schuif_op(rij, size);
    print_array(rij, size);

    return 0;
}

void schuif_op(char rij[], int size) {
    char voorraan = rij[0];
    int i;
    for (i = 0; i < size; i++) {
        rij[i] = rij[i + 1];
    }
    rij[size - 1] = voorraan;
}

void print_array(const char rij[], int size) {
    printf("\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("%c", rij[i]);
    }
}
