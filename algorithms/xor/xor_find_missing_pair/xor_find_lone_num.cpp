#include <iostream>

int xorFindLoneNum(int *arr, int size) {
    int result = 0;
    
    for (int i = 0; i < size; i++)
        result ^= arr[i];

    return result;
}

int main() {
    int arr[5] = {1, 2, 1, 5, 2};

    std::cout << "Lone number: " << xorFindLoneNum(arr, 5) << std::endl;

    return 0;
}