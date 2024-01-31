#ifndef _RB_TREE_H_
#define _RB_TREE_H_

enum RBColor {
    RED = 0,
    BLACK = 1
};

class RBNode {
    int key;
    int value;
    RBNode* left;
    RBNode* right;
    RBNode* parent;
    RBColor color;

    RBNode();
    RBNode(int key, int value);
    void Insert(RBNode* rootNode, int key, int value);
    void BalanceTree(RBNode* rootNode, RBNode*newNode);
};

#endif