#include <stdio.h>

#define ARR_LEN(x) (sizeof(x) / sizeof(x[0]))

unsigned long int get_hash(char *str_key, int len);
unsigned long int get_index(char *str_key, int len, int len_value_arr);
void save_value(char *str_key, int len, int value,
        int *value_arr, int len_value_arr);
int get_value(char *str_key, int len, 
        int *value_arr, int len_value_arr);

int main(void)
{
    char str_key_1[1] = {'A'};
    char str_key_2[2] = {'A', 1};
    char str_key_3[3] = {'A', 'B', 'C'};
    char str_key_4[4] = {'A', 'B', 'C', 'D'};
    char str_key_5[5] = {'A', 'B', 'C', 'D', 'E'};
    int value_arr[30] = {0};

    save_value(str_key_1, ARR_LEN(str_key_1), 1, value_arr, ARR_LEN(value_arr));
    save_value(str_key_2, ARR_LEN(str_key_2), 2, value_arr, ARR_LEN(value_arr));
    save_value(str_key_3, ARR_LEN(str_key_3), 3, value_arr, ARR_LEN(value_arr));
    save_value(str_key_4, ARR_LEN(str_key_4), 4, value_arr, ARR_LEN(value_arr));
    save_value(str_key_5, ARR_LEN(str_key_5), 5, value_arr, ARR_LEN(value_arr));

    printf("str_key_1=%d\n", get_value(str_key_1, ARR_LEN(str_key_1), value_arr, ARR_LEN(value_arr)));
    printf("str_key_2=%d\n", get_value(str_key_2, ARR_LEN(str_key_2), value_arr, ARR_LEN(value_arr)));
    printf("str_key_3=%d\n", get_value(str_key_3, ARR_LEN(str_key_3), value_arr, ARR_LEN(value_arr)));
    printf("str_key_4=%d\n", get_value(str_key_4, ARR_LEN(str_key_4), value_arr, ARR_LEN(value_arr)));
    printf("str_key_5=%d\n", get_value(str_key_5, ARR_LEN(str_key_5), value_arr, ARR_LEN(value_arr)));

    return 0;
}

unsigned long int get_hash(char *str_key, int len)
{
    unsigned long int result_hash = 0;
    int i;

    for (i = 0; i < len; i++)
        result_hash = (result_hash << 8) + str_key[i];

    return result_hash;
}

unsigned long int get_index(char *str_key, int len, int len_value_arr)
{
    int hash = get_hash(str_key, len);

    return (hash % len_value_arr);
}

void save_value(char *str_key, int len, int value,
        int *value_arr, int len_value_arr)
{
    int arr_index;
    
    arr_index = get_index(str_key, len, len_value_arr);
    value_arr[arr_index] = value;
}

int get_value(char *str_key, int len, int *value_arr, int len_value_arr)
{
    int arr_index;

    arr_index = get_index(str_key, len, len_value_arr);

    return value_arr[arr_index]; 
}
