/*
 * Very simple linked list. Fillng two nodes and nothig elese
 */

#include <stdio.h>
#include <stdlib.h>

struct person
{
    char name[30];
    int age;
    struct person * next;
};

struct person * current;
struct person * new_node;
struct person * first;

struct person * create_node(void);
void fill_node(struct person *);
void print_node(struct person *);

int main(void)
{
    if(first == NULL)
    {
        first = create_node();
        current = first;
        fill_node(current);
    }
    
    new_node = create_node();
    current->next = new_node;
    current = new_node;
    fill_node(current);
    current->next = NULL;

    /* print nodes */
    puts("\n----------RESUT----------");
    print_node(first);
    print_node(first->next);
}

struct person * create_node(void)
{
    struct person * new_person;
    new_person = (struct person *)malloc(sizeof(struct person));

    return new_person;
}

void fill_node(struct person * node)
{
    puts("Enter person name:");
    scanf("%s", node->name);

    puts("Enter person age:");
    scanf("%d", &node->age);
}

void print_node(struct person * node)
{
    printf("Name:%s\nAge:%d\n", node->name, node->age);
}
