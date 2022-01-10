#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

void maxSells(int **sells, int m, int n, int *maxSellsCompanies, int *size) {
    int max = -1, k = 0;
    int averages[MAX_CAPACITY];

    for(int i = 0; i < m; ++i) {
        int sum = 0;

        for(int j = 0; j < n; ++j)
            sum += sells[i][j];

        double average = (double)sum / n;
        averages[k++] = average;
        
        if(average > max) max = average;
    }

    for(int i = 0; i < k; ++i)
        if(averages[i] == max)
            maxSellsCompanies[(*size)++] = i;
}

int main(void) {
    int **sells;
    int *maxSellsCompanies;
    int m, n, size = 0;

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

    maxSellsCompanies = (int*)calloc(m, sizeof(int));

    if(maxSellsCompanies == NULL) {
        printf("The memory was not allocated properly.\n");
        exit(1);
    }

    maxSells(sells, m, n, maxSellsCompanies, &size);
    printf("The number of companies with max sells: %d\n", size);

    for(int i = 0; i < size; ++i)
        printf("%d ", maxSellsCompanies[i]);
}