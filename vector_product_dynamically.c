#include <stdio.h>
#include <stdlib.h>

int *vectorProduct1(int *nums1, int *nums2, int nums1Size, int nums2Size, int *success) {
    if(nums1Size != nums2Size) {
        *success = 1;
        return NULL;
    }

    int *nums3 = (int*)malloc(nums1Size * sizeof(int));

    if(nums3 == NULL) {
        printf("The nums3 array was not allocated properly.\n");
        return NULL;
    }

    for(int i = 0; i < nums1Size; ++i)
        nums3[i] = nums1[i] * nums2[i];

    *success = 0;

    return nums3;
}

int main(void) {
    int *nums1, *nums2, *nums3;
    int nums1Size, nums2Size, success;

    printf("Enter the size of the first array: ");
    scanf("%d", &nums1Size);
    printf("\n");

    nums1 = (int*)malloc(nums1Size * sizeof(int));

    if(nums1 == NULL) {
        printf("The nums1 array was not allocated properly.\n");
        exit(1);
    }

    for(int i = 0; i < nums1Size; ++i) {
        printf("nums1[%d] = ", i);
        scanf("%d", &nums1[i]);
    }

    printf("\n");
    printf("Enter the size of the second array: ");
    scanf("%d", &nums2Size);
    printf("\n");

    nums2 = (int*)malloc(nums2Size * sizeof(int));

    if(nums2 == NULL) {
        printf("The nums2 array was not allocated properly.\n");
        exit(1);
    }

    for(int i = 0; i < nums2Size; ++i) {
        printf("nums2[%d] = ", i);
        scanf("%d", &nums2[i]);
    }

    printf("\n");

    nums3 = vectorProduct1(nums1, nums2, nums1Size, nums2Size, &success);
    free(nums1);
    free(nums2);

    if(success == 0) {
        if(nums3 == NULL)
            exit(1);
        else
            for(int i = 0; i < nums1Size; ++i)
                printf("%d ", nums3[i]);
    } else 
        printf("The sizes of the arrays are not equal.\n");

    printf("\n");

    free(nums3);
}