#include <stdio.h>
#include <stdlib.h>

int contains(int *a, int linesNumber, int idx) {
    for(int i = 0; i < linesNumber; ++i)
        if(a[i] == idx)
            return 1;

    return 0;
}

int **deleteMatrixLines(int **sells, int rows, int columns, int *linesToDelete, int *linesNumber) {
    int resultLines = rows - *linesNumber;

    int **newSells = (int**)malloc(resultLines * sizeof(int*));

    if(newSells == NULL) {
        printf("newSells was not properly allocated.\n");
        exit(1);
    }

    for(int i = 0; i < resultLines; ++i) {
        newSells[i] = (int*)malloc(columns * sizeof(int));

        if(newSells[i] == NULL) {
            printf("newSells[%d] was not properly allocated.\n", i);
            exit(1);
        }
    }

    int k = 0;

    for(int i = 0; i < rows; ++i)
        if(contains(linesToDelete, *linesNumber, i) == 0) {
            for(int j = 0; j < columns; ++j) 
                newSells[k][j] = sells[i][j];
            ++k;
        }
    
    return newSells;
}

int main(void) {
    int **sells;
    int *linesToDelete;
    int rows, columns, linesNumber;

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

    printf("\n");

    printf("Enter the number of lines you want to delete: ");
    scanf("%d", &linesNumber);
    printf("\n");

    linesToDelete = (int*)malloc(linesNumber * sizeof(int));

    if(linesToDelete == NULL) {
        printf("The array linesToDelete was not properely allocated.\n");
        exit(1);
    }

    for(int i = 0; i < linesNumber; ++i) {
        printf("linesToDelete[%d] = ", i);
        scanf("%d", &linesToDelete[i]);
    }

    printf("\n");

    int size = rows - linesNumber;
    int **newSells = deleteMatrixLines(sells, rows, columns, linesToDelete, &linesNumber);

    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < columns; ++j)
            printf("%d ", newSells[i][j]);
        printf("\n");
    }

    for(int i = 0; i < rows; ++i)
        free(sells[i]);

    free(sells);
    free(linesToDelete);
}