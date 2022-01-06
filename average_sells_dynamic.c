#include <stdio.h>
#include <stdlib.h>

#define AVERAGE_VALUE 5000

int countAverageCompanies(int **sells, int rows, int columns, int *averageCompanies) {
    int size = 0;

    for(int i = 0; i < rows; ++i) {
        int sum = 0;

        for(int j = 0; j < columns; ++j)
            sum += sells[i][j];
        
        double average = sum / columns;
        
        if(average > AVERAGE_VALUE) 
            averageCompanies[size++] = i;
    }

    return size;
}

int main(void) {
    int **sells;
    int *averageCompanies;
    int rows, columns;

    printf("Enter the number of companies: ");
    scanf("%d", &rows);
    printf("Enter the number of products: ");
    scanf("%d", &columns);
    printf("\n");

    sells = (int**)malloc(rows * sizeof(int*));

    if(sells == NULL) {
        printf("The memory for rows of matrix were not properly allocated.\n");
        exit(1);
    }

    for(int i = 0; i < rows; ++i) {
        sells[i] = (int*)malloc(columns * sizeof(int));

        if(sells[i] == NULL) {
            printf("sells[%d] was not properly allocated.\n", i);
            exit(1);
        }
    }

    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j) {
            printf("sells[%d][%d] = ", i, j);
            scanf("%d", &sells[i][j]);
        }
        printf("\n");
    }

    averageCompanies = (int*)malloc(rows * sizeof(int));

    if(averageCompanies == NULL) {
        printf("averageCompanies was not allocated properly.\n");
        exit(1);
    }

    printf("\n");

    int size = countAverageCompanies(sells, rows, columns, averageCompanies);

    for(int i = 0; i < size; ++i)
        printf("%d ", averageCompanies[i]);

    printf("\n");

    free(averageCompanies);

    for(int i = 0; i < rows; ++i)
        free(sells[i]);

    free(sells);
}