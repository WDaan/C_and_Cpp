#include <stdio.h>
#include <string.h>

int main() {
    printf("%d\n", strlen("test")); //4
    printf("%d\n", strlen("test\n")); //5
    printf("%d\n", strlen("test\0"));//4


    /*de \n wordt wel meegeteld bij strlen*/
    /*de 0 wordt niet meegeteld bij strlen*/

    printf("%d\n", strcmp("appel", "appel")); //0
    printf("%d\n", strcmp("appel\n", "appel")); //1
    printf("%d\n", strcmp("appel", "appelmoes"));//-1

    char buf[20];
    printf("Woord : ");
    scanf("%s", buf);
     printf("%d\n", strlen(buf));

    return 0;
}