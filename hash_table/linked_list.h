#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#define LOG_ERROR(format, ...) \
    fprintf(stderr, format, __VA_ARGS__)

enum value_type_element
{
    _DECEMAL_ELEM,
    _REAL_ELEM,
    _STRING_ELEM,
};

struct node
{
    void * data;
    enum value_type_element type;
    struct node * next;
    struct node * previous;
};

struct node * node_create(void * data, enum value_type_element type);
struct node * fill_node_last(struct node * node, void * data, enum value_type_element type);
struct node * find_node_by_value(struct node * node, void * data, enum value_type_element type);
void delete_node(struct node * first_node, struct node * node);
void delete_all_nodes(struct node * node);
void print_all_nodes(struct node * node);

#endif
