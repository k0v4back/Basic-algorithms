#include <stdio.h>
#include <stdlib.h>

void merge(int * arr, int left, int middle, int right);
void merge_sort(int * arr, int left, int right);

int main(void)
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    
    merge_sort(arr, 0, arr_size - 1);

    for(int i = 0; i < 6; i++)
        printf("%d\n", arr[i]);

    return 0;
}


void merge(int * arr, int left, int middle, int right)
{
    /* parts of arrays */
    int left_part = left;
    int right_part = middle + 1;
    int part_res_arr = left;

    int res_arr[6];

    printf("%d, %d, %d, %d\n", left_part, middle, right_part, right); 
    while(left_part < middle && right_part < right){
        if(arr[left_part] >= arr[right_part]){
            res_arr[part_res_arr] = arr[left_part];
            part_res_arr++;
            left_part++;
        }
        else{
            res_arr[part_res_arr] = arr[right_part];
            part_res_arr++;
            right_part++;
        }
    }

    if(left_part > middle){
        while(right_part < right){
            res_arr[part_res_arr] = arr[right_part];
            part_res_arr++;
            right_part++;
        }
    }else{
        while(left_part <= middle){
            res_arr[part_res_arr] = arr[left_part];
            part_res_arr++;
            left_part++;
        }
    }

    for(int i = left; i <= right; i++)
        arr[i] = res_arr[i];
}

void merge_sort(int * arr, int left, int right)
{
    if(left < right){
        int middle = left + (right - left) / 2;
        
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}
