#include <iostream>

using namespace std;

#include "simple_linked_list.h"

Person::Person(string name, int age) {
    this->name = name;
    this->age = age;
    this->next = nullptr;

    if (first == nullptr) {
        first = this;
        current = first;
    } else {
        new_node = this;
        current->next = new_node;
        current = new_node;
    }
}

Person::~Person() {
    cout << "Delete " << name << endl;
}

string Person::GetName() const {
    return name;
}

int Person::GetAge() const {
    return age;
}

class Person* Person::GetNext() const {
    return next;
}

void Person::SetName(string name) {
    this->name = name;
}

void Person::SetAge(int age) {
    this->age = age;
}

void Person::SetNext(class Person* next) {
    this->next = next;
}

void Person::PrintNode(void) {
    cout << "Name: " << name << " " << "Age: " << age << endl;
}

void Person::PrintAllNodes(void) {
    current = first;

    while (current) {
        current->PrintNode();
        current = current->next;
    }
}

int main() {
    Person* p1 = new Person("Oliver", 30);
    Person* p2 = new Person("Arthur", 31);
    Person* p3 = new Person("Henry", 32);

    Person::PrintAllNodes();

    return 0;
}