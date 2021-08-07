#include <stdio.h>
#include <stdlib.h>

#define BIN_SEARCH_SUCCESS 1

void fill_array(int * arr, unsigned count);
int binary_search(int * arr, unsigned count_elem, unsigned hidden_num);

int main(void)
{
    int * array;
    unsigned count_elem, hidden_num;

    puts("Enter count of numbers");
    scanf("%u", &count_elem);
    fflush(stdin);

    puts("Enter hidden number");
    scanf("%u", &hidden_num);
    fflush(stdin);

    array = (int *)malloc(count_elem * sizeof(int));
    if(!array)
    {
        puts("Cann't allocate memory for array");
        exit(1);
    }

    fill_array(array, count_elem);

    if(binary_search(array, count_elem, hidden_num) == BIN_SEARCH_SUCCESS)
        printf("SUCCESS\n");

    return 0;
}

void fill_array(int * arr, unsigned count)
{
    for(unsigned i = 0; i < count; i++)
        arr[i] = i + 1;
}

int binary_search(int * arr, unsigned count_elem, unsigned hidden_num)
{
    unsigned guess, mid, min_index = 0, max_index = count_elem - 1;
    
    while(min_index <= max_index)
    {
        mid = (min_index + max_index) / 2;
        guess = arr[mid];
        if(hidden_num == guess)
        {
            printf("Hidden number == %d\n", guess);
            return BIN_SEARCH_SUCCESS;
        }
        else if(guess > hidden_num)
            max_index = mid - 1;
        else if(guess < hidden_num)
            min_index = mid + 1;
    }
}

