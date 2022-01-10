#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

void integralistStudents(double**grades, int m, int n, int *students, int *size) {
    for(int i = 0; i < m; ++i) {
        int counter = 0;

        for(int j = 0; j < n; ++j)
            if(grades[i][j] >= 5.00)
                ++counter;

        if(counter == n)
            students[(*size)++] = i;
    }
}

int main(void) {
    double **grades;
    int *students;
    int m, n;

    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);
    printf("\n");

    grades = (double**)calloc(m, sizeof(double));

    if(grades == NULL) {
        printf("The memory was not allocated properly.\n");
        exit(1);
    }

    for(int i = 0; i < m; ++i) {
        grades[i] = (double*)calloc(n, sizeof(double));

        if(grades[i] == NULL) {
            printf("The memory was not allocated properly.\n");
            exit(1);
        }
    }

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("grades[%d][%d] = ", i, j);
            scanf("%lf", &grades[i][j]);
        }

        printf("\n");
    }

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j)
            printf("%.2lf ", grades[i][j]);
        printf("\n");
    }

    printf("\n");

    students = (int*)calloc(m, sizeof(int));

    if(students == NULL) {
        printf("The memory for students was not allocated properly.\n");
        exit(1);
    }

    int counter = 0;

    integralistStudents(grades, m, n, students, &counter);

    printf("The number of integralist students: %d\n", counter);

    for(int i = 0; i < counter; ++i)
        printf("%d ", students[i]);
}