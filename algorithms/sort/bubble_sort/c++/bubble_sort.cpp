#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& arr, int size);

int main() {
    std::vector<int> arr;
    int size;
    int input;

    /* Input array and size */
    std::cout << "Input array size: ";
    std::cin >> size;

    /* Fill array */
    for (int i = 0; i < size; i++) {
        std::cout << "Input arr[" << i << "] = ";
        std::cin >> input;
        arr.push_back(input);
    }
        
    /* Sort array */
    bubble_sort(arr, size);

    /* Print sorted array */
    for (int i = 1; i <= size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}

void bubble_sort(std::vector<int>& arr, int size) {
    int tmp;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}