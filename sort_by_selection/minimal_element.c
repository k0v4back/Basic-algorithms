/*
 * Sort the array in ascending order
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define COUNT_OF_ELEMENTS 5

void fill_array(int * arr);
int * sort_by_selection(int * arr);
int min_el(int * arr);
void print_arr(int * arr);

int main(void)
{
    int nums[COUNT_OF_ELEMENTS];
    int * new_nums;
    
    fill_array(nums);
    new_nums = sort_by_selection(nums);

    puts("\n---------AFTER SORT---------");
    print_arr(new_nums);
}

void fill_array(int * arr)
{
    for(unsigned i = 0; i < COUNT_OF_ELEMENTS; i++)
    {
        int num;
        puts("Enter number");
        scanf("%d", &num);
        arr[i] = num;
    }
}

int * sort_by_selection(int * arr)
{
    int * sorted_array = (int *)malloc(sizeof(int) * COUNT_OF_ELEMENTS);

    for(unsigned i = 0; i < COUNT_OF_ELEMENTS; i++)
    {
        int min_el_index = min_el(arr);
        sorted_array[i] = arr[min_el_index];
        arr[min_el_index] = INT_MAX; /* 'delete' element from array */
    }

    return sorted_array;
}

int min_el(int * arr)
{
    int min = arr[0];
    int index_min = 0; 
    for(unsigned i = 1; i < COUNT_OF_ELEMENTS; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            index_min = i;
        }
    }
    
    return index_min;
}

void print_arr(int * arr)
{
    for(unsigned i = 0; i < COUNT_OF_ELEMENTS; i++)
        printf("%d, ", arr[i]);
    puts("");
}
