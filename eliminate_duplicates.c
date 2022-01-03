#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100000

void readData(int array[], int n) {
    for(int i = 0; i < n; ++i) {
        printf("n[%d] = ", i);
        scanf("%d", &array[i]);
    }

    printf("\n");
}

void printData(int array[], int n) {
    for(int i = 0; i < n; ++i)
        printf("%d ", array[i]);

    printf("\n");
}

void removeDuplicates(int array[], int *n) {
    for(int i = 0; i < *n - 1; ++i)
        for(int j = i + 1; j < *n; ++j)
            if(array[j] == array[i]) {
                for(int k = j; k < *n - 1; ++k)
                    array[k] = array[k + 1];
                --*n;
            }
}

int main(void) {
    int array[MAX_CAPACITY];
    int size;

    printf("Size of the array: ");
    scanf("%d", &size);
    printf("\n");

    readData(array, size);
    removeDuplicates(array, &size);
    printData(array, size);
}