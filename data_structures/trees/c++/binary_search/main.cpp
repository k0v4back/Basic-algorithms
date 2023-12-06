#include <iostream>

#include "binary_search_tree.h"

int main(void) {
    class Node<int, std::string>* node = new Node<int, std::string>(6, "one");
    node->insertNode(node, 4, "two");
    node->insertNode(node, 8, "three");
    node->insertNode(node, 7, "four");
    node->symmetricTreePrint(node);

    /*
    class Node<int, int>* node = new Node<int, int>(6, 6);
    node->insertNode(node, 4, 4);
    node->insertNode(node, 8, 8);
    node->insertNode(node, 7, 7);
    */

    return 0;
}