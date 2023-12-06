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

    void insertNode(class Node* node, KeyType key, ValueType value);
    class Node* deleteNode(class Node* node, KeyType key);
    class Node* searchNode(class Node* node, KeyType key);
    class Node* getMinNode(class Node* node);
    class Node* getMaxNode(class Node* node);
    void symmetricTreePrint(class Node* node);
    void reverseTreePrint(class Node* node);
    void directTreePrint(class Node* node);

    class Node* currentNode = nullptr;
};

#endif // _BINARY_SEARCH_TREE_H