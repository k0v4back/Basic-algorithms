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
};

struct node * node_create(void * data, enum value_type_element type);
struct node * fill_node(struct node * node, void * data, enum value_type_element type);
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
    
    temp = fill_node(node, &val_b, _DECEMAL_ELEM);
    temp = fill_node(node, &val_c, _REAL_ELEM);
    temp = fill_node(node, &val_d, _REAL_ELEM);
    temp = fill_node(node, val_e, _STRING_ELEM);
    temp = fill_node(node, val_x, _STRING_ELEM);
    print_all_nodes(node);

    delete_all_nodes(node);
    print_all_nodes(node);

    return 0;
}

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

    return tmp_node;
}

struct node * fill_node(struct node * node, void * data, enum value_type_element type)
{
    struct node * new_node = NULL;
    new_node = node_create(data, type);
    if(new_node != NULL){
        while(node->next != NULL) // go to the end of the list
            node = node->next;
        node->next = new_node;
    }

    return new_node;
}

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

void print_all_nodes(struct node * node)
{
    if(node == NULL){
        LOG_ERROR("%s\n.", "Node is null");
        exit(3);
    }

    printf("[ ");
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
    printf("]\n");
}
