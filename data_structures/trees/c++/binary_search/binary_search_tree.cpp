#include <iostream>

#include "binary_search_tree.h"

Node::Node(int key, int value) {
    this->key = key;
    this->value = value;
}

Node::~Node() {
    std::cout << "Node delete\n";
}

void Node::insertNode(class Node* node, int key, int value) {
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

class Node* Node::deleteNode(class Node* node, int key) {
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

class Node* Node::searchNode(class Node* node, int key) {
    if (node == nullptr)
        return nullptr;
    
    if (node->key == key)
        return node;
    
    if (node->key > key)
        searchNode(node->left, node->key);
    else
        searchNode(node->right, node->key);
}

class Node* Node::getMinNode(class Node* node) {
    if (node == nullptr)
        return nullptr;
    
    if (node->left == nullptr)
        return node;
    
    return getMinNode(node);
}

class Node* Node::getMaxNode(class Node* node) {
    if (node == nullptr)
        return nullptr;

    if (node->right == nullptr)
        return node;
    
    return getMaxNode(node);
}

void Node::symmetricTreePrint(class Node* node) {
    if (node == nullptr)
        return;
    
    symmetricTreePrint(node->left);
    std::cout << node->value << std::endl;
    symmetricTreePrint(node->right);
}

void Node::reverseTreePrint(class Node* node) {
    if (node == nullptr)
        return;
    
    reverseTreePrint(node->left);
    reverseTreePrint(node->right);
    std::cout << node->value << std::endl;
}

void Node::directTreePrint(class Node* node) {
    if (node == nullptr)
        return;
    
    std::cout << node->value << std::endl;    
    directTreePrint(node->left);
    directTreePrint(node->right);
}