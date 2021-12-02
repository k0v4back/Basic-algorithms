#include <stdio.h>

#include "linked_list.h"

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
