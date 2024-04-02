/* Author: Andrew D'Angelo
   Date: 04/01/2024
   Description: This program simulates a smart product ordering system and tests the use of classes to accomplish this task. This new system allows the user to designate how many products they would like to
   order, apply a name to them, calculates the bulk cost and the total cost.
*/

#ifndef SMARTPRODUCT_H
#define SMARTPRODUCT_H

#include <iostream>
#include <string>

using namespace std;

class SmartProduct {
private:
    int productID;
    string productName;
    int unitsOrdered;
    double pricePerUnit;
    double totalPrice;

public:
    SmartProduct(int id, string name, int units, double price);
    int getProductID() const;
    void setProductID(int id);
    string getProductName() const;
    void setProductName(const std::string &name);
    int getUnitsOrdered() const;
    void setUnitsOrdered(int units);
    double getPricePerUnit() const;
    void setPricePerUnit(double price);
    double getTotalPrice() const;
};

#endif