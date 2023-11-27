#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <iostream>

using namespace std;

template<typename ListType>
class List {
public:
    List();
    ~List();

    void push_back(ListType data);
    void push_front(ListType data);
    void pop_back(void);
    void pop_front(void);
    void insert(ListType data, int index);
    void remove_at(int index);
    void clear(void);
    void print_nodes(void);
    ListType& operator[](const int index);

    int GetListSize(void);
private:
    template<typename NodeType>
    class Node {
    public:
        NodeType data;
        Node* next;

        Node(NodeType data = NodeType(), Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };

    int list_size;
    Node<ListType>* first;
};

#endif /* _LINKED_LIST_H_ */
