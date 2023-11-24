#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "linked_list.h"

struct Node* create_node(enum value_type_element key_type, enum value_type_element value_type)
{
    struct Node* tmp_node = NULL;

    tmp_node = (struct Node*)malloc(sizeof(struct Node));
    if (!tmp_node){
        fprintf(stderr, "%s", "No memory allocated");
        exit(1);
    }

    tmp_node->type.key = key_type;
    tmp_node->type.value = value_type;
    tmp_node->next = NULL;
    tmp_node->previous = NULL;

    return tmp_node;
}

void fill_last_node(struct Node* node, void* key, void* value)
{
    struct Node* new_node = NULL;

    new_node = create_node(node->type.key, node->type.value);

    if (node->previous == NULL && node->next == NULL) {
        node->next= new_node;
        new_node->previous = node;
    } else {
        while (node->next)
            node = node->next;
        node->next= new_node;
        new_node->previous = node;
    }

    /* Check correct key type and set data key */
    switch (new_node->type.key) {
        case _DECEMAL_ELEM:
            new_node->data.key.decimal = (int64_t)key;
            break;
        case _STRING_ELEM:
            new_node->data.key.string = (uint8_t*)key;
            break;
        default:
            fprintf(stderr, "%s", "Key type doesn't exist");
            exit(1);
    }

    /* Check correct value type and set data value */
    switch (new_node->type.value) {
        case _DECEMAL_ELEM:
            new_node->data.value.decimal = (int64_t)value;
            break;
        case _STRING_ELEM:
            new_node->data.value.string = (uint8_t*)value;
            break;
        default:
            fprintf(stderr, "%s", "Value type doesn't exist");
            exit(1);
    }

    //printf("value = %d\n", new_node->data.value);
    //printf("key = %d\n", new_node->data.key);
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
        switch (node->type.key) {
            case _DECEMAL_ELEM:
                printf("[key:%ld,", node->data.key.decimal);
                break;
            case _STRING_ELEM:
                printf("[key:%s,", node->data.key.string);
                break;
        }

        switch (node->type.value) {
            case _DECEMAL_ELEM:
                printf(" value:%ld], ", node->data.value.decimal);
                break;
            case _STRING_ELEM:
                printf(" value:%s], ", node->data.value.string);
                break;
        }

        node = node->next;
    }
}

_Bool in_list(struct Node* node, enum value_type_element key)
{
    if(!node){
        fprintf(stderr, "%s", "Node is null");
        exit(1);
    }

    if(!key){
        fprintf(stderr, "%s", "Node is null");
        exit(1);
    }

    while(node) {
        if (key == node->type.key)
            return true;
        node = node->next;
    }
}

void* get_node(struct Node* node, enum value_type_element key)
{
    if(!node){
        fprintf(stderr, "%s", "Node is null");
        exit(1);
    }

    if(!key){
        fprintf(stderr, "%s", "Node is null");
        exit(1);
    }

    while(node) {
        if (key == node->type.key)
            return (void *)node->type.value;
        node = node->next;
    }
}