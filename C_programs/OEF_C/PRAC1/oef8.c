#include <stdio.h>

int cijfersom(int a);
int cijfersom_rec(int b);

int main() {
    int i;
    i = 12345;
    int antwd;
    antwd = cijfersom(i);
    printf("\n De cijfersom is : %d", antwd);

    //rec_functie uitvoeren
    int antwd2;
    antwd2 = cijfersom_rec(i);
    printf("\n De cijfersom_rec is : %d", antwd2);

    return 0;
}

int cijfersom(int a) {
    int sum = 0;
    while (a > 0) {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}
/* -----uitleg----
stel getal 12
remainder door 10 = 2
=> sum = 2;
12/10 = 1
remainder door 10 = 1
sum += 1  => 3
1/10 = 0
einde while loop
*/

int cijfersom_rec(int b) {
    if (b < 10) return b;
    return b % 10 + cijfersom_rec(b / 10);
}