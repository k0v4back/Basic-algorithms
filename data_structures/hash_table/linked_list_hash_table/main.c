#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "linked_list/linked_list.h"

union value_hashtable_t {
    int64_t decimal;
    double real;
    uint8_t* string;
};

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

union value_hashtable_t get_hashtab(struct HashTab* ht, void* key);
void set_hashtab(struct HashTab* ht, void* key, void* value);
void del_hashtab(struct HashTab* ht, void* key);
_Bool in_hashtab(struct HashTab* ht, void* key);

void print_hashtab(struct HashTab* ht);

static uint32_t _strhash(uint8_t* str, size_t size);

int main(void)
{
    struct HashTab* hashtab = new_hashtab(6, _DECEMAL_ELEM, _DECEMAL_ELEM);

    set_hashtab(hashtab, 1, (void*)555);
    set_hashtab(hashtab, 1, (void*)666);
    set_hashtab(hashtab, 1, (void*)777);
    set_hashtab(hashtab, 2, (void*)888);
    set_hashtab(hashtab, 3, (void*)999);
    set_hashtab(hashtab, 4, (void*)999);
    print_hashtab(hashtab);

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
        ht->pp_node[i] = create_node((int)key_type, (int)value_type);
    
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

void set_hashtab(struct HashTab* ht, void* key, void* value)
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
            hash = _strhash((uint8_t*)key, ht->size);
            break;
    }

    fill_last_node(ht->pp_node[hash], (int)key, (int)value);
}

void print_hashtab(struct HashTab* ht)
{
    uint32_t hash;
    int i;

    for (i = 0; i < ht->size; i++) {
        //if (ht->pp_node[i]->next == NULL && ht->pp_node[i]->previous == NULL)
            //continue;
        if (i == 0)
            continue;
        
        /* Check type of hash table key */
        switch (ht->type.key) {
            case _DECEMAL_ELEM:
                /* Calculate hash for decimal */
                hash = ht->pp_node[i]->key % ht->size;
                break;
            case _STRING_ELEM:
                /* Calculate hash for decimal */
                hash = _strhash((uint8_t*)ht->pp_node[i]->key, ht->size);
                break;
        }
        printf("{ ");
        print_all_nodes(ht->pp_node[hash]);
        printf(" }\n");
    }
}

static uint32_t _strhash(uint8_t* str, size_t size)
{
    uint32_t hash;

    for (hash = 0; *str != '\0'; str++)
        hash = *str + 31 * hash;

    return hash % size;
}