#include <iostream>

#include "binary_search_tree.h"

int main(void) {
    class Node* node = new Node(6, 6);

    node->insertNode(node, 4, 4);
    node->insertNode(node, 8, 8);
    node->insertNode(node, 7, 7);

    node->symmetricTreePrint(node);

    return 0;
}