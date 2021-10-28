/*
 * Sort the array in ascending order
 */

#include <stdio.h>

#define arr_length(arr) sizeof(arr)/sizeof(int)

void sort_by_selection(int *arr, int len);
int min_el(int *arr, int start_index,  int len);
void print_arr(int *arr, int len);

int main(void)
{
    int nums[] = {5, 2, 4, 6, 1, 3};
    
    puts("\n---------BEFORE SORT---------\n");
    print_arr(nums, arr_length(nums));

    puts("\n---------AFTER SORT---------\n");
    sort_by_selection(nums, arr_length(nums));
    print_arr(nums, arr_length(nums));

    return 0;
}

void sort_by_selection(int *arr, int len)
{
    for(unsigned i = 0; i < len-1; i++)
    {
        int key = i;
        while(key < len)
        {
            int buff = arr[i];
            int index_min_el = min_el(arr, i, len);
            arr[i] = arr[index_min_el];
            arr[index_min_el] = buff;
            key++;
        }
    }
}

int min_el(int *arr, int start_index, int len)
{
    int min = arr[start_index];
    int index_min = start_index; 
    for(unsigned i = start_index+1; i < len; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            index_min = i;
        }
    }
    
    return index_min;
}

void print_arr(int *arr, int len)
{
    for(unsigned i = 0; i < len; i++)
        printf("%d, ", arr[i]);
    puts("");
}
