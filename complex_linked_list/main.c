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

static struct node * current;
static struct node * new_node;
static struct node * first;

struct node * create_node(void);
struct node * fill_node(uint8_t * format, ...);
struct node * check_first_node_exist(void);
void print_all_nodes(void);
void delete_last_node(void); 
void free_all_nodes(void);

int main(int argc, char **argv)
{
    struct node * temp = NULL;

    temp = fill_node("sdrdd", "HELLO", 1, 74.3, 2, 3);

    print_all_nodes();
    free_all_nodes();

    return 0;
}

struct node * create_node(void)
{
    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        LOG_ERROR("%s\n.", "Can not allocate memory for new node");
        exit(1);
    }
        
    return new_node;
}

struct node * fill_node(uint8_t * format, ...)
{
    while(current != NULL)
    {
        current = current->next;
    }

    union value_node value;
    va_list factor;
    va_start(factor, format);
    while(*format) //read each of symbols in loop
    {
        current = check_first_node_exist();
        printf("%s, %p \n", "HELLO", &current);
        switch(*format)
        {
            case 'd': case 'i': //decimal
               value.decimal = va_arg(factor, int32_t);
               current->type = _DECEMAL_ELEM;
               current->value.decimal = value.decimal;
               current->next = NULL;
               break;
            case 'r': case 'f': //real
               value.real = va_arg(factor, double);
               current->type = _REAL_ELEM;
               current->value.real = value.real;
               current->next = NULL;
               break;
            case 's':           //string
               value.string = va_arg(factor, uint8_t *);
               current->type = _STRING_ELEM;
               current->value.string = value.string;
               current->next = NULL;
              break; 
        }
        ++format;
    }
    va_end(factor);

    return current;
}

void delete_last_node(void)
{
    if(first == NULL){
        LOG_ERROR("%s\n.", "First node does not exist");
        exit(2);
    }

    current = first;
    while(current != NULL)
    {
        current = current->next;
    }

    free(current);
} 

void print_all_nodes(void)
{
    current = first;
    
    printf("[ ");
    while(current != NULL)
    {
        switch(current->type){
            case _DECEMAL_ELEM:
                printf("%d ", current->value.decimal);
                break;
            case _REAL_ELEM:
                printf("%lf ", current->value.real);
                break;
            case _STRING_ELEM:
                printf("'%s' ", current->value.string);
                break;
        }
        current = current->next;
    }
    printf("]\n");
}

struct node * check_first_node_exist(void)
{
    if(first == NULL)
    {
        first = create_node();
        current = first;
    }
    else
    {
        new_node = create_node();
        current = new_node;
    }

    return current;
}

void free_all_nodes(void)
{
    struct node * next_node = NULL;
    current = first;

    while(current != NULL)
    {
        next_node = current->next;
        free(next_node);
        current = next_node;
    }
}

