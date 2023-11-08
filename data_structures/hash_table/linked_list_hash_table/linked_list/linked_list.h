#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdio.h>

struct Node {
    struct Node *next;
    struct Node *previous;
    int key;
    int value;
};

struct Node *first;
struct Node *current;
struct Node *new_node;

struct Node * create_node(int key, int value);
void delete_node(struct Node *del_node);
void print_all_nodes(void);
void print_all_nodes_reverse(void);

#endif /* _LINKED_LIST_H_ */