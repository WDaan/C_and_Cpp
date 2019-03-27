#include <stdio.h>

int main() {
    int i;
    float x, sum, term;
    float som = 0;

    //waarde vragen
    printf("Enter a value for x (in radian) : ");
    scanf("%f", &x);

    //term en som gelijkstellen want x/1! = x
    term = x;
    sum = x;

    //loop to calculate sine
    for (i = 1; i < 10; i++) {
        term = (term * (-1) * x * x) / (2 * i * (2 * i + 1));
        sum += term;
    }

    printf("Value of sin(%f) =  %f", x, sum);

    return 0;
}

/* HELGA OPL

term = ... ;
som =  ....;

for (....){
    term = term...
    som += term;
}
*/
