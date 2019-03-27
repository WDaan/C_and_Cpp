/*
#include <stdio.h>

int main()
{
    int i;
    for (i = 2; i < 20; i++)
    {
        long long getal = i;
        long long fac = getal;
        while (getal > 1)
        {
            getal--;
            fac *= getal;
        }

        printf("faculteit is : %ld \n", fac);
    }

    return 0;
}
*/
/* 

---- Gwn Faculteit berekenen ----

/*
int fac(int n) { 
    int res = 1, i;
    for (i=2 ; i<=n ; i++) 
        res *= i;
    return res; 
}
*/

/* versie 1 is correct tot 12 !  
#include <stdio.h> int main()
{
    long int fac = 1;
    int n = 30;
    int i;
    for (i = 2; i <= n; i++)
    {
        fac *= i;
        printf("%d! = %lld \n", i, fac);
    }
    return 0;
}

*/
/* versie 2 - met unsigned long long is het resultaat tot 20 ! */
#include <stdio.h>
int main() {
    unsigned long long int fac = 1;
    int n = 30;
    int i;
    for (i = 2; i <= n; i++) {
        fac *= i;
        printf("%d! = %lld \n", i, fac);
    }
    return 0;
}
