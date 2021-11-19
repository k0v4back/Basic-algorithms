#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

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
void free_node(struct node * node);

struct node * fill_node(struct node * node, uint8_t * format, ...);
struct node * delete_node(struct node * node); 
void print_node(struct node * node);

int main(int argc, char **argv)
{
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

void free_node(struct node * node)
{
    struct node *node_ptr = NULL;

    while(node != NULL)
    {
        node_ptr = node->next;
        free(node);
        node = node_ptr;
    }
}

