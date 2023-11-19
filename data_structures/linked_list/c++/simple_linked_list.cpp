#include <iostream>

using namespace std;

template<typename T> class List {
public:
    List();
    ~List();

    void push_back(T data);
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
    list.print_nodes();

    return 0;
}