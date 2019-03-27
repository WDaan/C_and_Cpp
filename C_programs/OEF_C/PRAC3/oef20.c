#include <stdio.h>

void wissel(int*, int*);

int main() {
    int x = 5, y = 10;
    printf("Eerst hebben we x=%d en y=%d.\n", x, y);
    wissel(&x, &y);
    printf("Na de wissel hebben we x=%d en y=%d.\n", x, y);
    return 0;
}

void wissel(int* px, int* py) {
    int hulp;
    printf(" Bij start van de wisselprocedure hebben we a=%d en b=%d.\n", *px, *py);
    hulp = *px;
    *px = *py;
    *py = hulp;
    printf(" Op het einde van de wisselprocedure hebben we a=%d en b=%d.\n", *px, *py);
}