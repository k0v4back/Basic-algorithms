#include <stdio.h>

#define ARR_LEN(x) (sizeof(x) / sizeof(x[0]))

void my_quick_sort(int *arr, int left, int right);
void print_arr(int *input_arr, int arr_len);

int main(void)
{
    int arr[7] = {8, 3, 4, -1, 4, -3, 0};

    printf("Befor sort: ");
    print_arr(arr, ARR_LEN(arr));

    printf("After sort: ");
    my_quick_sort(arr, 0, (ARR_LEN(arr) - 1));
    print_arr(arr, ARR_LEN(arr));

    return 0;
}

void my_quick_sort(int *arr, int left, int right)
{
    int mid;    /* Middle element */
    int i, j;   /* Array bounds */
    int tmp;    /* Temporary variable */

    if (left > right)
        return;

    mid = arr[(left + right) / 2];
    i = left;
    j = right;

    while (i <= j) {
        while (arr[i] < mid) 
            i++;
        while (arr[j] > mid) 
            j--;

        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            i++;
            j--;
        }
    }

    my_quick_sort(arr, left, j);
    my_quick_sort(arr, i, right);
}

void print_arr(int *input_arr, int arr_len)
{
    int i;

    for (i = 0; i < arr_len; i++)
        printf("%d ", input_arr[i]);

    printf("\n");
}
