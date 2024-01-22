#include <iostream>

#include "lru_cache.h"

int main(void) {
    LRUCache* lRUCache = new LRUCache(2);
    
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    std::cout << lRUCache->get(1) << std::endl;    // return 1
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    std::cout << lRUCache->get(2) << std::endl;    // returns -1 (not found)
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    std::cout << lRUCache->get(1) << std::endl;    // return -1 (not found)
    std::cout << lRUCache->get(3) << std::endl;    // return 3
    std::cout << lRUCache->get(4) << std::endl;    // return 4
    
    return 0;
}
