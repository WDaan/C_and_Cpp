#include <stdio.h>

int main() {
    int i = 7, j;
    double d;
    int *ip, *jp, *tp;
    double *dp;
    const int *p1;
    int *const p2 = &i;
    int t[25] = {10, 20, 30, 40, 50, 60};
    /* 1*/
    i = j;  //zinloos
    /* 2*/
    jp = &i;  //ok =>(jp wijst naar i)
    /* 3*/
    j = *jp;  //ok => j = 7
    /* 4*/
    *ip = i;  //FOUT   (want ip wijst nog naar niks)
    /* 5*/
    ip = jp;  //ok => (ip wijst naar i)
    /* 6*/
    &i = ip;  //FOUT
    /* 7*/
    (*ip)++;  //ok => (i = 8)
    /* 8*/
    *ip *= i;  //ok => (i = 64)
    /* 9*/
    ip++;  //zinloos
    /*10*/
    tp = t + 2;  //ok => (tp wijst naar t[2])
    /*11*/
    j = &t[5] - tp;  //ok => ( j = 3)
    /*12*/
    t++;  //FOUT
    /*13*/
    (*t)++;  //ok => (t[0] = 11)
    /*14*/
    *tp--;  //niet ok => (tp wijst naar t[1])
    /*15*/
    j = (*tp)++;  // ok => (j = 20, t[1] = 21)
    /*16*/
    i = *tp++;  // ok => (i = 21, tp wijst naar t[2])
    /*17*/
    p1 = ip;  // ok
    /*18*/
    jp = p1;  //FOUT
    /*19*/
    (*p1)--;  //FOUT  (const int pointer => mag waarde niet aanpassen)
    /*20*/
    dp = &i;  //FOUT (pointer naar double kan niet naar int wijzen)
    /*21*/
    dp = ip;  //FOUT (pointer naar double kan niet gelijk zijn aan pointer naar int)
    /*22*/
    jp = p2;
    /*23*/
    p2 = p1;
    /*24*/
    *p2 += i;
    return 0;
}