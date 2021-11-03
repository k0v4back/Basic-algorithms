#include <stdio.h>
#include <stdlib.h>

int * merge(int * arr_a, int len_arr_a, int * arr_b, int len_arr_b);

int main(void)
{
    return 0;
}

int * merge(int * arr_a, int len_arr_a, int * arr_b, int len_arr_b)
{
    int * arr_c; 
    arr_c = (int *)malloc(len_arr_a + len_arr_b);

    int index_a, index_b, index_c = 0; 

    while(index_a < len_arr_a || index_b < len_arr_b){
        if(arr_a[index_a] >= arr_b[index_b]){
            arr_c[index_c] = arr_a[index_a];
            index_a++;
            index_c++;
        }
        else{
            arr_c[index_c] = arr_b[index_b];
            index_b++;
            index_c++;
        }
    }

    while(index_a < len_arr_a){
        arr_c[index_c] = arr_a[index_a];
        index_c++;
        index_a++;
    }

    while(index_b < len_arr_b){
        arr_c[index_c] = arr_b[index_b];
        index_c++;
        index_b++;
    }

    return arr_c;
}
