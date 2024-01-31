#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

#include <iostream>

template<typename KeyType, typename ValueType>
class Node {
public:
    Node(KeyType key, ValueType value);
    ~Node();
    KeyType key;
    ValueType value;
    class Node* left = nullptr;
    class Node* right = nullptr;

    void insertNode(class Node* rootNode, KeyType key, ValueType value);
    class Node* deleteNode(class Node* rootNode, KeyType key);
    class Node* searchNode(class Node* rootNode, KeyType key);
    class Node* getMinNode(class Node* rootNode);
    class Node* getMaxNode(class Node* rootNode);
    void symmetricTreePrint(class Node* rootNode);
    void reverseTreePrint(class Node* rootNode);
    void directTreePrint(class Node* rootNode);

    class Node* currentNode = nullptr;
};

#endif // _BINARY_SEARCH_TREE_H