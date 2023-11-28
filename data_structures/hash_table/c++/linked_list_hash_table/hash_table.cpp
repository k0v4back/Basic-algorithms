#include <iostream>

using namespace std;

#include "hash_table.h"

template<typename T>
HashTab<T>::HashTab() {
    size = 1000;

    ppNode = new List<T>*[size];

    for (int i = 0; i < size; i++)
        ppNode[i]->push_back(0);
}

template<typename T>
HashTab<T>::HashTab(int size) {
    this->size = size;

    ppNode = new List<T>*[size];

    for (int i = 0; i < size; i++)
        ppNode[i]->push_back(0);
}

template<typename T>
HashTab<T>::~HashTab() {
    delete[] ppNode; 
}

template<typename T>
List<T>* HashTab<T>::getHashTab(T key) {
    return ppNode[hashCalculate(key)];
}

template<typename T>
void HashTab<T>::setHashTab(T key, T value) {
    ppNode[hashCalculate(key)]->push_back(value);
}

template<typename T>
bool HashTab<T>::inHashTab(T key) {
    return ppNode[hashCalculate(key)] != nullptr;
}

template<typename T>
void HashTab<T>::printHashTab() {
    for (int i = 0; i < size; i++)
        ppNode[hashCalculate(i)]->print_nodes();
}

template<typename T>
int HashTab<T>::hashCalculate(int key) {
    return (key % size);
}

template<typename T>
int HashTab<T>::hashCalculate(string key) {
    int hash = 0;

    for(auto st = key.begin(); st != key.end(); st++)
        hash = *st + 31 * hash;

    return hash % size;
}

template class HashTab<int>;