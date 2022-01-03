#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100

void readData(int calls[MAX_ROWS][MAX_COLUMNS], int m, int n) {
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("calls[%d][%d] = ", i, j);
            scanf("%d", &calls[i][j]);
        }
        
        printf("\n");
    }

    printf("\n");
}

void printData(int calls[MAX_ROWS][MAX_COLUMNS], int m, int n) {
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) 
            printf("%d ", calls[i][j]);
        printf("\n");
    }

    printf("\n");
}

void countUsers(int calls[MAX_ROWS][MAX_COLUMNS], int m, int n, int *counter) {
    for(int i = 0; i < m; ++i) {
        int c = 1;
        for(int j = 0; j < n - 1; ++j)
            if(calls[i][j] == calls[i][j + 1])
                ++c;
        if(c == n)
            ++*counter;
    }
}

int main(void) {
    int calls[MAX_ROWS][MAX_COLUMNS];
    int m, n, counter = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of column: ");
    scanf("%d", &n);
    printf("\n");

    readData(calls, m, n);
    printData(calls, m, n);
    countUsers(calls, m, n, &counter);

    printf("Number of users with constant calls: %d\n", counter);
}