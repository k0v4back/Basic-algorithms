#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "linked_list/linked_list.h"

enum value_type_element
{
    _DECEMAL_ELEM,
    _REAL_ELEM,
    _STRING_ELEM,
};

union value_hashtable_t {
    int64_t decimal;
    double real;
    uint8_t *string;
};

struct HashTab {
    struct {
        enum value_type_element key;
        enum value_type_element value;
    } type;
    size_t size; /* Count of elements in hash table */
    struct Node **node; /* Array of pointers to linked list */
};

struct HashTab *new_hashtab(size_t size, enum value_type_element key, enum value_type_element value);
void free_hashtab(struct HashTab *ht);

union value_hashtable_t get_hashtab(struct HashTab *ht, void *key);
void set_hashtab(struct HashTab *ht, void *key, void *value);
void del_hashtab(struct HashTab *ht, void *key);
_Bool in_hashtab(struct HashTab *ht, void *key);

void print_hashtab(struct HashTab *ht);

static uint32_t _strhash(uint8_t *str, size_t size);

int main(void)
{
    return 0;
}

struct HashTab *new_hashtab(size_t size, enum value_type_element key_type, enum value_type_element value_type)
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
    struct HashTab *hash_tab = (struct HashTab *)malloc(sizeof(*hash_tab));
    if (!hash_tab) {
        fprintf(stderr, "%s", "Cann't allocate memory for HashTab");
        exit(1);
    }

    /* Allocate memory for each node in linked list */
    hash_tab->node = (struct Node **)malloc(size * sizeof(**hash_tab->node));
    if (!hash_tab) {
        fprintf(stderr, "%s", "Cann't allocate memory for linked list node");
        exit(1);
    }

    /* Create first node for all elements inside hash table */
    for (i = 0; i < size; i++)
        *(hash_tab->node + i) = create_node(key_type, value_type);
    
    hash_tab->size = size;
    hash_tab->type.key = key_type;
    hash_tab->type.value = value_type;

    return hash_tab;
}

void free_hashtab(struct HashTab *ht)
{
    int i;

    /* Free memory of linked list nodes */
    for (i = 0; i < ht->size; i++)
        delete_node(ht->node[i]);
    
    /* Free memory of HashTab */
    free(ht->node);
    free(ht);
}

void set_hashtab(struct HashTab *ht, void *key, void *value)
{
    uint32_t hash;

    /* Check type of hash table key */
    switch (ht->type.key) {
        case _DECEMAL_ELEM:
            /* Calculate hash for decimal */
            hash = (uint32_t)key % ht->size;
            break;
        case _STRING_ELEM:
            /* Calculate hash for decimal */
            hash = _strhash((uint8_t *)key, ht->size);
            break;
    }

    current = ht->node[hash];
    create_node((int)key, (int)value);
}

void print_hashtab(struct HashTab *ht)
{
    uint32_t hash;
    int i;

    for (i = 0; i < ht->size; i++) {
        if (ht->node[i] == NULL)
            continue;
        
        /* Check type of hash table key */
        switch (ht->type.key) {
            case _DECEMAL_ELEM:
                /* Calculate hash for decimal */
                hash = ht->node[i]->key % ht->size;
                current = ht->node[hash];
                break;
            case _STRING_ELEM:
                /* Calculate hash for decimal */
                hash = _strhash(ht->node[i]->key, ht->size);
                current = ht->node[hash];
                break;
        }
        printf("%d = ", hash);
        print_all_nodes();
    }
}

static uint32_t _strhash(uint8_t *str, size_t size)
{
    uint32_t hash;

    for (hash = 0; *str != '\0'; str++)
        hash = *str + 31 * hash;

    return hash % size;
}