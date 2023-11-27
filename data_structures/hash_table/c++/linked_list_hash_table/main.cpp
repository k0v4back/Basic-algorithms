#include <iostream>

using namespace std;

#include "linked_list/linked_list.h"

template<typename T>
class HashTab {
private:
    int size;
    List<T>** ppNode;
public:
    HashTab();
    HashTab(int size);
    ~HashTab();

    List<T>* getHashTab(T key);
    void setHashTab(T key);
    bool inHashTab(T key);
    void printHashTab();

    int hashCalculate(int key);
    int hashCalculate(string key);
};

template<typename T>
HashTab<T>::HashTab() {
    size = 1000;

    ppNode = new List<T>*[size];

    for (int i = 0; i < size; i++)
        ppNode[i] = push_back(0);
}

template<typename T>
HashTab<T>::HashTab(int size) {
    this->size = size;

    ppNode = new List<T>*[size];

    for (int i = 0; i < size; i++)
        ppNode[i] = push_back(0);
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
void HashTab<T>::setHashTab(T value) {
    push_back(value)
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

    for (string::iterator st = key.begin(), end = key.end(); st != end; ++st)
        hash = *key + 31 * hash;

    return hash % size;
}

int main(void) {
    return 0;
}