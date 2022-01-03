#include <stdio.h>

int ucp(unsigned int number) {
    while(number > 0) {
        int digit = number % 10;

        if(digit % 2 == 0)
            return digit;

        number /= 10;
    }

    return -1;
}

int main(void) {
    unsigned int number;

    printf("Enter the number: ");
    scanf("%u", &number);
    printf("\n");

    int lastDigit = ucp(number);

    printf("%d\n", lastDigit);
    printf("%d\n", ucp(number));
}