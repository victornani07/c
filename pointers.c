#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a = 5;

    printf("Value of a: %d\n", a);
    printf("Address of a: %p\n\n", &a);

    int *p = &a;
    *p = 12;

    printf("Value of the block p points: %d\n", *p);
    printf("Address of p: %p\n", &p);
    printf("The address to which p points: %p\n\n", p);

    printf("Value of a: %d\n", a);
}