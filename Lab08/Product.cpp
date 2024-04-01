/* Author: Andrew D'Angelo
   Date: 04/01/2024
   Description: This program simulates a product ordering system and tests the use of classes to accomplish this task.
*/

#include "Product.h"
using namespace std;

// set constructor and default values
Product::Product() : name(""), units(0), price(0.0), totalCost(0.0) {}

// Getters
string Product::getName() const { return name; }
int Product::getUnits() const { return units; }
double Product::getPrice() const { return price; }
double Product::getTotalCost() const { return totalCost; }

// Setters
void Product::setName(const string &newName) { name = newName; }
void Product::setUnits(int newUnits) { units = newUnits; }
void Product::setPrice(double newPrice) { price = newPrice; }
void Product::setTotalCost(double newTotalCost) { totalCost = newTotalCost; }