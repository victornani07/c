#include <stdio.h>
#include <stdlib.h>

int countStudents(double **grades, int rows, int columns, int *indexes) {
    int counter = 0, max = 0, pos = 0;
    int tracking[100];

    for(int j = 0; j < columns; ++j) {
        int c = 0;
        for(int i = 0; i < rows; ++i)
            if(grades[i][j] < 5.00)
                ++c;
        if(c > max)
            max = c;
        tracking[pos++] = c;
    }

    for(int i = 0; i < pos; ++i)
        if(tracking[i] == max) 
            indexes[counter++] = i;

    return counter;    
}

int main(void) {
    double **grades;
    int rows, columns, *indexes;

    printf("Enter the number of students: ");
    scanf("%d", &rows);
    printf("Enter the number of subjects: ");
    scanf("%d", &columns);
    printf("\n");

    grades = (double**)malloc(rows * sizeof(double*));

    if(grades == NULL) {
        printf("The memory for rows of matrix were not properly allocated.\n");
        exit(1);
    }

    for(int i = 0; i < rows; ++i) {
        grades[i] = (double*)malloc(columns * sizeof(double));

        if(grades[i] == NULL) {
            printf("grades[%d] was not properly allocated.\n", i);
            exit(1);
        }
    }

    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j) {
            printf("grades[%d][%d] = ", i, j);
            scanf("%lf", &grades[i][j]);
        }
        printf("\n");
    }

    indexes = (int*)malloc(columns * sizeof(int));

    if(indexes == NULL) {
        printf("indexes was not properly allocated.\n");
        exit(1);
    }

    int counter = countStudents(grades, rows, columns, indexes);

    for(int i = 0; i < counter; ++i)
        printf("%d ", indexes[i]);
    
    for(int i = 0; i < rows; ++i)
        free(grades[i]);
    
    free(grades);
    free(indexes);
}