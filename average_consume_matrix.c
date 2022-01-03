#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100

void readData(int consumers[MAX_ROWS][MAX_COLUMNS], int m, int n) {
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("consumers[%d][%d] = ", i, j);
            scanf("%d", &consumers[i][j]);
        }
        
        printf("\n");
    }

    printf("\n");
}

void printData(int consumers[MAX_ROWS][MAX_COLUMNS], int m, int n) {
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) 
            printf("%d ", consumers[i][j]);
        printf("\n");
    }

    printf("\n");
}

void countUsers(int consumers[MAX_ROWS][MAX_COLUMNS], int m, int n, double average[], int *counter) {
    for(int j = 0; j < n; ++j) {
        int count = 0, totalEnergy = 0;
        for(int i = 0; i < m; ++i)
            if(consumers[i][j] != 0) {
                ++count;
                totalEnergy += consumers[i][j];
            }
        if(count != 0)
            average[*counter] = totalEnergy / count;
        else
            average[*counter] = 0;
        ++*counter;
    }
}

int main(void) {
    int consumers[MAX_ROWS][MAX_COLUMNS];
    double average[MAX_ROWS];
    int m, n, counter = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of column: ");
    scanf("%d", &n);
    printf("\n");

    readData(consumers, m, n);
    printData(consumers, m, n);
    countUsers(consumers, m, n, average, &counter);

    for(int i = 0; i < counter; ++i)
        printf("%.1lf ", average[i]);
} 