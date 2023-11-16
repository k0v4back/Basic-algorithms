#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

struct Node * create_node(int key, int value)
{
    if (first == NULL) {
        first = (struct Node *)malloc(sizeof(struct Node));
        if (!first){
            fprintf(stderr, "%s", "No memory allocated");
            exit(1);
        }

        first->next = NULL;
        first->previous = NULL;
        first->key = key;
        first->value = value;
        current = first;

        return current;
    }

    new_node = (struct Node *)malloc(sizeof(struct Node));
    if (!new_node){
        fprintf(stderr, "%s", "No memory allocated");
        exit(1);
    }

    current->next = new_node;
    new_node->previous = current;
    new_node->key = key;
    new_node->value = value;
    current = new_node;

    return current;
}

void set_node(struct Node *node, int key, int value)
{
    node->key = key;
    node->value = value;
}

void delete_node(struct Node *del_node)
{
    current = first;

    while(current->key != del_node->key)
        current = current->next;

    del_node->previous = current->next;

    free(del_node);
}

void set_end_list(void)
{
    current = first;
    while(current)
        current = current->next;
}

void print_all_nodes(void)
{
    current = first;
    while(current) {
        printf("key: %d, value: %d", current->key, current->value);
        current = current->next;
    }
}

void print_all_nodes_reverse(void)
{
    set_end_list();
    
    current = current->previous;
    while(current) {
        printf("key: %d, value: %d", current->key, current->value);
        current = current->previous;
    }
}