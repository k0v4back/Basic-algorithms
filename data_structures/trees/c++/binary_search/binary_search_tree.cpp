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
    else if (node->key > key)
        delete node->left;
    else if (node->key < key)
        delete node->right;
    else {
        if (node->left == nullptr && node->right == nullptr) {
            if (node->left == nullptr)
                node = node->right;
            else
                node = node->left;
        } else {

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

void Node::printTree(class Node* node) {
    if (node == nullptr)
        return;
    
    printTree(node->left);
    std::cout << node->value << std::endl;
    printTree(node->right);
}