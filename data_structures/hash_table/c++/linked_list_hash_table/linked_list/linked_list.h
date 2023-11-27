#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <iostream>

using namespace std;

template<typename T> class List {
public:
    List();
    ~List();

    void push_back(T data);
    void push_front(T data);
    void pop_back(void);
    void pop_front(void);
    void insert(T data, int index);
    void remove_at(int index);
    void clear(void);
    void print_nodes(void);
    T& operator[](const int index);

    int GetListSize(void);
private:
    template<typename U> class Node {
    public:
        U data;
        Node* next;

        Node(U data = U(), Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };

    int list_size;
    Node<T>* first;
};

#endif /* _LINKED_LIST_H_ */
