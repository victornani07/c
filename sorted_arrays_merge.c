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

    int i = 0, j = 0;

    while(i < m || j < n) {
        if(array1[i] <= array2[j]) 
            array3[pos++] = array1[i++];
        else if(array1[i] > array2[j])
            array3[pos++] = array2[j++];
        if(i == m) {
            for(int k = j; k < n; ++k)
                array3[pos++] = array2[k];
            break;
        } else if(j == n) {
            for(int k = i; k < m; ++k)
                array3[pos++] = array1[k];
            break;
        }
    }

    for(i = 0; i < pos; ++i)
        printf("%d ", array3[i]);
}