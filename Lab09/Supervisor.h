/* Author: Andrew D'Angelo
   Date: 04/08/2024
   Description: This header file declares a supervisor class that inherits the main attributes from the employee class.
*/

#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "Employee.h"
using namespace std;

class Supervisor : public Employee {
private:
    int level;
    double payRate;

public:
    // Constructor declaration
    Supervisor(string name, int id, int level, double payRate);

    // Override calcPay function
    double calcPay(int hours) override;

    // Getter and Setter functions
    int getLevel() const;
    void setLevel(int level);
    double getPayRate() const;
    void setPayRate(double payRate);
};

#endif
