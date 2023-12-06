#include <iostream>

#include "stack.h"

Stack::Stack(int data) {
    this->data = data;
    next = nullptr;
    first = nullptr;
}

Stack::~Stack() {
    std::cout << "Delete stack\n";
}

void Stack::pushNode(int data) {
    if (first == nullptr) {
        this->data = data;
        this->next = nullptr;
    } else {
        class Stack* current = first;

        while (current->next)
            current = current->next;

        current->next = new Stack(data);
    }
}

void Stack::popNode(void) {
    class Stack* current = first;

    while (current->next)
        current = current->next;
    
    delete current;
}

void Stack::printStack(void) {
    class Stack* current = first;

    while (current->next) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

void Stack::deleteStack(void) {

}