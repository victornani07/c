#include <stdio.h>
#include <stdlib.h>

int constantSells(int **sells, int m, int n, int *constantSellsProducts) {
    int size = 0;

    for(int j = 0; j < n; ++j) {
        int counter = 1;

        for(int i = 0; i < m - 1; ++i)
            if(sells[i][j] == sells[i + 1][j])
                ++counter;

        if(counter == m) 
            constantSellsProducts[size++] = j;
    }

    return size;
}

int main(void) {
    int **sells;
    int *constantSellsProducts;
    int m, n;

    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);
    printf("\n");

    sells = (int**)calloc(m, sizeof(int));

    if(sells == NULL) {
        printf("The memory was not allocated properly.\n");
        exit(1);
    }

    for(int i = 0; i < m; ++i) {
        sells[i] = (int*)calloc(n, sizeof(int));

        if(sells[i] == NULL) {
            printf("The memory was not allocated properly.\n");
            exit(1);
        }
    }

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("sells[%d][%d] = ", i, j);
            scanf("%d", &sells[i][j]);
        }

        printf("\n");
    }

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j)
            printf("%d ", sells[i][j]);
        printf("\n");
    }

    constantSellsProducts = (int*)calloc(m, sizeof(int));

    if(constantSellsProducts == NULL) {
        printf("The memory was not allocated properly.\n");
        exit(1);
    }

   int size = constantSells(sells, m, n, constantSellsProducts);

   printf("The number of products with constant sells: %d.\n", size);

   for(int i = 0; i < size; ++i)
        printf("%d ", constantSellsProducts[i]);
}