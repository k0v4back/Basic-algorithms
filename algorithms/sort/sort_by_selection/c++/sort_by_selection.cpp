#include <iostream>
#include <vector>

void selection_sort(std::vector<int>& arr);

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
    selection_sort(arr);

    /* Print sorted array */
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}

void selection_sort(std::vector<int>& arr) {
    int tmp;
    int min;
    int index_min;
    
    for (int i = 0; i < arr.size() - 1; i++) {
        min = arr[i];
        index_min = i;
        for (int j = i + 1; j < arr.size(); j++) {
            /* Find min */
            if (arr[j] < min) {
                min = arr[j];
                index_min = j;
            }

            /* If min exist, switch */
            if (index_min != i) {
                tmp = arr[i];
                arr[i] = arr[index_min];
                arr[index_min] = tmp;
            }
        }
    }
}