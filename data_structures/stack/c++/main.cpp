#include <iostream>

#include "stack.h"

int main(void) {
    class Stack* stack = new Stack(1);

    stack->pushNode(2);
    stack->pushNode(3);
    stack->pushNode(4);
    stack->pushNode(5);

    stack->printStack();

    return 0;
}