#include <stdio.h>

int recursive_factorial(int num, int result);

int main(void)
{
    int num;
    int result;

    puts("Input number: ");
    scanf("%d", &num);

    result = 1;
    printf("recursive_factorial(%d) = %d\n", 
            num, recursive_factorial(num, result));
}

int recursive_factorial(int num, int result)
{
    if (num > 0) {
        result *= num;
        num--;
        recursive_factorial(num, result);
    } else if (num < 0) {
        if ((num % 2) != 0)
            result *= (-1);
        result *= num;
        num++;
        recursive_factorial(num, result);
    } else {
        return result;
    }
}
