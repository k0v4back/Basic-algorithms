#include <iostream>

using namespace std;

int partLomutoSort(int* arr, int start, int end, int size);
void quikLomutoSort(int* arr, int start, int end, int size);
void LomutoSort(int* arr, int size);
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

    LomutoSort(arr, size);
    printArray(arr, size);

    return 0;
}

void LomutoSort(int* arr, int size) {
    quikLomutoSort(arr, 0, size - 1, size);
}

void quikLomutoSort(int* arr, int start, int end, int size) {
    if (start >= end)
        return;
    
    int rightStart = partLomutoSort(arr, start, end, size);
    quikLomutoSort(arr, start, rightStart - 1, size);
    quikLomutoSort(arr, rightStart + 1, end, size);
}

int partLomutoSort(int* arr, int start, int end, int size) {
    int left = start;
    
    for (int current = start; current < end; current++) {
        if (arr[current] <= arr[end]) {
            swap(arr[left], arr[current]);
            left++;
        }
    }

    swap(arr[end], arr[left]);

    return left;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << "arr[" << i << "]=" << arr[i] << " ";
    cout << endl;
}