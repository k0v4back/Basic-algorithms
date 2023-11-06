#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

struct node * create_node(void)
{
    if (first == NULL) {
        first = (struct node *)malloc(sizeof(*first));
        if (!first){
            fprintf(stderr, "%s", "No memory allocated");
            exit(1);
        }

        first->next = NULL;
        first->previous = NULL;
        current = first;
        fill_node();

        return current;
    }

    new_node = (struct node *)malloc(sizeof(*new_node));
    if (!new_node){
        fprintf(stderr, "%s", "No memory allocated");
        exit(1);
    }

    current->next = new_node;
    new_node->previous = current;
    current = new_node;
    fill_node();

    return current;
}

void delete_node(struct node *del_node)
{
    current = first;

    while(current != del_node)
        current = current->next;
    
    printf("main: current->num=%d\n", current->num);

    del_node->previous = current->next;

    free(del_node);
}

void print_all_nodes(void)
{
    current = first;
    while(current) {
        printf("num: %d\n", current->num);
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
        printf("num: %d\n", current->num);
        current = current->previous;
    }
}

void fill_node(void)
{
    printf("Inter number: ");
    scanf("%d", &current->num);
}