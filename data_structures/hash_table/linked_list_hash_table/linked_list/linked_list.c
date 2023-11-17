#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

struct Node* create_node(enum value_type_element key, enum value_type_element value)
{
    struct Node* tmp_node = NULL;

    tmp_node = (struct Node*)malloc(sizeof(struct Node));
    if (!tmp_node){
        fprintf(stderr, "%s", "No memory allocated");
        exit(1);
    }

    tmp_node->key = key;
    tmp_node->value = value;
    tmp_node->next = NULL;
    tmp_node->previous = NULL;

    return tmp_node;
}

void fill_last_node(struct Node* node, enum value_type_element key, enum value_type_element value)
{
    struct Node* new_node = NULL;

    if (node->previous == NULL && node->next == NULL) {
        new_node = create_node(key, value);
        node->next= new_node;
        new_node->previous = node;

        node->key = key;
        node->value = value;

        return;
    }

    new_node = create_node(key, value);
    while (node->next)
        node = node->next;
    node->next= new_node;
    new_node->previous = node;
}

void delete_node(struct Node* first_node, struct Node* del_node)
{
    struct Node* tmp_node = first_node;

    if(!del_node){
        fprintf(stderr, "%s", "Delete node is null");
        exit(1);
    }

    while(tmp_node != del_node)
        tmp_node = tmp_node->next;
    
    del_node->previous = del_node->next;
    free(del_node);
}

void delete_all_node(struct Node* node)
{
    struct Node* tmp_node = NULL;

    if(!node){
        fprintf(stderr, "%s", "Node is null");
        exit(1);
    }

    while(node) {
        tmp_node = node->next;
        free(node);
        node = node->next;
    }
}

void print_all_nodes(struct Node* node)
{
    if(!node){
        fprintf(stderr, "%s", "Node is null");
        exit(1);
    }

    while(node) {
        printf("[key:%d, value:%d], ", node->key, node->value);
        node = node->next;
    }
}