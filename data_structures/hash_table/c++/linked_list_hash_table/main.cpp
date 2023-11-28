#include <iostream>

using namespace std;

#include "hash_table.h"

int main(void) {
    HashTab<int> ht(10);

    ht.setHashTab(1, 10);
    ht.setHashTab(1, 11);
    ht.setHashTab(1, 12);

    ht.setHashTab(2, 20);
    ht.setHashTab(3, 30);
    ht.setHashTab(4, 40);
    ht.setHashTab(5, 50);

    return 0;
}