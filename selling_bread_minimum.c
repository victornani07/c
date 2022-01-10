#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

int **getMinimumPositions(int **sells, int m, int n, int *min, int *counter) {
    int **minimumPositions = (int**)calloc(m * n, sizeof(int));

    if(minimumPositions == NULL) {
        printf("The memory for minimumPositions was not allocated properly.\n");
        exit(1);
    }

    for(int i = 0; i < m * n; ++i) {
        minimumPositions[i] = (int*)calloc(2, sizeof(int));

        if(minimumPositions[i] == NULL) {
            printf("The memory for minimumPositions[%d] was not allocated properly.\n", i);
            exit(1);
        }
    }

    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            if(sells[i][j] < *min) *min = sells[i][j];

    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            if(sells[i][j] == *min) {
                minimumPositions[*counter][0] = i;
                minimumPositions[(*counter)++][1] = j;
            }

    return minimumPositions;
}

int main(void) {
    int **sells;
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

    int min = sells[0][0], counter = 0;

    int **minimumPositions = getMinimumPositions(sells, m, n, &min, &counter);

    printf("The number of minimum elements: %d\n", counter);

    for(int i = 0; i < counter; ++i)
        printf("%d %d\n", minimumPositions[i][0], minimumPositions[i][1]);
}