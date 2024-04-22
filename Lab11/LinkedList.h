#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

class Node
{
    private:
        string data;
        Node* next;

    public:
        Node(string data)
        {
            this->data = data;
            this->next = nullptr;
        }
        string getData()
        {
            return data;
        }
        void setData(string data)
        {
            this->data = data;
        }
        Node* getNext()
        {
            return next;
        }
        void setNext(Node* next)
        {
            this->next = next;
        }
};

class LinkedList
{
    private:
        Node* head;

    public:
        LinkedList()
        {
            head = nullptr;
        }

        void append(string data)
        {
            Node* temp = new Node(data);

            if(head == nullptr)
                head = temp;
            else
            {
                Node* current = head;

                while(current->getNext() != nullptr)
                    current = current->getNext();

                current->setNext(temp);
            }
        }
        int find(string data)
        {
            Node* current = head;
            int position = 0;

            while(current != nullptr)
            {
                if(current->getData() == data)
                    return position;
                else
                {
                    current = current->getNext();
                    position++;
                }
            }

            return -1;            
        }
        bool remove(string data)
        {
            if(head == nullptr)
                return false;
            else if(head->getData() == data)
            {
                Node* tempNode = head;
                head = head->getNext();
                delete tempNode;
                return true;
            }

            Node* previous = head;
            Node* current = head->getNext();

            while(current != nullptr)
            {
                if(current->getData() == data)
                {
                    Node* tempNode = current;
                    previous->setNext(current->getNext());
                    delete tempNode;
                    return true;
                }
                else
                {
                    current = current->getNext();
                    previous = previous->getNext();
                }
            }

            return false;
        }
        void printLinkedList()
        {
            Node* current = head;
            while(current != nullptr)
            {
                if(current->getNext() != nullptr)
                    cout << current->getData() << " -> ";
                else
                    cout << current->getData() << endl;

                current = current->getNext();
            }
        }
};










#endif