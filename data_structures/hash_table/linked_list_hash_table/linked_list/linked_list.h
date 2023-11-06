#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdio.h>

struct node {
    struct node *next;
    struct node *previous;
    int num;
};

struct node *first;
struct node *current;
struct node *new_node;

struct node * create_node(void);
void delete_node(struct node *del_node);
void fill_node(void);
void print_all_nodes(void);
void print_all_nodes_reverse(void);

#endif /* _LINKED_LIST_H_ */