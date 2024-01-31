#include <iostream>

#include "rb_tree.h"

RBNode* nil = new RBNode();

RBNode::RBNode() {
    color = BLACK;
}

RBNode::RBNode(int key, int value) {
    this->key = key;
    this->value = value;
    left = nil;
    right = nil;
    parent = nil;
    color = RED;
}

void RBNode::Insert(RBNode* rootNode, int key, int value) {
    RBNode* currentNode = rootNode;
    RBNode* parrentNode = nil;

    while (currentNode != nil) {
        parrentNode = currentNode;
        if (value < currentNode->value)
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;
    }

    RBNode* newNode = new RBNode(key, value);
    newNode->parent = parrentNode;

    if (parrentNode == nil)
        rootNode = newNode;
    else if (value < parent->value)
        parent->left = newNode;
    else
        parent->right = newNode;
    
    BalanceTree(rootNode, newNode);
}

void RBNode::BalanceTree(RBNode* rootNode, RBNode*newNode) {
    RBNode* uncle;

    while (newNode->parent == newNode->parent->parent->left) {
        uncle = newNode->parent->parent->right;
        if (uncle->color == RED) {
            newNode->parent->color = BLACK;
            uncle->color = BLACK;
            newNode->parent->parent->color = RED;
            newNode = newNode->parent->parent;
        } else {
            if (newNode == newNode->parent->right) {
                newNode = newNode->parent;
                LeftRotate(rootNode, newNode);
            }
            newNode->parent->color = BLACK;
            newNode->parent->parent->color = RED;
            RightRotate(rootNode, newNode->parent->parent);
        }
    } else {
        uncle = newNode->parent->left;
        if (uncle->color == RED) {
            newNode->parent->color = BLACK;
            uncle->color = BLACK;
            newNode->parent->parent->color = RED;
            newNode = newNode->parent->parent;
        } else {
            if (newNode == newNode->parent->left) {
                newNode = newNode->parent;
                RightRotate(rootNode, newNode);
            }
            newNode->parent->color = BLACK;
            newNode->parent->parent->color = RED;
            LeftRotate(tree, newNode->parent->parent);
        }
    }

    rootNode->color = BLACK;
}