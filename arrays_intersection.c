#include <stdio.h>

#define MAX_CAPACITY 1000

int main(void) {
    int x[MAX_CAPACITY], y[MAX_CAPACITY];
    int m, n;

    printf("m = ");
    scanf("%d", &m);
    printf("\n");

    for(int i = 0; i < m; ++i) {
        printf("x[%d] = ", i);
        scanf("%d", &x[i]);
    }

    printf("\n");

    printf("n = ");
    scanf("%d", &n);
    printf("\n");

    for(int i = 0; i < n; ++i) {
        printf("y[%d] = ", i);
        scanf("%d", &y[i]);
    }

    printf("\n");

    for(int i = 0; i < n; ++i) {
        int found = 0;
        for(int j = 0; j < m; ++j)
            if(y[i] == x[j]) {
                printf("1 ");
                found = 1;
                break;
            }
        if(found == 0) 
            printf("0 ");
    }
}