#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **matrix, int rows, int columns) {
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j) {
            printf("Enter element [%d, %d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void printMatrix(int **matrix, int rows, int columns) {
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    printf("\n");
}

void bubbleSort(int *array, int size) {
    for(int i = 0; i < size - 1; ++i)
        for(int j = 0; j < size - 1 - i; ++j)
            if(array[j] > array[j + 1]) {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
}

void bubbleSortColumns(int **matrix, int rows, int columns) {
    for(int k = 0; k < columns; ++k) 
        for(int i = 0; i < rows - 1; ++i)
            for(int j = 0; j < rows - 1 - i; ++j)
                if(matrix[j][k] > matrix[j + 1][k]) {
                    int temp = matrix[j + 1][k];
                    matrix[j + 1][k] = matrix[j][k];
                    matrix[j][k] = temp;
                }
}

int main(void) {
    int **matrix;
    int rows, columns;

    printf("rows = ");
    scanf("%d", &rows);
    printf("columns = ");
    scanf("%d", &columns);
    printf("\n");

    matrix = (int**)malloc(rows * sizeof(int*));

    if(matrix == NULL) {
        printf("matrix was not properly allocated.\n");
        exit(1);
    }

    for(int i = 0; i < rows; ++i) {
        matrix[i] = (int*)malloc(columns * sizeof(int));

        if(matrix[i] == NULL) {
            printf("matrix[%d] was not properly allocated.\n", i);
            exit(1);
        }
    }

    readMatrix(matrix, rows, columns);

    // for(int i = 0; i < rows; ++i)
    //     bubbleSort(matrix[i], columns);

    // bubbleSortColumns(matrix, rows, columns);

    printMatrix(matrix, rows, columns);
}