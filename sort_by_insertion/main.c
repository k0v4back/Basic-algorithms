/*
 * Simple example insertion sort
 */

#include <stdio.h>

#define arr_length(arr) sizeof(arr)/sizeof(int)
 
void print_arr(int *arr, unsigned int len);

int main(void)
{
    int arr[] = {5, 2, 4, 6, 1, 3};

    for(unsigned i = 1; i < arr_length(arr); i++)
    {
        int key = i;

        while(i > 0 && arr[key - 1] > arr[key])
        {
            int buf = arr[key];
            arr[key] = arr[key - 1];
            arr[key - 1] = buf;
            key -= 1;
        }
        
    }
    
    print_arr(arr, arr_length(arr));

    return 0;
}

void print_arr(int * arr, unsigned len)
{
    for(unsigned i = 0; i < len; i++)
    {
        printf("%d, ", arr[i]);
    }
 
    puts("");
}
