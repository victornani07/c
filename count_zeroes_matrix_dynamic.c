#include <stdio.h>
#include <stdlib.h>

void countZeroes(int **sells, int rows, int columns, int ***indexes, int *counter) {
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < columns; ++j)
            if(sells[i][j] == 0)
                ++(*counter);

    *indexes = (int**)malloc(*counter * sizeof(int*));

    if(*indexes == NULL) {
        printf("indexes was not allocated properly.\n");
        exit(1);
    }    

    for(int i = 0; i < *counter; ++i) {
        (*indexes)[i] = (int*)malloc(2 * sizeof(int));

         if((*indexes)[i] == NULL) {
             printf("indexes[%d]  was not allocated properly.\n");
             exit(1);
         }
    }

    int pos = 0;

    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < columns; ++j)
            if(sells[i][j] == 0) {
                (*indexes)[pos][0] = i;
                (*indexes)[pos++][1] = j;
            }
}

int main(void) { 
    int **sells, **indexes;
    int rows, columns, counter = 0;

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

    countZeroes(sells, rows, columns, &indexes, &counter);

    for(int i = 0; i < counter; ++i) {
        for(int j = 0; j < 2; ++j)
            printf("%d ", indexes[i][j]);
        printf("\n");
   }

    for(int i = 0; i < rows; ++i) 
        free(sells[i]);
    

    for(int i = 0; i < counter; ++i)
        free(indexes[i]);
    
    free(indexes);
    free(sells);
}