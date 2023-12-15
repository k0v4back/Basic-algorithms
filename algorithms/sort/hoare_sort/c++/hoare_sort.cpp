#include <iostream>

using namespace std;

int partHoareSort(int* arr, int left, int right, int size);
void quikHoareSort(int* arr, int start, int end, int size);
void hoareSort(int* arr, int size);
void printArray(int* arr, int size);

int main(void) {
    int size;

    cout << "Input array size: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Fill array: \n";
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i <<"]=";
        cin >> arr[i];
    }

    hoareSort(arr, size);
    printArray(arr, size);

    return 0;
}

void hoareSort(int* arr, int size) {
    quikHoareSort(arr, 0, size - 1, size);
}

void quikHoareSort(int* arr, int start, int end, int size) {
    if (start >= end)
        return;
    
    int rightStart = partHoareSort(arr, start, end, size);
    quikHoareSort(arr, start, rightStart - 1, size);
    quikHoareSort(arr, rightStart, end, size);
}

int partHoareSort(int* arr, int left, int right, int size) {
    int pivot = arr[(left + right) / 2];

    while (left <= right) {
        while (arr[left] < pivot)
            left++;
        
        while (arr[right] > pivot)
            right--;
        
        /* Swapping the array elements */
        if (left <= right) {
            iter_swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }

    return left;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << "arr[" << i << "]=" << arr[i] << " ";
    cout << endl;
}