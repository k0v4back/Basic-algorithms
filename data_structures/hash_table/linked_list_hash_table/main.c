#include <stdio.h>
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

struct hashtab {
    struct {
        enum value_type_element key;
        enum value_type_element value;
    } type;
    size_t size; /* Count of elements in hash table */
};

struct hashtab *new_hashtab(size_t size, enum value_type_element key, enum value_type_element value);
void free_hashtab(struct hashtab *ht);

union value_hashtable_t get_hashtab(struct hashtab *ht, void *key);
void set_hashtab(struct hashtab *ht, void *key, void *value);
void del_hashtab(struct hashtab *ht, void *key);
_Bool in_hashtab(struct hashtab *ht, void *key);

void print_hashtab(struct hashtab *ht);

int main(void)
{
    return 0;
}