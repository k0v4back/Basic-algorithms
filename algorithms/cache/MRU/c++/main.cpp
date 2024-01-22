#include <iostream>

#include "mru_cache.h"

int main(void) {
    MRUCache* cache = new MRUCache(2);
    
    cache->put(1, 1); // cache is {1=1}
    cache->put(2, 2); // cache is {1=1, 2=2}
    std::cout << cache->get(1) << std::endl;    // return 1
    cache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    std::cout << cache->get(2) << std::endl;    // returns -1 (not found)
    cache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    std::cout << cache->get(1) << std::endl;    // return -1 (not found)
    std::cout << cache->get(3) << std::endl;    // return 3
    std::cout << cache->get(4) << std::endl;    // return 4
    
    return 0;
}