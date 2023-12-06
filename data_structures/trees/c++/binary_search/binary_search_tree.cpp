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
void Node<KeyType, ValueType>::insertNode(class Node* node, KeyType key, ValueType value) {
    /* Recursively go to the left */
    if (key < node->key) {
        if (node->left == nullptr)
            node->left = new Node(key, value);
        else
            insertNode(node->left, key, value);
    }

    /* Recursively go to the right */
    if (key >= node->key) {
        if (node->right == nullptr)
            node->right = new Node(key, value);
        else
            insertNode(node->right, key, value);
    }
}

template<typename KeyType, typename ValueType>
class Node<KeyType, ValueType>* Node<KeyType, ValueType>::deleteNode(class Node* node, KeyType key) {
    if (node == nullptr)
        return nullptr;
    else if (key < node->key)
        deleteNode(node->left, key);
    else if (key > node->key)
        deleteNode(node->right, key);
    else {
        /* Overwriting the deleted item with one of the parents */
        if (node->left == nullptr && node->right == nullptr) {
            if (node->left == nullptr)
                node = node->right;
            else
                node = node->left;
        } else {
            class Node* maxInLeft = getMaxNode(node->left);
            node->key = maxInLeft->key;
            node->value = maxInLeft->value;
            node->right = deleteNode(node->right, maxInLeft->key);
        }
    }

    return node;
}

template<typename KeyType, typename ValueType>
class Node<KeyType, ValueType>* Node<KeyType, ValueType>::searchNode(class Node* node, KeyType key) {
    if (node == nullptr)
        return nullptr;
    
    if (node->key == key)
        return node;
    
    if (node->key > key)
        searchNode(node->left, node->key);
    else
        searchNode(node->right, node->key);
    
    return node;
}

template<typename KeyType, typename ValueType>
class Node<KeyType, ValueType>* Node<KeyType, ValueType>::getMinNode(class Node* node) {
    if (node == nullptr)
        return nullptr;
    
    if (node->left == nullptr)
        return node;
    
    return getMinNode(node);
}

template<typename KeyType, typename ValueType>
class Node<KeyType, ValueType>* Node<KeyType, ValueType>::getMaxNode(class Node* node) {
    if (node == nullptr)
        return nullptr;

    if (node->right == nullptr)
        return node;
    
    return getMaxNode(node);
}

template<typename KeyType, typename ValueType>
void Node<KeyType, ValueType>::symmetricTreePrint(class Node* node) {
    if (node == nullptr)
        return;
    
    symmetricTreePrint(node->left);
    std::cout << node->value << std::endl;
    symmetricTreePrint(node->right);
}

template<typename KeyType, typename ValueType>
void Node<KeyType, ValueType>::reverseTreePrint(class Node* node) {
    if (node == nullptr)
        return;
    
    reverseTreePrint(node->left);
    reverseTreePrint(node->right);
    std::cout << node->value << std::endl;
}

template<typename KeyType, typename ValueType>
void Node<KeyType, ValueType>::directTreePrint(class Node* node) {
    if (node == nullptr)
        return;
    
    std::cout << node->value << std::endl;    
    directTreePrint(node->left);
    directTreePrint(node->right);
}

template class Node<int, int>;
template class Node<int, std::string>;