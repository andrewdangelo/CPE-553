/* Author: Andrew D'Angelo
   Date: 04/08/2024
   Description: This file defines a worker class that inherits features from the emplyee class.
*/

#include "Worker.h"

// Constructor definition
Worker::Worker(std::string name, int id, int shift, double payRate)
    : Employee(name, id), shift(shift), payRate(payRate) {}

// calcPay function definition
double Worker::calcPay(int hours) {
    return hours * payRate;
}

// Getter and Setter functions
int Worker::getShift() const {
    return shift;
}

void Worker::setShift(int shift) {
    this->shift = shift;
}

double Worker::getPayRate() const {
    return payRate;
}

void Worker::setPayRate(double payRate) {
    this->payRate = payRate;
}