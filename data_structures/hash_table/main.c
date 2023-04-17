#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "linked_list.h"

struct hash_table
{
    struct
    {
        enum value_type_element key;
        enum value_type_element value;
    } type;
    size_t size;
    struct node ** table; 
};

struct hash_table * new_hash_table(size_t size, enum value_type_element key, enum value_type_element value);
struct hash_table * get_hash_table(struct hash_table * hash_table, void * key);
void free_hash_table(struct hash_table * hash_table);
void print_hash_table(struct hash_table * hash_table);
void fill_hash_table(struct hash_table * hash_table, void * key, void * value);
void del_hash_table(struct hash_table * hash_table, void * key);
uint32_t get_hash(uint8_t * str, size_t size); 

int main(int argc, char **argv)
{
    struct hash_table * hash_table = new_hash_table(1000, _STRING_ELEM, _DECEMAL_ELEM);
    fill_hash_table(hash_table, enum value_type_element key, void *value)

    free_hash_table(hash_table);

    return 0;
}

struct hash_table * new_hash_table(size_t size, enum value_type_element key, enum value_type_element value)
{
    switch(key){
        case _DECEMAL_ELEM:
            break;
        case _STRING_ELEM:
            break;
        default:
            LOG_ERROR("%s\n.", "Key type not supported");
            return NULL;
    }
    
    switch(value){
        case _DECEMAL_ELEM:
            break;
        case _REAL_ELEM:
            break;
        case _STRING_ELEM:
            break;
        default:
            LOG_ERROR("%s\n.", "Value type not supported");
            return NULL;
    }

    struct hash_table * hash_table = (struct hash_table *)malloc(sizeof(struct hash_table));
    hash_table->table = (struct node **)malloc(size * sizeof(struct node));

    for(unsigned i = 0; i < size; i++){
        hash_table->table[i] = node_create(0, key);
    }
    hash_table->size = size;
    hash_table->type.key = key;
    hash_table->type.value = value;

    return hash_table;
}

void free_hash_table(struct hash_table * hash_table)
{
    for(unsigned i = 0; i < hash_table->size; i++){
        delete_all_nodes(hash_table->table[i]); 
    }
    free(hash_table->table);
    free(hash_table);
}

void print_hash_table(struct hash_table * hash_table)
{
    uint32_t hash;
    for(unsigned i = 0; i < hash_table->size; i++){
       if(hash_table->table[i]->data == NULL)
          continue;
       switch(hash_table->type.key){
          case _DECEMAL_ELEM:
              hash = (int)(hash_table->table[i]->data) % hash_table->size;
              break;
          case _STRING_ELEM:
              hash = get_hash(hash_table->table[i]->data, hash_table->size);
       } 
       printf("\t%d => ", hash);
       print_all_nodes(hash_table->table[i]);
    }
}

void fill_hash_table(struct hash_table * hash_table, void * key, void * value)
{
    uint32_t hash;
    switch(hash_table->type.key){
        case _DECEMAL_ELEM:
            hash = (uint64_t)key % hash_table->size;
            fill_node_last(hash_table->table[hash], value, _DECEMAL_ELEM);
        break;
        case _STRING_ELEM:
            hash = get_hash((uint8_t*)key, hash_table->size);
            fill_node_last(hash_table->table[hash], value, _STRING_ELEM);
        break;
    }
}

uint32_t get_hash(uint8_t * str, size_t size)
{
    uint32_t hash_val;
    for(hash_val = 0; *str != '\0'; ++str){
         hash_val = *str + 31 * hash_val;
    }

    return hash_val % size;
} 
