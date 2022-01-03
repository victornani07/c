#include <stdio.h>
#include <stdlib.h>

void readData(int a[10][10], int m, int n) {
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
        
        printf("\n");
    }

    printf("\n");
}

void printData(int a[10][10], int m, int n) {
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("\n");
}

int multiply(int a[10][10], int m1, int n1,
              int b[10][10], int m2, int n2,
              int c[10][10], int *m3, int *n3) {
    if(n1 != m2)
        return 1; 

    *m3 = m1;
    *n3 = n2;   

    int pos1 = 0, pos2 = 0;

    for(int i = 0; i < m1; ++i) {
        int j = 0;
        for(int j = 0; j < n2; ++j) {
            int element = 0;
            for(int x = 0, y = 0; x < n1, y < m2; ++x, ++y) 
                element += (a[i][x] * b[y][j]);
            c[pos1][pos2] = element;
            ++pos2;
        }
        pos2 = 0;
        ++pos1;
    }         

    return 0;
}

int main(void) {
    int a[10][10], b[10][10], c[10][10];
    int m1, n1, m2, n2, m3, n3;

    printf("Enter the number of rows for a matrix: ");
    scanf("%d", &m1);
    printf("Enter the number of columns for a matrix: ");
    scanf("%d", &n1);
    printf("Enter the number of rows for b matrix: ");
    scanf("%d", &m2);
    printf("Enter the number of columns for b matrix: ");
    scanf("%d", &n2);
    printf("\n");


    readData(a, m1, n1);
    readData(b, m2, n2);
    multiply(a, m1, n1, b, m2, n2, c, &m3, &n3);
    printData(c, m3, n3);
}