#include <iostream>

using namespace std;

#include "hash_table.h"

int main(void) {
    HashTab<int> ht(10);

    ht.setHashTab(1, 10);
    ht.setHashTab(1, 11);
    ht.setHashTab(1, 12);

    ht.setHashTab(57, 13);
    ht.setHashTab(57, 14);
    ht.setHashTab(50, 15);


    ht.setHashTab(59, 16);
    ht.setHashTab(59, 17);
    ht.setHashTab(59, 18);
    ht.setHashTab(59, 19);
    ht.setHashTab(59, 20);
    ht.setHashTab(59, 21);
    ht.setHashTab(59, 22);
    ht.setHashTab(59, 23);

    ht.printHashTab();

    return 0;
}