/* Author: Andrew D'Angelo
   Date: 04/08/2024
   Description: This file defines an employee class that stands as an abstract base class with basic information about an employee in the business.
*/

#include "Employee.h"
using namespace std;

// Constructor definition
Employee::Employee(std::string name, int id) : name(name), id(id) {}

// Getter and Setter definitions
string Employee::getName() const {
    return name;
}

void Employee::setName(std::string name) {
    this->name = name;
}

int Employee::getId() const {
    return id;
}

void Employee::setId(int id) {
    this->id = id;
}
