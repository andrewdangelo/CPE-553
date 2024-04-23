/* Author: Andrew D'Angelo
   Date: 04/22/2024
   Description: This program declared a queue built on a Linked list foundation. Queues are FIFO and have enqueue, dequeue, peek and clear operations.
*/

#ifndef QUEUE_H
#define QUEUE_H

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
• Appropriate getter and setter functions
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

// Define the EmptyQueueException class
class EmptyQueueException : public exception {
private:
    string message;

public:
    EmptyQueueException(const string& action) : message("Sorry, the queue is empty and we cannot " + action + "!") {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Define the Queue template class
template<typename T>
class Queue {

// Private pointers to the head and tail of type T.
private:
    Node<T>* head;
    Node<T>* tail;

public:
    //A constructor that takes in no parameters and initializes the head and tail Nodes to nullptr.
    Queue() : head(nullptr), tail(nullptr) {}

    ~Queue() {
        clear();
    }

    /*
    A function named enqueue() that takes in one parameter of type T representing the
    data to be added to the Queue, returns nothing, and should:
        • Store the data in a new Node, and append the Node to the LinkedList
        o Note, pay attention to the case where the LinkedList is empty, versus if it
        contains at least one element, and how that affects updating the head
        and tail Nodes
    */
    void enqueue(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (!tail) {
            head = tail = newNode; 
        } else {
            tail->setNext(newNode);
            tail = newNode;
        }
    }

    /*
    A function named dequeue() that takes in no parameters, returns the data of type T
    at the top of the Queue, and should:
        • Check if the Queue is empty, and if so raise an EmptyQueueException
        passing in the function name as a string
        • Otherwise, remove the Node from the front of the LinkedList, deallocate it, and
        return the data in the Node
        o Note, pay attention to the case where the LinkedList contains exactly one
        element, versus if it contains more than one element, and how that
        affects updating the head and tail Nodes
    */
    T dequeue() {
        if (!head) throw EmptyQueueException("dequeue");
        Node<T>* temp = head;
        T data = temp->getData();
        head = head->getNext();
        if (!head) tail = nullptr;
        delete temp;
        return data;
    }

    /*
    A function named peek() that takes in no parameters, returns the data of type T at
    the front of the Queue, and should:
        • Check if the Queue is empty, and if so raise an EmptyQueueException
        passing in the function name as a string
        • Otherwise, return the data in the Node at the front of the LinkedList
    */
    T peek() const {
        //Empty?
        if (!head) throw EmptyQueueException("peek");
        return head->getData();
    }

    /*
    A function named clear() that takes in no parameters, returns nothing, and removes
    all Nodes from the LinkedList
        • Don’t forget to deallocate each Node!
        • Also, don’t forget to update both the head and tail Nodes!
    */
    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->getNext();
            delete temp;
        }
        tail = nullptr;
    }

/*
A function named clear() that takes in no parameters, returns nothing, and removes
all Nodes from the LinkedList
• Don’t forget to deallocate each Node!
• Also, don’t forget to update both the head and tail Nodes!
*/
    void printQueue() const {
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
