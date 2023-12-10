#include <stdio.h>

#define ARR_LEN(x) (sizeof(x) / sizeof(x[0]))

void bubble_sort(int *input_arr, int arr_len);
void print_arr(int *input_arr, int arr_len);

int main(void)
{
    int input_arr[10] = {3, 4, 7, 3, 5, 0, 9, 6, 1, 8};

    printf("Befor sort: ");
    print_arr(input_arr, ARR_LEN(input_arr));

    printf("After bubble sort: ");
    bubble_sort(input_arr, ARR_LEN(input_arr));
    print_arr(input_arr, ARR_LEN(input_arr));
    
    return 0;
}

void bubble_sort(int *input_arr, int arr_len)
{
    int i, j;
    int temp;

    for (i = 0; i < arr_len - 1; i++) {
        for (j = 0; j < arr_len - i - 1; j++) {
            if (input_arr[j] > input_arr[j+1]) {
                temp = input_arr[j];
                input_arr[j] = input_arr[j+1];
                input_arr[j+1] = temp;
            }
        }
    }
}

void print_arr(int *input_arr, int arr_len)
{
    int i;

    for (i = 0; i < arr_len; i++)
        printf("%d ", input_arr[i]);

    printf("\n");
}
