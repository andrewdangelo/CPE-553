/* Author: Andrew D'Angelo
   Date: 04/01/2024
   Description: This program simulates a product ordering system and tests the use of classes to accomplish this task.
*/


#include <iostream>
#include <iomanip>
#include "Product.h"
using namespace std;

/**
 * @brief The function should calculate the total cost of the order using the information from the Product object and then store the total cost.
 * @param product - reference to product object. 
*/
void calcTotal(Product &product) {
    double total = product.getUnits() * product.getPrice();
    product.setTotalCost(total);
}

int main() {
    //declare a product
    Product product;

    string productName;
    int units;

    // Get the user input for the product order.
    cout << "Please enter the name of the product you wish to order: ";
    getline(cin, productName);
    product.setName(productName);

    // Get Product information
    cout << "Please enter the number of units of product you wish to order: ";
    cin >> units;
    product.setUnits(units);

    product.setPrice(9.99);

    calcTotal(product);

    cout << "You ordered:\n"
         << "Name: " << product.getName() << "\n"
         << "Units: " << product.getUnits() << "\n"
         << "Price: $" << fixed << setprecision(2) << product.getPrice() << "\n"
         << "Total Cost: $" << fixed << setprecision(2) << product.getTotalCost() << endl;

    return 0;
}
