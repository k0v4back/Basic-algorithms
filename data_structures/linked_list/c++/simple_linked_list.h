#ifndef _SIMPLE_LINKED_LIST_H_
#define _SIMPLE_LINKED_LIST_H_

#include <iostream>

using namespace std;

class Person {
private:
    string name;
    int age;
    class Person* next;
public:
    Person(string name, int age);
    ~Person();

    string GetName() const;
    int GetAge() const;
    class Person* GetNext() const;

    void SetName(string name);
    void SetAge(int age);
    void SetNext(class Person* next);

    class Person* CreateNode(void);
    void FillNode(class Person* node);
    void PrintNode(class Person* node);

    void PrintNode(void);
    static void PrintAllNodes(void);
};

class Person* current;
class Person* new_node;
class Person* first;

#endif // _SIMPLE_LINKED_LIST_H_