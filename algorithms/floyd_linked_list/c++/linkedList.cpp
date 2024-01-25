#include <iostream>
#include <string>

#include "linkedList.h"

void LinkedList::pushBack(std::string name) {
    if (!first) {
        first = new LinkedList();
        first->name = name;
    } else {
        LinkedList* current = first;

        while (current->next)
            current = current->next;

        current->next = new LinkedList();
        current->name = name;
    }

    listSize++;
}

void LinkedList::printNodes() {
    LinkedList* current = first;
    
    while (current) {
        std::cout << current->name << std::endl;
        current = current->next;
    }
}

bool LinkedList::isLoop() {
    LinkedList* rabbit = first;
    LinkedList* turtle = first;

    while (true) {
        rabbit = rabbit->next;
        if (rabbit == turtle)
            return true;

        if (rabbit == nullptr)
            return false;
        
        
        rabbit = rabbit->next;
        turtle = turtle->next;
        if (rabbit == turtle)
            return true;

        if (rabbit == nullptr)
            return false;
    }
}
