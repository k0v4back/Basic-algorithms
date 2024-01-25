#include <iostream>

#include "linkedList.h"

int main() {
    LinkedList* list = new LinkedList();

    for (int i = 0; i < 5; i++) {
        std::string name;
        std::cin >> name;
        list->pushBack(name);
    }

    //list->printNodes();
    if (list->isLoop() == true)
        std::cout << "TRUE\n";
    else
        std::cout << "FALSE\n";
}