/* Author: Andrew D'Angelo
   Date: 04/22/2024
   Description: This program declares a stack built on a Linked list foundation. Stacks are LIFO and have push, pop, peek and clear operations.
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

using namespace std;

/*
Define a template class named Node that uses a single generic type T and contains:
• A private member variable of type T to store the Node’s data
• A private Node pointer (using type T) to store the next Node in the chain
• A constructor that takes in a parameter of type T representing the data to be stored in
the Node
• Assigns the parameter’s value to the appropriate member variable
• Initialize the next Node pointer to nullptr
*/
template<typename T>
class Node {

//All member variables should be private
private:
    T data;
    Node<T>* next;

public:
    Node(T data) : data(data), next(nullptr) {}

    T getData() const { return data; }
    void setData(T newData) { data = newData; }

    Node<T>* getNext() const { return next; }
    void setNext(Node<T>* temp) { next = temp; }
};

/*
Define a class named EmptyStackException which contains:
• A private string member variable to store the error message
• A constructor that takes in a string parameter representing the action being performed
when the exception was generated
• Store a message in the member variable explaining that the stack was empty and
thus the specified action cannot be completed
• A function named what() that takes in no parameters and returns the string member
variable
*/
class EmptyStackException : public exception {
private:
    string message;

public:
    EmptyStackException(const string& action) : message("Sorry, the stack is empty and we cannot " + action + "!") {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

/*
Define a template class named Stack that uses a single generic type T and contains:
• A private Node pointer (using type T) to store the head Node
• A constructor that takes in no parameters and initializes the head Node to nullptr
• A function named push() that takes in one parameter of type T representing the data
to be added to the Stack, returns nothing, and should:
• Store the data in a new Node, and prepend the Node to the LinkedList
• A function named pop() that takes in no parameters, returns the data of type T at the
top of the Stack, and should:
• Check if the Stack is empty, and if so throw an EmptyStackException
passing in the function name as a string
• Otherwise, remove the Node from the front of the LinkedList, deallocate it, and
return the data in the Node
*/
template<typename T>
class Stack {
private:
    Node<T>* head;

public:
    Stack() : head(nullptr) {}

    ~Stack() {
        clear();
    }

    void push(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->setNext(head);
        head = newNode;
    }

    T pop() {
        if (!head) throw EmptyStackException("pop");
        Node<T>* temp = head;
        T data = temp->getData();
        head = head->getNext();
        delete temp;
        return data;
    }

    T peek() const {
        // Empty?
        if (!head) throw EmptyStackException("peek");
        return head->getData();
    }

    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->getNext();
            delete temp;
        }
    }

    void printStack() const {
        if (!head) {
            cout << endl;
            return;
        }
        Node<T>* current = head;
        while (current) {
            cout << current->getData();
            if (current->getNext()) cout << ", ";
            current = current->getNext();
        }
        cout << endl;
    }
};

#endif
