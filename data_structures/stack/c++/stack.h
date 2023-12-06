#ifndef _STACK_H_
#define _STACK_H_

class Stack {
public:
    Stack(int data);
    ~Stack();

    void pushNode(int data);
    void popNode(void);
    void printStack(void);
    void deleteStack(void);

    int data;
    class Stack* next;

    class Stack* first;
};

#endif /* _STACK_H_ */