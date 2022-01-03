#include <stdio.h>

#define MAX_CAPACITY_1 50
#define MAX_CAPACITY_2 100

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

    printf("\n");

    for(int i = 0; i < m; ++i) 
        array3[pos++] = array1[i];

    for(int i = 0; i < n; ++i)
        array3[pos++] = array2[i];

    for(int i = 0; i < pos - 1; ++i)
        for(int j = 0; j < pos - 1 - i; ++j)
            if(array3[j] > array3[j + 1]) {
                int temp = array3[j + 1];
                array3[j + 1] = array3[j];
                array3[j] = temp;
            }

    for(int i = 0; i < pos; ++i) 
        printf("%d ", array3[i]);
}