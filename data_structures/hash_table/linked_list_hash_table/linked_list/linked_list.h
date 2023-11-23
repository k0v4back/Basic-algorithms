#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdio.h>

enum value_type_element
{
    _DECEMAL_ELEM,
    _REAL_ELEM,
    _STRING_ELEM,
};

struct Node {
    struct Node* next;
    struct Node* previous;
    enum value_type_element key;
    enum value_type_element value;
};

struct Node* create_node(enum value_type_element key, enum value_type_element value);
void fill_last_node(struct Node* node, enum value_type_element key, enum value_type_element value);
void delete_node(struct Node* first_node, struct Node* del_node);
void delete_all_node(struct Node* node);
void print_all_nodes(struct Node* node);
_Bool in_list(struct Node* node, enum value_type_element key);
void* get_node(struct Node* node, enum value_type_element key);

#endif /* _LINKED_LIST_H_ */