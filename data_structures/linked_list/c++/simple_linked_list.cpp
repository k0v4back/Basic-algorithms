#include <iostream>

using namespace std;

template<typename T> class List {
public:
    List();
    ~List();

    void push_back(T data);
    void push_front(T data);
    void pop_front(void);
    void insert(T data, int index);
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


template<typename T> List<T>::List() {
    list_size = 0;
    first = nullptr;
}

template<typename T> List<T>::~List() {
    clear();
}

template<typename T> void List<T>::push_back(T data) {
    if (first == nullptr) {
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

template<typename T> void List<T>::pop_front(void) {
    Node<T>* current = first;

    first = first->next;
    delete current;

    list_size--;
}

template<typename T> void List<T>::insert(T data, int index) {
    //Node<T>* new_node = new Node<T>(data);
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


int main(void) {
    List<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    cout << list[1] << endl;
    cout << "----------------------" << endl;
    list.push_front(0);
    list.push_front(-1);
    list.insert(9, 2);
    list.print_nodes();

    cout << "Count of elements: " << list.GetListSize() << endl;
    list.clear();
    cout << "Count of elements: " << list.GetListSize() << endl;

    return 0;
}