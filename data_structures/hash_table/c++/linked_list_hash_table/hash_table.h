#ifndef _HASHTABLE_LIST_H_
#define _HASHTABLE_LIST_H_

#include <iostream>

#include "linked_list/linked_list.h"

using namespace std;

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
    void setHashTab(T key, T value);
    bool inHashTab(T key);
    void printHashTab();

    int hashCalculate(int key);
    int hashCalculate(string key);
};

#endif /* _HASHTABLE_LIST_H_ */
