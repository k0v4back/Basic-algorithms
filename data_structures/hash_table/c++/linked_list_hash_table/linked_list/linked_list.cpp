#include <iostream>

#include "linked_list.h"

using namespace std;

template<typename ListType>
List<ListType>::List() {
    list_size = 0;
    first = nullptr;
}

template<typename ListType>
List<ListType>::~List() {
    clear();
}

template<typename ListType>
void List<ListType>::push_back(ListType data) {
    if (!first) {
        first = new Node<ListType>(data);
    } else {
        Node<ListType>* current = first;

        while (current->next)
            current = current->next;

        current->next = new Node<ListType>(data);
    }

    list_size++;
}

template<typename ListType>
void List<ListType>::push_front(ListType data) {
    Node<ListType>* current = first;

    first = new Node<ListType>(data);
    first->next = current;

    list_size++;
}

template<typename ListType>
void List<ListType>::pop_back(void) {
    Node<ListType>* current = first;
    Node<ListType>* deleteNode = nullptr;

    for (int i = 0; i < list_size - 2; i++) {
        current = current->next;
    }

    deleteNode = current->next;
    current->next = deleteNode->next;
    delete deleteNode;

    list_size--;
}

template<typename ListType>
void List<ListType>::pop_front(void) {
    Node<ListType>* current = first;

    first = first->next;
    delete current;

    list_size--;
}

template<typename ListType>
void List<ListType>::insert(ListType data, int index) {
    Node<ListType>* current = first;
    Node<ListType>* new_node = nullptr;

    if (index == 0)
        push_front(data);

    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    new_node = new Node<ListType>(data, current->next);
    current->next = new_node;
    list_size++;
}

template<typename ListType>
void List<ListType>::remove_at(int index) {
    Node<ListType>* current = first;
    Node<ListType>* deleteNode = nullptr;

    if (index == 0) {
        pop_front();
    } else {
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        deleteNode = current->next;
        current->next = deleteNode->next;

        delete deleteNode;
        list_size--;
    }
}

template<typename ListType>
void List<ListType>::clear(void) {
    while (list_size)
        pop_front();
}

template<typename ListType>
void List<ListType>::print_nodes(void) {
    Node<ListType>* current = first;

    while (current) {
        cout << current->data << endl;
        current = current->next;
    }
}

template<typename ListType>
ListType& List<ListType>::operator[](const int index) {
    Node<ListType>* current = first;
    int i = 0;

    while(current) {
        if (i == index)
            return current->data;
        current = current->next;
        i++;
    }
}

template<typename ListType>
int List<ListType>::GetListSize(void) {
    return list_size;
}