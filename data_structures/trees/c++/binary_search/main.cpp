#include <iostream>

#include "binary_search_tree.h"

int main(void) {
    class Node<int, std::string>* rootNode = new Node<int, std::string>(6, "one");
    rootNode->insertNode(rootNode, 4, "two");
    rootNode->insertNode(rootNode, 8, "three");
    rootNode->insertNode(rootNode, 7, "four");
    rootNode->symmetricTreePrint(rootNode);

    /*
    class Node<int, int>* rootNode = new Node<int, int>(6, 6);
    rootNode->insertNode(rootNode, 4, 4);
    rootNode->insertNode(rootNode, 8, 8);
    rootNode->insertNode(rootNode, 7, 7);
    */

    return 0;
}