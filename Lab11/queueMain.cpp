/* Author: Andrew D'Angelo
   Date: 04/22/2024
   Description: This program fines a queue built on a Linked list foundation. Queues are FIFO and have enqueue, dequeue, peek and clear operations.
*/

#include "Queue.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    Queue<string> myQueue;
    ifstream file("inputQueue.txt");
    string line;
    
    //Handle operations from file
    while (getline(file, line)) {
        istringstream queueFile(line);
        string operation, value;
        queueFile >> operation;

        if (operation == "enqueue") {
            getline(queueFile, value);
            myQueue.enqueue(value);
            cout << "Enqueued " << value << endl;
        } else if (operation == "dequeue") {
            try {
                string dequeuedValue = myQueue.dequeue();
                cout << "Dequeued " << dequeuedValue << endl;
            } catch (const EmptyQueueException& e) {
                cout << e.what() << endl;
            }
        } else if (operation == "peek") {
            try {
                string frontValue = myQueue.peek();
                cout << "Peeked at " << frontValue << endl;
            } catch (const EmptyQueueException& e) {
                cout << e.what() << endl;
            }
        } else if (operation == "clear") {
            myQueue.clear();
            cout << "Cleared out the queue." << endl;
        } else if (operation == "print") {
            myQueue.printQueue();
        }
    }
    file.close();
    return 0;
}
