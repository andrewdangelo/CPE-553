/* Author: Andrew D'Angelo
   Date: 04/01/2024
   Description: This program simulates a product ordering system and tests the use of classes to accomplish this task.
*/

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {

//set all member variables as private
private:
    string name;
    int units;
    double price;
    double totalCost;

public:
    // Constructors
    Product();

    // Getters
    string getName() const;
    int getUnits() const;
    double getPrice() const;
    double getTotalCost() const;

    // Setters
    void setName(const string &name);
    void setUnits(int units);
    void setPrice(double price);
    void setTotalCost(double totalCost);
};

#endif
