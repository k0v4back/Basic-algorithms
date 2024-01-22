#include <iostream>
#include <unordered_map>
#include <list>

#include "mru_cache.h"

void MRUCache::put(int key, int value) {
    auto iter = htKeyValue.find(key);

    //If this element exist
    if (iter != htKeyValue.end()) {
        auto listIter = htKeyIterator.find(key);
        
        //if element is last, then exit
        if (listIter != htKeyIterator.end()) {
            return;
        }

        //if element is first, then delete it
        nodes.erase(listIter->second);
    } else {
        //If list size full, then delete first
        if (nodes.size() == capacity) {
            int firstKey = nodes.front();
            nodes.pop_front();
            htKeyValue.erase(firstKey);
            htKeyIterator.erase(firstKey);
        }
    }
    //Update place of element
    nodes.push_back(key);
    htKeyIterator[key] = nodes.end();
    htKeyValue[key] = value;
}

int MRUCache::get(int key) {
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