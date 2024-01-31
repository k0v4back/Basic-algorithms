#include <iostream>

#include "binary_search_tree.h"

template<typename KeyType, typename ValueType>
Node<KeyType, ValueType>::Node(KeyType key, ValueType value) {
    this->key = key;
    this->value = value;
}

template<typename KeyType, typename ValueType>
Node<KeyType, ValueType>::~Node() {
    std::cout << "Node delete\n";
}

template<typename KeyType, typename ValueType>
void Node<KeyType, ValueType>::insertNode(class Node* rootNode, KeyType key, ValueType value) {
    /* Recursively go to the left */
    if (key < rootNode->key) {
        if (rootNode->left == nullptr)
            rootNode->left = new Node(key, value);
        else
            insertNode(rootNode->left, key, value);
    }

    /* Recursively go to the right */
    if (key >= rootNode->key) {
        if (rootNode->right == nullptr)
            rootNode->right = new Node(key, value);
        else
            insertNode(rootNode->right, key, value);
    }
}

template<typename KeyType, typename ValueType>
class Node<KeyType, ValueType>* Node<KeyType, ValueType>::deleteNode(class Node* rootNode, KeyType key) {
    if (rootNode == nullptr)
        return nullptr;
    else if (key < rootNode->key)
        deleteNode(rootNode->left, key);
    else if (key > rootNode->key)
        deleteNode(rootNode->right, key);
    else {
        /* Overwriting the deleted item with one of the parents */
        if (rootNode->left == nullptr && rootNode->right == nullptr) {
            if (rootNode->left == nullptr)
                rootNode = rootNode->right;
            else
                rootNode = rootNode->left;
        } else {
            class Node* maxInLeft = getMaxNode(rootNode->left);
            rootNode->key = maxInLeft->key;
            rootNode->value = maxInLeft->value;
            rootNode->right = deleteNode(rootNode->right, maxInLeft->key);
        }
    }

    return rootNode;
}

template<typename KeyType, typename ValueType>
class Node<KeyType, ValueType>* Node<KeyType, ValueType>::searchNode(class Node* rootNode, KeyType key) {
    if (rootNode == nullptr)
        return nullptr;
    
    if (rootNode->key == key)
        return rootNode;
    
    if (rootNode->key > key)
        searchNode(rootNode->left, rootNode->key);
    else
        searchNode(rootNode->right, rootNode->key);
    
    return rootNode;
}

template<typename KeyType, typename ValueType>
class Node<KeyType, ValueType>* Node<KeyType, ValueType>::getMinNode(class Node* rootNode) {
    if (rootNode == nullptr)
        return nullptr;
    
    if (rootNode->left == nullptr)
        return rootNode;
    
    return getMinNode(rootNode);
}

template<typename KeyType, typename ValueType>
class Node<KeyType, ValueType>* Node<KeyType, ValueType>::getMaxNode(class Node* rootNode) {
    if (rootNode == nullptr)
        return nullptr;

    if (rootNode->right == nullptr)
        return rootNode;
    
    return getMaxNode(rootNode);
}

template<typename KeyType, typename ValueType>
void Node<KeyType, ValueType>::symmetricTreePrint(class Node* rootNode) {
    if (rootNode == nullptr)
        return;
    
    symmetricTreePrint(rootNode->left);
    std::cout << rootNode->value << std::endl;
    symmetricTreePrint(rootNode->right);
}

template<typename KeyType, typename ValueType>
void Node<KeyType, ValueType>::reverseTreePrint(class Node* rootNode) {
    if (rootNode == nullptr)
        return;
    
    reverseTreePrint(rootNode->left);
    reverseTreePrint(rootNode->right);
    std::cout << rootNode->value << std::endl;
}

template<typename KeyType, typename ValueType>
void Node<KeyType, ValueType>::directTreePrint(class Node* rootNode) {
    if (rootNode == nullptr)
        return;
    
    std::cout << rootNode->value << std::endl;    
    directTreePrint(rootNode->left);
    directTreePrint(rootNode->right);
}

template class Node<int, int>;
template class Node<int, std::string>;