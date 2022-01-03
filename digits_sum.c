#include <stdio.h>

void sumcif(unsigned int number, unsigned int *evenSum, unsigned int *oddSum) {
    while(number > 0) {
        int digit = number % 10;

        if(digit % 2 == 0)
            *evenSum += digit;
        else
            *oddSum += digit;

        number /= 10;
    }
}

int main(void) {
    unsigned int number, evenSum = 0, oddSum = 0;

    printf("Enter the number: ");
    scanf("%u", &number);
    printf("\n");
    
    sumcif(number, &evenSum, &oddSum);

    printf("Even sum: %d\n", evenSum);
    printf("Odd sum %d\n", oddSum);
}