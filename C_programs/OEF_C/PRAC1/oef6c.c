#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* seeden me time is een goed idee,
anders altijd zelfde 'random' sequentie */

int main()
{
    unsigned long long int fac = 1;
    int i, n;
    srand(time(NULL)); /* Laat je dit weg , dan genereert het programma bij elke run telkens hetzelfde getal. Probeer uit! */
    n = rand() % 19 + 2;
    for (i = 2; i <= n; i++)
    {
        fac *= i;
    }
    printf("%d! = %lld \n", n, fac);
    return 0;
}

/*
------ 5 random getallen genereren ---- 


srand ( time(NULL) );
    int i;
    for( i = 0 ; i < 5 ; i++ ) {
      printf("%d\n", rand() % 50);
   }


   */

/* ----- FAC ------
int fac(int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}
*/

/* computer kiest getal 
 #include <stdio.h> 
 #include <stdlib.h> 
 #include <time.h> 
 
 int main()
{
    unsigned long long int fac = 1;
    int i, n;
    srand(time(NULL)); // Laat je dit weg , dan genereert het programma bij elke run telkens hetzelfde getal. Probeer uit! 
    n = rand() % 19 + 2;
    for (i = 2; i <= n; i++)
    {
        fac *= i;
    }
    printf("%d! = %lld \n", n, fac);
    return 0;
}

*/