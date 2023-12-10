#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& arr);

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
    insertion_sort(arr);

    /* Print sorted array */
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}

void insertion_sort(std::vector<int>& arr) {
    int tmp;
    
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            } else {
                break;
            }
        }
    }
}