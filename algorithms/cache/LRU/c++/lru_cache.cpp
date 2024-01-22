#include <iostream>
#include <unordered_map>
#include <list>

#include "lru_cache.h"

void LRUCache::put(int key, int value) {
    auto iter = htKeyValue.find(key);

    //If this element exist
    if (iter != htKeyValue.end()) {
        auto listIter = htKeyIterator.find(key);
        
        //if element is first, then exit
        if (listIter == htKeyIterator.begin()) {
            return;
        }

        //if element is not first, then delete it
        nodes.erase(listIter->second);
    } else {
        //If list size full, then delete last
        if (nodes.size() == capacity) {
            int lastKey = nodes.back();
            nodes.pop_back();
            htKeyValue.erase(lastKey);
            htKeyIterator.erase(lastKey);
        }
    }
    //Update place of element
    nodes.push_front(key);
    htKeyIterator[key] = nodes.begin();
    htKeyValue[key] = value;
}

int LRUCache::get(int key) {
    auto iter = htKeyValue.find(key);
    if (iter == htKeyValue.end()) {
        return -1;
    }

    //Update place of element
    auto listIter = htKeyIterator[key];
    if (listIter != nodes.begin()) {
        nodes.erase(listIter);
        nodes.push_front(key);
        htKeyIterator[key] = nodes.begin();
    }
    return iter->second;
}