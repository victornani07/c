#include <stdio.h>

#define MAX_CAPACITY_1 100000
#define MAX_CAPACITY_2 200000

int main(void) {
    int array1[MAX_CAPACITY_1], array2[MAX_CAPACITY_1], array3[MAX_CAPACITY_2];
    int m, n, pos = 0;

    printf("Enter the length of the first array: ");
    scanf("%d", &m);
    printf("\n");

    for(int i = 0; i < m; ++i) {
        printf("array1[%d] = ", i);
        scanf("%d", &array1[i]);
    }

    printf("\n");

    printf("Enter the length of the second array: ");
    scanf("%d", &n);
    printf("\n");

    for(int i = 0; i < n; ++i) {
        printf("array2[%d] = ", i);
        scanf("%d", &array2[i]);
    }

    int i = 0, j = n - 1;

    while(i < m || j >= 0) {
        if(array1[i] <= array2[j]) {
            if(array1[i] % 2 == 0)
                array3[pos++] = array1[i];
            ++i;
        }
        else if(array1[i] > array2[j]) {
            if(array2[j] % 2 == 0)
                array3[pos++] = array2[j];
            --j;
        }
        if(i == m) {
            for(int k = j; k >= 0; --k)
                if(array2[k] % 2 == 0)
                    array3[pos++] = array2[k];
            break;
        } else if(j == -1) {
            for(int k = i; k < m; ++k)
                if(array1[k] % 2 == 0)
                    array3[pos++] = array1[k];
            break;
        }
    }

    for(i = 0; i < pos; ++i)
        printf("%d ", array3[i]);
}