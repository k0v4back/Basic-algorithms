#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define LOG_ERROR(format, ...) \
        fprintf(stderr, format, __VA_ARGS__)

enum value_type_element
{
    _INIT_ELEM,
    _DECEMAL_ELEM,
    _REAL_ELEM,
    _STRING_ELEM,
};

union value_node
{
    int32_t decimal;
    double real;
    uint8_t *string;
};

struct node
{
    enum value_type_element type;
    union value_node value;
    struct node * next;
};

struct node * create_node(uint8_t * format, ...);
struct node * fill_node(struct node * node, uint8_t * format, ...);
struct node * delete_node(struct node * node); 
void print_node(struct node * node);
void free_all_nodes(struct node * node);

int main(int argc, char **argv)
{
    struct node * node = create_node("drs", 555, 1.23, "hello, world!");
    struct node * temp = fill_node(node, "d", 542);

    temp = fill_node(node, "ddddd", 1, 2, 3, 4, 5);
    temp = fill_node(node, "d", 6);
    print_node(node);

    temp = delete_node(temp);
    free(temp);

    print_node(node);
    free_all_nodes(node);

    return 0;
}

struct node * create_node(uint8_t * format, ...)
{
    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    struct node * node_ptr = new_node;

    new_node->next = NULL;
    new_node->type = _INIT_ELEM;
    union value_node value;

    va_list factor;
    va_start(factor, format);
    while(*format) //read each of symbols in loop
    {
        switch(*format)
        {
            case 'd': case 'i': //decimal
               value.decimal = va_arg(factor, int32_t);
               new_node = fill_node(new_node, "d", value.decimal);
               break;
            case 'r': case 'f': //real
               value.real = va_arg(factor, double);
               new_node = fill_node(new_node, "r", value.real);
               break;
            case 's':           //string
               value.string = va_arg(factor, uint8_t *);
               new_node = fill_node(new_node, "s", value.string);
              break; 
        }

        ++format;
    }
    va_end(factor);


    return new_node;
}

struct node * fill_node(struct node * node, uint8_t * format, ...)
{
    if(node == NULL){
        LOG_ERROR("%s\n.", "Node is null");
        return NULL;
    }

    /* go to end of nodes */
    while(node->next != NULL)
    {
        node = node->next;
    }
    
    union value_node value;
    va_list factor;
    va_start(factor, format);
    while(*format) //read each of symbols in loop
    {
        switch(*format)
        {
            case 'd': case 'i': //decimal
               value.decimal = va_arg(factor, int32_t);
               node->next = (struct node *)malloc(sizeof(struct node));
               node = node->next;
               node->type = _DECEMAL_ELEM;
               node->value.decimal = value.decimal;
               node->next = NULL;
               break;
            case 'r': case 'f': //real
               value.real = va_arg(factor, double);
               node->next = (struct node *)malloc(sizeof(struct node));
               node = node->next;
               node->type = _REAL_ELEM;
               node->value.real = value.real;
               node->next = NULL;
               break;
            case 's':           //string
               value.string = va_arg(factor, uint8_t *);
               node->next = (struct node *)malloc(sizeof(struct node));
               node = node->next;
               node->type = _STRING_ELEM;
               node->value.string = value.string;
               node->next = NULL;
              break; 
        }

        ++format;
    }
    va_end(factor);

    return node;
}

struct node * delete_node(struct node * node)
{
    if(node == NULL){
        LOG_ERROR("%s\n.", "Node is null");
        return NULL;
    }

    if(node->next == NULL)
        return node;

    struct node * prev_node = node;
    struct node * past_node = node->next;

    while(past_node->next != NULL)
    {
        prev_node = past_node;
        past_node = past_node->next;
    }
    prev_node->next = NULL;

    return past_node;
} 

void print_node(struct node * node)
{
    printf("[ ");
    
    while(node != NULL)
    {
        switch(node->type){
            case _DECEMAL_ELEM:
                printf("%d ", node->value.decimal);
                break;
            case _REAL_ELEM:
                printf("%lf ", node->value.real);
                break;
            case _STRING_ELEM:
                printf("'%s' ", node->value.string);
                break;
        }
        node = node->next;
    }
    printf("]\n");
}

void free_all_nodes(struct node * node)
{
    struct node *node_ptr = NULL;

    while(node != NULL)
    {
        node_ptr = node->next;
        free(node);
        node = node_ptr;
    }
}

