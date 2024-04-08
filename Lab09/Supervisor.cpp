/* Author: Andrew D'Angelo
   Date: 04/08/2024
   Description: This file defines a Supervisor class with proper getter and setter functions set forth by the lab prompt.
*/

#include "Supervisor.h"

// Constructor definition
Supervisor::Supervisor(std::string name, int id, int level, double payRate)
    : Employee(name, id), level(level), payRate(payRate) {}

// calcPay function definition
double Supervisor::calcPay(int hours) {
    return hours * payRate + 1000.00 * level;
}

// Getter and Setter functions
int Supervisor::getLevel() const {
    return level;
}

void Supervisor::setLevel(int level) {
    this->level = level;
}

double Supervisor::getPayRate() const {
    return payRate;
}

void Supervisor::setPayRate(double payRate) {
    this->payRate = payRate;
}
