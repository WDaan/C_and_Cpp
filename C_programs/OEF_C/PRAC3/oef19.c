#include <stdio.h>
int main() {
    int t[6] = {0, 10, 20, 30, 40, 50};
    int *pt[3];
    int i;
    for (i = 0; i < 3; i++) {  // grootte vervangen door sizeof(pt)/sizeof(int*)
        pt[i] = &t[2 * i];
    }
    pt[1]++;
    pt[2] = pt[1];
    *pt[1] += 1;
    *pt[2] *= 2;
    int **ppt = &pt[0];
    (*ppt)++;
    **ppt += 1;
    for (i = 0; i < 6; i++) {  // 6 vervangen door sizeof(t)/sizeof(int)
        printf("%d ", t[i]);
    }
    printf("\n");
    for (i = 0; i < 3; i++) {  // grootte vervangen door sizeof(pt)/sizeof(int*)
        printf("%d ", *pt[i]);
    }
    printf("\n");
    return 0;
}