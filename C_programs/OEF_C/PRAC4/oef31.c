#include <stdio.h>

void schrijf_cstring(const char *const *);
void schrijf_int(const int *);
void schrijf_double(const double *);
void schrijf_array(const void *t, int aantal, int grootte, char tussenteken, void (*schrijf)(const void *));

int main() {
    char *namen[] = {"Evi", "Jaro", "Timen", "Youri", "Ashaf", "Jennifer"};
    int leeftijden[] = {21, 30, 18, 14, 22, 19};
    double scores[] = {0.5, 1.6, 8.2, -2.4};
    /*
      schrijf_int(leeftijden);
      printf("\n");
      schrijf_double(scores);
      printf("\n");
      schrijf_cstring((const char *const *)namen);
      printf("\n");
  */
    printf("aantal namen : %d", sizeof(namen) / sizeof(char *));
    printf("\n");
    schrijf_array(leeftijden, 6, sizeof(int), ',',
                  (void (*)(const void *))schrijf_int);
    printf("\n");
    schrijf_array(scores, 4, sizeof(double), '~',
                  (void (*)(const void *))schrijf_double);
    printf("\n");
    schrijf_array(namen, 6, sizeof(char *), ';',
                  (void (*)(const void *))schrijf_cstring);

    return 0;
}

void schrijf_cstring(const char *const *s) {
    printf("%s", *s);
}
void schrijf_int(const int *s) {
    printf("%d", *s);
}

void schrijf_double(const double *s) {
    printf("%.1lf", *s);
}

void schrijf_array(const void *t, int aantal, int grootte, char tussenteken, void (*schrijf)(const void *)) {
    /* altijd eerst casten naar een char array!!!! */
    const char *char_array = (const char *)t;
    int i = 0;
    for (; i < aantal - 1; i++) {
        schrijf(char_array);
        char_array += grootte; //pointer verzetten
        printf("%c", tussenteken);
    }
    schrijf(char_array);
}
