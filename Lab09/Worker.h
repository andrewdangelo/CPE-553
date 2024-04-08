/* Author: Andrew D'Angelo
   Date: 04/08/2024
   Description: This header file declares a worker class that inherits the main attributes from the employee class.
*/

#ifndef WORKER_H
#define WORKER_H

#include "Employee.h"
using namespace std;

class Worker : public Employee {
private:
    int shift;
    double payRate;

public:
    // Constructor declaration
    Worker(string name, int id, int shift, double payRate);

    // Override calcPay function
    double calcPay(int hours) override;

    // Getter and Setter functions
    int getShift() const;
    void setShift(int shift);
    double getPayRate() const;
    void setPayRate(double payRate);
};


#endif