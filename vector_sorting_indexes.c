#include <stdio.h>

int main(void) {
    int n, pos = 0, numPrec = -100, indexPrec = -100;
    int numsUnsorted[100], numsSorted[100], numsIndexes[200];

    printf("Enter the length of the array: ");
    scanf("%d", &n);
    printf("\n");

    for(int i = 0; i < n; ++i) {
        printf("Enter number %d: ", i);
        scanf("%d", &numsUnsorted[i]);
        numsSorted[i] = numsUnsorted[i];
    }
    
    printf("\n");

    for(int i = 0; i < n - 1; ++i)
        for(int j = 0; j < n - 1 - i; ++j)
            if(numsSorted[j] > numsSorted[j + 1]) {
                int temp = numsSorted[j + 1];
                numsSorted[j + 1] = numsSorted[j];
                numsSorted[j] = temp;
            }

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(numsSorted[i] == numsUnsorted[j]) {
                numsIndexes[pos] = numsSorted[i];
                if(numsSorted[i] == numPrec) {
                    for(int k = j; k < n; ++k)
                        if(k > indexPrec && numsUnsorted[k] == numsSorted[i]) {
                            numsIndexes[pos + 1] = k;
                            indexPrec = k;
                            break;
                        }
                } else {
                    numsIndexes[pos + 1] = j;
                    indexPrec = j;
                }
                numPrec = numsSorted[i];
                pos += 2;
                break;
            }

    for(int i = 0; i < 2 * n; i += 2) 
        printf("%d %d\n", numsIndexes[i], numsIndexes[i + 1]);
}