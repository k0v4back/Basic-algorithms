/*
 * Simple example insertion sort
 */

#include <stdio.h>

#define arr_length(arr) sizeof(arr)/sizeof(int)
 
void insertion_sort(int *arr, unsigned int len);
void print_arr(int *arr, unsigned int len);

int main(void)
{
    int arr[] = {5, 2, 4, 6, 1, 3};

    insertion_sort(arr, arr_length(arr));
    print_arr(arr, arr_length(arr));

    return 0;
}

void insertion_sort(int *arr, unsigned int len)
{
    for(unsigned i = 1; i < len; i++)
    {
        int key = i;
        while(key > 0 && arr[key - 1] > arr[key])
        {
            int buf = arr[key];
            arr[key] = arr[key - 1];
            arr[key - 1] = buf;
            key--;
        }
    }
}

void print_arr(int * arr, unsigned len)
{
    for(unsigned i = 0; i < len; i++)
    {
        printf("%d, ", arr[i]);
    }
 
    puts("");
}
