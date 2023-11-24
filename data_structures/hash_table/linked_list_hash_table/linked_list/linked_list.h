#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdio.h>

enum value_type_element
{
    _DECEMAL_ELEM,
    _REAL_ELEM,
    _STRING_ELEM,
};

union value_list_t {
    int64_t decimal;
    double real;
    uint8_t *string;
};

struct Node {
    struct Node* next;
    struct Node* previous;
    struct {
        enum value_type_element key;
        enum value_type_element value;
    } type;
    struct {
        union value_list_t key;
        union value_list_t value;
    } data;
};

struct Node* create_node(enum value_type_element key_type, enum value_type_element value_type);
void fill_last_node(struct Node* node, void* key, void* value);
void delete_node(struct Node* first_node, struct Node* del_node);
void delete_all_node(struct Node* node);
void print_all_nodes(struct Node* node);
_Bool in_list(struct Node* node, enum value_type_element key);
void* get_node(struct Node* node, enum value_type_element key);

#endif /* _LINKED_LIST_H_ */