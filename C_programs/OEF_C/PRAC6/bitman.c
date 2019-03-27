#include <stdio.h>
typedef unsigned int uint;

int bit_i(uint x, int i) { return (x >> i) & 1; }

void schrijf(uint x, int lengte) {
    int i;
    int viervoud = lengte / 4 * 4;
    for (i = lengte - 1; i >= viervoud; i--) {
        printf("%u", bit_i(x, i));
    }
    for (i = viervoud - 1; i >= 0; i -= 4) {
        printf(" ");
        int k;
        for (k = 0; k < 4; k++) {
            printf("%u", bit_i(x, i - k));
        }
    }
    printf("        %u\n", x);
}

uint eenbit(int i) { return 1 << i; }

int aantal_eenbits(uint x) {
    int counter = 0;
    while (x) {
        counter += (x & 1);  //laatste bit optellen
        x >>= 1;             //getal met 1 bit naar rechts opschuiven, dus meest rechtse wegdoen
    }
    return counter;
}

uint bit_i_aangezet(uint x, int i) { return x | (1 << i); }
uint alle_bits_omgedraaid(uint x) { return ~x; }
uint bit_i_uitgezet(uint x, int i) { return x & ~(1 << i); }
uint bit_i_gewisseld(uint x, int i) { return x ^ (1 << i); }
int zijn_gelijk(uint x, uint y) { return x ^ y; }
int is_even(uint x) { return 1 & ~(x & 1); }
/*
wat test de code "n&(n-1)==0" ?
=> n en n-1 hebben nergens beide een bit gelijk aan 1
=> gaat na of n een macht is van 2
*/
uint product(int a, int b) {
    int res = 0;
    while (a > 0) {
        if (a & 1 == 1) {
            res += b;
        }
        b <<= 1;
        a >>= 1;
    }
    return res;
}

int main() {
    uint k = 49;
    int tel;
    schrijf(k, 16);
    tel = aantal_eenbits(k);
    k = bit_i_uitgezet(k, 5);
    schrijf(k, 16);
    k = bit_i_aangezet(k, 6);
    schrijf(k, 16);
    schrijf(eenbit(6), 16);
    schrijf(k ^ k, 16);
    k = product(5, 8);
    printf("        %d = 40", k);
    return 0;
}