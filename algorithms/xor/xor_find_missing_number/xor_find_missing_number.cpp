#include <iostream>

int xorFindMissingNumber(int *arr, int size) {
    int result = 0;

    for (int i = 1; i <= size + 1; i++)
        result ^= i;
    
    for (int i = 0; i < size; i++)
        result ^= arr[i];

    return result;
}

int main() {
    int arr[5] = {1, 2, 3, 5, 6};

    std::cout << "Missing number: " << xorFindMissingNumber(arr, 5) << std::endl;

    return 0;
}