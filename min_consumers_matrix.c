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

int countUsers(int consumers[MAX_ROWS][MAX_COLUMNS], int m, int n, int days[]) {
    int quantities[MAX_ROWS];
    int pos = 0, min = -1, counter = 0;

    for(int j = 0; j < n; ++j) {
        int quantity = 0;
        for(int i = 0; i < m; ++i)
            quantity += consumers[i][j];
        
        if(min == -1)
            min = quantity;
        else {
            if(quantity < min)
                min = quantity;
        }

        quantities[pos++] = quantity;
    }   

    for(int i = 0; i < pos; ++i) 
        if(quantities[i] == min) 
            days[counter++] = i;
        
    return counter;
}

int main(void) {
    int consumers[MAX_ROWS][MAX_COLUMNS];
    int days[MAX_ROWS];
    int m, n;

    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of column: ");
    scanf("%d", &n);
    printf("\n");

    readData(consumers, m, n);
    printData(consumers, m, n);
    int counter = countUsers(consumers, m, n, days);

    printf("Number of users with minimum consume: %d\n", counter);

    for(int i = 0; i < counter; ++i)
        printf("%d ", days[i]);
} 