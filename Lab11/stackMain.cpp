/* Author: Andrew D'Angelo
   Date: 04/22/2024
   Description: This program defines a stack built on a Linked list foundation. Stacks are LIFO and have push, pop, peek and clear operations.
*/

#include "Stack.h"
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    Stack<int> myStack;
    ifstream file("inputStack.txt");
    string line;
    
    while (getline(file, line)) {
        istringstream stackFile(line);
        string operation;
        stackFile >> operation;

        if (operation == "push") {
            int value;
            stackFile >> value;
            myStack.push(value);
            cout << "Pushed " << value << endl;
        } else if (operation == "pop") {
            try {
                int poppedValue = myStack.pop();
                cout << "Popped " << poppedValue << endl;
            } catch (const EmptyStackException& e) {
                cout << e.what() << endl;
            }
        } else if (operation == "peek") {
            try {
                int top = myStack.peek();
                cout << "Peeked at " << top << endl;
            } catch (const EmptyStackException& e) {
                cout << e.what() << endl;
            }
        } else if (operation == "clear") {
            myStack.clear();
            cout << "Cleared out the stack." << endl;
        } else if (operation == "print") {
            myStack.printStack();
        }
    }
    file.close();
    return 0;
}
