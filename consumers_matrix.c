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

int countUsers(int consumers[MAX_ROWS][MAX_COLUMNS], int m, int n, int products[], int *counter) {
    for(int i = 0; i < m; ++i) {
        int c = 1;
        for(int j = 0; j < n - 1; ++j)
            if(consumers[i][j] > consumers[i][j + 1])
                ++c;
        if(c == n) {
            products[*counter] = i;
            ++*counter;
        }
    }
}

int main(void) {
    int consumers[MAX_ROWS][MAX_COLUMNS];
    int products[MAX_ROWS];
    int m, n, counter = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of column: ");
    scanf("%d", &n);
    printf("\n");

    readData(consumers, m, n);
    printData(consumers, m, n);
    countUsers(consumers, m, n, products, &counter);

    printf("Number of users with descendent consume: %d\n", counter);

    for(int i = 0; i < counter; ++i)
        printf("%d ", products[i]);
} 