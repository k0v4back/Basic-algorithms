#ifndef _LRU_CACHE_H_
#define _LRU_CACHE_H_

#include <iostream>
#include <unordered_map>
#include <list>

class MRUCache {
private:
    std::list<int> nodes;
    std::unordered_map<int, int> htKeyValue;
    std::unordered_map<int, std::list<int>::iterator> htKeyIterator;
    int capacity;
public:
    MRUCache(int size) : capacity(size) {
        if (size < 1)
            capacity = 5;
    }

    void put(int key, int value);
    int get(int key);
};

#endif /*_MRU_CACHE_H_ */