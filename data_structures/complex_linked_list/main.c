#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char **argv)
{
    int val_a= 543;
    int val_b= 400;
    double val_c= 42.5;
    double val_d= 63.3;
    char * val_e = "Vadim";
    char * val_x = "Kosolapov";

    struct node * node = node_create(&val_a, _DECEMAL_ELEM);
    struct node * temp = NULL;
    
    temp = fill_node_last(node, &val_b, _DECEMAL_ELEM);
    temp = fill_node_last(node, &val_d, _REAL_ELEM);
    temp = fill_node_last(node, val_e, _STRING_ELEM);
    temp = fill_node_last(node, val_x, _STRING_ELEM);
    print_all_nodes(node);

    delete_node(node, find_node_by_value(node, &val_d, _REAL_ELEM)); 
    print_all_nodes(node);

    return 0;
}

/*
 * Creating a new node and inserting it at the end of the linked list
 * Arguments: data of new element, the data type of the new element
 */
struct node * node_create(void * data, enum value_type_element type)
{
    struct node * tmp_node = NULL;
    tmp_node = (struct node *)malloc(sizeof(struct node));
    if(tmp_node == NULL){
        LOG_ERROR("%s\n.", "No memory allocated");
        exit(1);
    }
    tmp_node->data = data;
    tmp_node->type = type;
    tmp_node->next = NULL;
    tmp_node->previous = NULL;

    return tmp_node;
}

/*
 * Filling a new node and inserting it at the end of the linked list
 * Arguments: pointer to linked list, data of new node, the data type of the new element
 */
struct node * fill_node_last(struct node * node, void * data, enum value_type_element type)
{
    struct node * new_node = NULL;
    new_node = node_create(data, type);
    if(new_node != NULL){
        while(node->next != NULL) // go to the end of the list
            node = node->next;
        node->next = new_node;
        new_node->previous = node;
    }

    return new_node;
}

/*
 * Searching for an item in the list by value
 * Arguments: pointer to a linked list, pointer to data, data type
 */
struct node * find_node_by_value(struct node * node, void * data, enum value_type_element type)
{
    while(node != NULL){
        if(node->type == type && node->data == data)
            break;
        node = node->next;
    }    

    return node;
}

/*
 * Deleting node of linked list
 * Arguments: pointer to linked list, pointer to node  which we are looking for
 */
void delete_node(struct node * first_node, struct node * node)
{
    struct node * tmp_node = first_node;

    if(node == NULL){
        LOG_ERROR("%s\n.", "Node is null");
        exit(3);
    }
    
    /* Navigating to the node to delete */
    while(tmp_node != node){
        tmp_node = tmp_node->next;
    }

    node->previous = node->next;
    free(node);
}

/*
 * Deleting all the elements that are in linked list
 * Argument: pointer to linked list
 */
void delete_all_nodes(struct node * node)
{
    struct node * tmp_node = NULL;

    if(node == NULL){
        LOG_ERROR("%s\n.", "Node is null");
        exit(3);
    }
    
    while(node != NULL){
        tmp_node = node->next;
        free(node);
        node = node->next;
    }
}

/*
 * Printing all the elements that are in linked list
 * Argument: pointer to linked list
 */
void print_all_nodes(struct node * node)
{
    if(node == NULL){
        LOG_ERROR("%s\n.", "Node is null");
        exit(3);
    }

    printf("[\n");
    while(node != NULL){
        switch(node->type)
        {
            case _DECEMAL_ELEM:
                printf("data = %d \n", *((int*)(node->data)));
                break;
            case _REAL_ELEM:
                printf("data = %lf \n", *((double*)(node->data)));
                break;
            case _STRING_ELEM:
                printf("data = %s \n", (char*)(node->data));
                break;
        }
        node = node->next;
    }
    printf("]\n\n");
}
