/* Author: Andrew D'Angelo
   Date: 04/08/2024
   Description: This program simulates an application to help small businesses keep track of their employees with information such as pay rate, hours, etc.
*/

#include <iostream>
#include <vector>
#include "Employee.h"
#include "Worker.h"
#include "Supervisor.h"

using namespace std;

/**
 * @brief Calculates and determines the total pay of for all employees of the business.
 * @param employees array of Employee pointers.
 * @param size interger representing the size of the array.
 * @return returns the total pay of the employees of the business.
*/
double calcTotalPay(Employee** employees, int size) {
    double pay = 0.0;
    for (int i = 0; i < size; ++i) {
        pay += employees[i]->calcPay(40);
    }
    return pay;
}

/**
 * @brief Outputs all of the employee information with appropriate labels using a loop.
 * @param employees array of Employee pointers
 * @param size interger representing the size of the array.
*/
void listEmployees(Employee** employees, int size) {
    for (int i = 0; i < size; ++i) {
        /*
        Be sure to use dynamic_cast<> to determine the class type for each object in the
        array so that your program outputs the appropriate information for the appropriate
        object type.
        */
        Worker* worker = dynamic_cast<Worker*>(employees[i]);
        Supervisor* supervisor = dynamic_cast<Supervisor*>(employees[i]);
        
        if (worker) {
            cout << "Name: " << worker->getName() << endl;
            cout << "ID: " << worker->getId() << endl;
            cout << "Pay Rate: $" << worker->getPayRate() << endl;
            cout << "Shift: " << (worker->getShift() == 1 ? "Day Shift" : "Night Shift") << endl;
        } else if (supervisor) {
            cout << "Name: " << supervisor->getName() << endl;
            cout << "ID: " << supervisor->getId() << endl;
            cout << "Pay Rate: $" << supervisor->getPayRate() << endl;
            cout << "Level: " << supervisor->getLevel() << endl;
        }
        cout << endl;
    }
}

int main() {

     // Prompt the user for how many employees they wish to add, and store that in a local variable
    int numOfEmployees;
    cout << "How many employees would you like to add: ";
    cin >> numOfEmployees;
    cin.ignore();

    // Create an array of Employee pointers, with a size specified by the user
    Employee** employees = new Employee*[numOfEmployees];


    for (int i = 0; i < numOfEmployees; ++i) {
        string type, name;
        int id, shiftOrLevel;
        double payRate;

        // Prompt the user if they wish to add a Supervisor or a Worker.
        cout << "Would you like to add a worker or a supervisor: ";
        getline(cin, type);

        if (type == "worker") {
            cout << "Please enter the name of the worker: ";
            getline(cin, name);
            cout << "Please enter the id of the worker: ";
            cin >> id;
            cout << "Please enter the pay rate of the worker: ";
            cin >> payRate;
            cout << "Please enter the shift of the worker (1 for day, 2 for night): ";
            cin >> shiftOrLevel;
            cin.ignore();

            employees[i] = new Worker(name, id, shiftOrLevel, payRate);
        } else if (type == "supervisor") {
            cout << "Please enter the name of the supervisor: ";
            getline(cin, name);
            cout << "Please enter the id of the supervisor: ";
            cin >> id;
            cout << "Please enter the pay rate of the supervisor: ";
            cin >> payRate;
            cout << "Please enter the level of the supervisor: ";
            cin >> shiftOrLevel;
            cin.ignore();

            employees[i] = new Supervisor(name, id, shiftOrLevel, payRate);
        } else {
            cout << "Invalid input. Please enter either 'worker' or 'supervisor'." << endl;
            --i;
            continue;
        }
    }

    // Call the listEmployees() function, and pass it the Employee pointer array and the size of the array
    listEmployees(employees, numOfEmployees);

    /*
    Call the calcTotalPay() function, pass it the Employee pointer array and the size
    of the array, and output the total pay for all employees with an appropriate message.
    */
    double pay = calcTotalPay(employees, numOfEmployees);
    cout << "The total cost of all of the worker's pay is $" << pay << "." << endl;

    // IMPORTANT: Clean up dynamic memory
    for (int i = 0; i < numOfEmployees; ++i) {
        delete employees[i];
    }
    delete[] employees;

    return 0;
}
