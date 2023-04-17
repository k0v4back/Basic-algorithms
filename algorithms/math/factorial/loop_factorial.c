#include <stdio.h>

int loop_factorial(int num);

int main(void)
{
    int num;

    puts("Input number: ");
    scanf("%d", &num);

    printf("loop_factorial(%d)=%d\n", num, loop_factorial(num));
}

int loop_factorial(int num)
{
    int result = 1;
    int i;
    
    if (num > 0) {
        for (i = 0; i < num; i++)
            result *= (num - i);
    } else if (num < 0) {
        for (i = 0; i > num; i--)
            result *= (num - i);
    }

    return result;
}
