#include <stdio.h>

#define MAX_CAPACITY 10

int isMountain(int number) {
    int digits[10], max = -1, indexMax = 0;
    int countDigits = 0;

    while(number > 0) {
        digits[countDigits] = number % 10;

        if(digits[countDigits] > max) {
            max = digits[countDigits];
            indexMax = countDigits;
        }

        number /= 10;
        ++countDigits;
    }

    if(indexMax == 0 || indexMax == countDigits - 1)
        return 0;

    for(int i = 0; i < indexMax; ++i)
        if(digits[i] > digits[i + 1])
            return 0;

    for(int i = indexMax; i < countDigits - 1; ++i)
        if(digits[i] < digits[i + 1])
            return 0;

    return 1;
}

int main(void) {
    int nums[MAX_CAPACITY];
    int n;

    printf("Enter the amount of numbers: ");
    scanf("%d", &n);
    printf("\n");

    for(int i = 0; i < n; ++i) {
        printf("nums[%d] = ", i);
        scanf("%d", &nums[i]);
    }

    printf("\n");

    for(int i = 0; i < n; ++i) 
        printf("%d\n", isMountain(nums[i]));
    
}