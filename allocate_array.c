#include <stdio.h>
#include <stdlib.h>

int* allocateMemory1(int *size) {
    printf("Enter the size of the array: ");
    scanf("%d", size);
    printf("\n");

    int* a = (int*)malloc(*size * sizeof(int));

    if(a == NULL) {
        printf("The memory was not allocated properly.\n");
        exit(1);
    }

    for(int i = 0; i < *size; ++i) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    return a;
}

void allocateMemory2(int **a, int *size) {
    printf("Enter the size of the array: ");
    scanf("%d", size);
    printf("\n");

    *a = (int*)malloc(*size * sizeof(int));

    if(*a == NULL) {
        printf("The memory was not allocated properly.\n");
        exit(1);
    }

    for(int i = 0; i < *size; ++i) {
        printf("a[%d] = ", i);
        scanf("%d", &(*a)[i]);
    }
}

int main(void) {
    int size;
    int *a;

    allocateMemory2(&a, &size);
    printf("\n");

    for(int i = 0; i < size; ++i)
        printf("%d ", a[i]);
}