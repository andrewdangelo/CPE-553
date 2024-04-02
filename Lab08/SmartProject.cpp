/* Author: Andrew D'Angelo
   Date: 04/01/2024
   Description: This program simulates a smart product ordering system and tests the use of classes to accomplish this task. This new system allows the user to designate how many products they would like to
   order, apply a name to them, calculates the bulk cost and the total cost.
*/

#include "SmartProduct.h"
using namespace std;

SmartProduct::SmartProduct(int id, string name, int units, double price)
    : productID(id), productName(name), unitsOrdered(units), pricePerUnit(price) {
    totalPrice = unitsOrdered * pricePerUnit;
}

// GETTER: id
int SmartProduct::getProductID() const {
    return productID;
}

//SETTER: id
void SmartProduct::setProductID(int id) {
    productID = id;
}

//GETTER: name
string SmartProduct::getProductName() const {
    return productName;
}

//SETTER: name
void SmartProduct::setProductName(const string &name) {
    productName = name;
}

//GETTER: orders
int SmartProduct::getUnitsOrdered() const {
    return unitsOrdered;
}

//SETTER: orders
void SmartProduct::setUnitsOrdered(int units) {
    unitsOrdered = units;
    totalPrice = unitsOrdered * pricePerUnit; // Recalculate total price
}

//GETTER: ppu
double SmartProduct::getPricePerUnit() const {
    return pricePerUnit;
}

//SETTER: ppu
void SmartProduct::setPricePerUnit(double price) {
    pricePerUnit = price;
    totalPrice = unitsOrdered * pricePerUnit; // Recalculate total price
}

//GETTER: price
double SmartProduct::getTotalPrice() const {
    return totalPrice;
}