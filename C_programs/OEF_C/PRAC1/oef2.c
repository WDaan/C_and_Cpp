#include <stdio.h>

int main()
{
    int i;
    for (i = 0; i < 65; i++)
    {
        printf("%5o  %5d  %-5x \n", i, i, i); //octal, decimal, hexadecimal
    }

    return 0;
}