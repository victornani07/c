#include <stdio.h>

#define MAX_CAPACITY 100000

int main(void) {
    int nums[MAX_CAPACITY];
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("\n");

    for(int i = 0; i < n; ++i) {
        printf("nums[%d] = ", i);
        scanf("%d", &nums[i]);
    }

    printf("\n");

    for(int i = 0; i < n - 1; ++i)
        for(int j = 0; j < n - 1 - i; ++j)
            if(nums[j] > nums[j + 1]) {
                int temp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = temp;
            }
    
    int counter = 1, found = 0;

    for(int i = 0; i < n - 1; ++i) {
        if(nums[i] == nums[i + 1]) 
            ++counter;
        else {
            if(counter > n / 2) {
                printf("DA %d", nums[i]);
                found = 1;
                break;
            }
            counter = 1;
        }
    }
    
    if(found == 0)
        if(counter > n / 2) 
            printf("DA %d", nums[n - 1]);
        else
            printf("NU");
}