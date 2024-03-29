#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "linked_list/linked_list.h"

struct HashTab {
    struct {
        enum value_type_element key;
        enum value_type_element value;
    } type;
    size_t size; /* Count of elements in hash table */
    struct Node** pp_node; /* Array of pointers to linked list */
};

struct HashTab* new_hashtab(size_t size, enum value_type_element key, enum value_type_element value);
void free_hashtab(struct HashTab* ht);

struct Node* get_hashtab(struct HashTab* ht, void* key_value);
void set_hashtab(struct HashTab* ht, void* key, void* value);
void del_hashtab(struct HashTab* ht, void* key);
_Bool in_hashtab(struct HashTab* ht, void* key);

void print_hashtab(struct HashTab* ht);

static uint32_t _strhash(uint8_t* str, size_t size);

int main(void)
{
    struct HashTab* hashtab = new_hashtab(5, _STRING_ELEM, _DECEMAL_ELEM);

    set_hashtab(hashtab, (void*)"A", (void*)111);
    set_hashtab(hashtab, (void*)"B", (void*)222);
    set_hashtab(hashtab, (void*)"C", (void*)333);
    set_hashtab(hashtab, (void*)"C", (void*)444);
    set_hashtab(hashtab, (void*)"C", (void*)555);
    print_hashtab(hashtab);


    if (in_hashtab(hashtab, "C") == true)
        printf("TRUE\n");
    else
        printf("FALSE\n");

    printf("%ld\n", get_hashtab(hashtab, "C")->data.value.decimal);


    free_hashtab(hashtab);

    return 0;
}

struct HashTab* new_hashtab(size_t size, enum value_type_element key_type, enum value_type_element value_type)
{
    int i;

    /* Check correct key type */
    switch (key_type) {
        case _DECEMAL_ELEM:
            break;
        case _STRING_ELEM:
            break;
        default:
            fprintf(stderr, "%s", "Key type doesn't exist");
            exit(1);
    }

    /* Check correct value type */
    switch (value_type) {
        case _DECEMAL_ELEM:
            break;
        case _REAL_ELEM:
            break;
        case _STRING_ELEM:
            break;
        default:
            fprintf(stderr, "%s", "Value type doesn't exist");
            exit(1);
    }
    
    /* Create hash table */
    struct HashTab* ht = (struct HashTab*)malloc(sizeof(struct HashTab));
    if (!ht) {
        fprintf(stderr, "%s", "Cann't allocate memory for HashTab");
        exit(1);
    }

    /* Allocate memory for each node in linked list */
    ht->pp_node = (struct Node**)malloc(size * sizeof(struct Node));
    if (!ht->pp_node) {
        fprintf(stderr, "%s", "Cann't allocate memory for linked list node");
        exit(1);
    }

    /* Create first node for all elements inside hash table */
    for (i = 0; i < size; i++)
        ht->pp_node[i] = create_node(key_type, value_type);
    
    ht->size = size;
    ht->type.key = key_type;
    ht->type.value = value_type;

    return ht;
}

void free_hashtab(struct HashTab* ht)
{
    int i;

    /* Free memory of linked list nodes */
    for (i = 0; i < ht->size; i++)
        delete_node(ht->pp_node[i], ht->pp_node[i]);
    
    /* Free memory of HashTab */
    free(ht->pp_node);
    free(ht);
}

struct Node* get_hashtab(struct HashTab* ht, void* key_value)
{
    uint32_t hash;

    /* Check type of hash table key */
    switch (ht->type.key) {
        case _DECEMAL_ELEM:
            /* Calculate hash for decimal */
            hash = (uint64_t)key_value % ht->size;
            break;
        case _STRING_ELEM:
            /* Calculate hash for decimal */
            hash = _strhash((uint8_t*)key_value, ht->size);
            break;
    }

    return get_node(ht->pp_node[hash], ht->type.key, key_value);
}

void set_hashtab(struct HashTab* ht, void* key, void* value)
{
    uint32_t hash;

    /* Check type of hash table key */
    switch (ht->type.key) {
        case _DECEMAL_ELEM:
            /* Calculate hash for decimal */
            hash = (uint64_t)key % ht->size;
            break;
        case _STRING_ELEM:
            /* Calculate hash for decimal */
            hash = _strhash((uint8_t*)key, ht->size);
            break;
    }

    fill_last_node(ht->pp_node[hash], key, value);
}

_Bool in_hashtab(struct HashTab* ht, void* key)
{
    uint32_t hash;

    /* Check type of hash table key */
    switch (ht->type.key) {
        case _DECEMAL_ELEM:
            /* Calculate hash for decimal */
            hash = (uint64_t)key % ht->size;
            break;
        case _STRING_ELEM:
            /* Calculate hash for decimal */
            hash = _strhash((uint8_t*)key, ht->size);
            break;
    }

    return in_list(ht->pp_node[hash], key);
}

void print_hashtab(struct HashTab* ht)
{
    uint32_t hash;
    int i;

    for (i = 0; i < ht->size; i++) {       
        /*
        switch (ht->type.key) {
            case _DECEMAL_ELEM:
                hash = ht->pp_node[i]->data.key.decimal % ht->size;
                break;
            case _STRING_ELEM:
                hash = _strhash((uint8_t*)ht->pp_node[i]->data.key.string, ht->size);
                break;
        }
        */
        printf("{ ");
        print_all_nodes(ht->pp_node[i]);
        printf("}\n");
    }
}

static uint32_t _strhash(uint8_t* str, size_t size)
{
    uint32_t hash;

    for (hash = 0; *str != '\0'; str++)
        hash = *str + 31 * hash;

    return hash % size;
}