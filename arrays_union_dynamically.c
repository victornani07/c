#include <stdio.h>
#include <stdlib.h>

int exists(int *set, int *setSize, int number) {
    for(int i = 0; i < *setSize; ++i)
        if(set[i] == number)
            return 1;

    return 0;        
}

int *setUnion(int *set1, int *set2, int setSize1, int setSize2, int *setSize3) {
    int *set3 = (int*)calloc(setSize1 + setSize2, sizeof(int));

    if(set3 == NULL) {
        printf("The memory for set3 was not allocated properly.\n");
        exit(1);
    }

    *setSize3 = setSize1;

    for(int i = 0; i < setSize1; ++i)
        set3[i] = set1[i];

    for(int i = 0; i < setSize2; ++i)
        if(exists(set3, setSize3, set2[i]) == 0) {
            set3[*setSize3] = set2[i];
            ++(*setSize3);
        }

    printf("\n");
    
    return set3;
}

int main(void) {
    int *set1, *set2, *set3;
    int setSize1, setSize2, setSize3 = 0;

    printf("Enter the number of elements for the first set: ");
    scanf("%d", &setSize1);
    printf("\n");

    set1 = (int*)calloc(setSize1, sizeof(int));

    if(set1 == NULL) {
        printf("The memory for the first set was not allocated properly.\n");
        exit(1);
    }

    for(int i = 0; i < setSize1; ++i) {
        printf("set1[%d] = ", i);
        scanf("%d", &set1[i]);
    }

    printf("\n");

    printf("Enter the number of elements for the second set: ");
    scanf("%d", &setSize2);
    printf("\n");

    set2 = (int*)calloc(setSize2, sizeof(int));

    if(set2 == NULL) {
        printf("The memory for the second set was not allcoated properly.\n");
        exit(1);
    }

    for(int i = 0; i < setSize2; ++i) {
        printf("set2[%d] = ", i);
        scanf("%d", &set2[i]);
    }

    printf("\n");

    set3 = setUnion(set1, set2, setSize1, setSize2, &setSize3);

    for(int i = 0; i < setSize3; ++i)
        printf("%d ", set3[i]);

    free(set1);
    free(set2);
    free(set3);
}