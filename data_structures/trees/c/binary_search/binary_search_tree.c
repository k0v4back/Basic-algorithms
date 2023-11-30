#include <stdio.h>
#include <stdlib.h>

struct binary_tree_node {
    struct binary_tree_node *left;
    struct binary_tree_node *right;
    int value;
};

struct binary_tree_node * search_binary_tree_node(
        struct binary_tree_node *tree,
        int value);
void insert_node(struct binary_tree_node **parent_node,
        int value);
struct binary_tree_node * create_tree_node(
        int value);

/* Recursive depth search */
void recursive_depth_search(
        struct binary_tree_node *tree);

int main(void)
{
    struct binary_tree_node * first_node = NULL;

    /* Add some nodes to binary tree */
    insert_node(&first_node, 0);
    insert_node(&first_node, 4);
    insert_node(&first_node, 4);
    insert_node(&first_node, 5);
    insert_node(&first_node, 6);
    insert_node(&first_node, 8);

    recursive_depth_search(first_node);

    return 0;
}

struct binary_tree_node * search_binary_tree_node(
        struct binary_tree_node *tree,
        int value)
{
    if (tree->value < value) {
        tree = tree->left;
        search_binary_tree_node(tree, value);
    } else if (tree->value > value) {
        tree = tree->right;
        search_binary_tree_node(tree, value);
    } else if (tree->value == value) {
        return tree;
    }
}

void insert_node(struct binary_tree_node **parent_node,
        int value)
{
    struct binary_tree_node *tmp_node = *parent_node;

    if (tmp_node == NULL) {
        *parent_node = create_tree_node(value);
    } else if (value < tmp_node->value) {
        if (tmp_node->left == NULL) {
            tmp_node->left = create_tree_node(value);
        } else {
            insert_node(&(tmp_node->left), value);
        }
    } else if (value > tmp_node->value) {
        if (tmp_node->right == NULL) {
            tmp_node->right = create_tree_node(value);
        } else {
            insert_node(&(tmp_node->left), value);
        }
    }
}

struct binary_tree_node * create_tree_node(
        int value)
{
    struct binary_tree_node * new_tree_node = (struct binary_tree_node *)
        malloc(sizeof(struct binary_tree_node));
    if (new_tree_node == NULL) {
        printf("Cannot allocate memory for new tree node\n");
        exit(-1);
    }

    new_tree_node->left = NULL;
    new_tree_node->right = NULL;
    new_tree_node->value = value;

    return new_tree_node;
}

void recursive_depth_search(
        struct binary_tree_node *tree)
{
    if (tree != NULL) {
        printf("%d\n", tree->value);
        if (tree->left != NULL)
            recursive_depth_search(tree->left);
        if (tree->right != NULL)
            recursive_depth_search(tree->right);
    } else {
        return;
    }
}
