/* Author: Andrew D'Angelo
   Date: 04/08/2024
   Description: This header file declares and employee class.
*/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee{
    protected:
        string name;
        int id;

    public:
        Employee(string name, int id);

        virtual double calcPay(int hours) = 0;

        string getName() const;
        void setName(std::string name);
        int getId() const;
        void setId(int id);
};

#endif