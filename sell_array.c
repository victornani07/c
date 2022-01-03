#include <stdio.h>

#define MAX_CAPACITY 100000

void readData(double array[], int n) {
    for(int i = 0; i < n; ++i) {
        printf("n[%d] = ", i);
        scanf("%lf", &array[i]);
    }

    printf("\n");
}

void printData(double array[], int n) {
    for(int i = 0; i < n; ++i)
        printf("%.1lf ", array[i]);

    printf("\n");
}

double computeSales(double array[], int n) {
    double sum = 0;
    int counter = 0;

    for(int i = 0; i < n; ++i)
        if(array[i] != 0) {
            ++counter;
            sum += array[i];
        }

    return sum / counter;
}

int main(void) {
    double n[MAX_CAPACITY];
    int size;

    printf("Size of the array: ");
    scanf("%d", &size);
    printf("\n");

    readData(n, size);
    printData(n, size);

    printf("%lf\n", computeSales(n, size));
}