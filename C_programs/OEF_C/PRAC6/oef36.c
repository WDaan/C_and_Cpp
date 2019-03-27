#include <stdlib.h>

typedef struct knoop knoop;
struct knoop {
    int d;
    knoop* next;
};


int main() {
    knoop* l = 0;
    knoop* k = l;
    k = (knoop*)malloc(sizeof(knoop));
    return 0;
}