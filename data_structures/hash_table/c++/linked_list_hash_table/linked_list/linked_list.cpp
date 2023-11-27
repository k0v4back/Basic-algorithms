#include <iostream>

#include "linked_list.h"

using namespace std;

template<typename T> List<T>::List() {
    list_size = 0;
    first = nullptr;
}

template<typename T> List<T>::~List() {
    clear();
}

template<typename T> void List<T>::push_back(T data) {
    if (!first) {
        first = new Node<T>(data);
    } else {
        Node<T>* current = first;

        while (current->next)
            current = current->next;

        current->next = new Node<T>(data);
    }

    list_size++;
}

template<typename T> void List<T>::push_front(T data) {
    Node<T>* current = first;

    first = new Node<T>(data);
    first->next = current;

    list_size++;
}

template<typename T> void List<T>::pop_back(void) {
    Node<T>* current = first;
    Node<T>* deleteNode = nullptr;

    for (int i = 0; i < list_size - 2; i++) {
        current = current->next;
    }

    deleteNode = current->next;
    current->next = deleteNode->next;
    delete deleteNode;

    list_size--;
}

template<typename T> void List<T>::pop_front(void) {
    Node<T>* current = first;

    first = first->next;
    delete current;

    list_size--;
}

template<typename T> void List<T>::insert(T data, int index) {
    Node<T>* current = first;
    Node<T>* new_node = nullptr;

    if (index == 0)
        push_front(data);

    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    new_node = new Node<T>(data, current->next);
    current->next = new_node;
    list_size++;
}

template<typename T> void List<T>::remove_at(int index) {
    Node<T>* current = first;
    Node<T>* deleteNode = nullptr;

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

template<typename T> void List<T>::clear(void) {
    while (list_size)
        pop_front();
}

template<typename T> void List<T>::print_nodes(void) {
    Node<T>* current = first;

    while (current) {
        cout << current->data << endl;
        current = current->next;
    }
}

template<typename T> T& List<T>::operator[](const int index) {
    Node<T>* current = first;
    int i = 0;

    while(current) {
        if (i == index)
            return current->data;
        current = current->next;
        i++;
    }
}

template<typename T> int List<T>::GetListSize(void) {
    return list_size;
}