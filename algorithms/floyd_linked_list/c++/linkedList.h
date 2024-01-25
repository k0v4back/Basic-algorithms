#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
#include <string>

class LinkedList {
private:
    std::string name;
    LinkedList* next;
    LinkedList* first;

    int listSize;
public:
    LinkedList() {
        next = nullptr;
        first = nullptr;
        listSize = 0;
    }

    void pushBack(std::string name);
    void printNodes();
    bool isLoop();
};

#endif /* _LINKED_LIST_H */