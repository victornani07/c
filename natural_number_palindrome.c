#include <stdio.h>

#define MAX_CAPACITY 1000

int main(void) {
    int nums[MAX_CAPACITY];
    int n, isPalindrome = 1;

    printf("n = ");
    scanf("%d", &n);
    printf("\n");

    for(int i = 0; i < n; ++i) {
        printf("nums[%d] = ", i);
        scanf("%d", &nums[i]);
    }

    printf("\n");

    int left = 0, right = n - 1;

    while(left < right)
        if(nums[left] == nums[right]) {
            ++left;
            --right;
        } else {
            isPalindrome = 0;
            break;
        }

    printf("Numarul: ");

    for(int i = 0; i < n; ++i)
        printf("%d", nums[i]);

    printf("\n");

    if(isPalindrome == 1)
        printf("DA");
    else 
        printf("NU");
}