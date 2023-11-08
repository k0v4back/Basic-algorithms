#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

struct Node * create_node(int key, int value)
{
    if (first == NULL) {
        first = (struct Node *)malloc(sizeof(*first));
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

    new_node = (struct Node *)malloc(sizeof(*new_node));
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

void delete_node(struct Node *del_node)
{
    current = first;

    while(current != del_node)
        current = current->next;
    
    printf("main: current->key=%d\n", current->key);

    del_node->previous = current->next;

    free(del_node);
}

void print_all_nodes(void)
{
    current = first;
    while(current) {
        printf("key: %d\n", current->key);
        current = current->next;
    }
}

void print_all_nodes_reverse(void)
{
    current = first;
    while(current->next)
        current = current->next;
    
    current = current->previous;
    while(current) {
        printf("key: %d\n", current->key);
        current = current->previous;
    }
}