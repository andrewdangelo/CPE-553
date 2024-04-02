/* Author: Andrew D'Angelo
   Date: 04/01/2024
   Description: This program simulates a smart product ordering system and tests the use of classes to accomplish this task. This new system allows the user to designate how many products they would like to
   order, apply a name to them, calculates the bulk cost and the total cost.
*/

#include "SmartProduct.h"
#include <vector>
#include <iomanip>

using namespace std;

double calcTotal(SmartProduct** products, int size) {
    double total = 0.0;
    for (int i = 0; i < size; ++i) {
        total += products[i]->getTotalPrice();
    }
    return total;
}

int main() {
    int numProducts;

    // Prompt the user to determine the number of products
    cout << "How many products would you like to order: ";
    cin >> numProducts;

    //set products based on user prompt
    SmartProduct** products = new SmartProduct*[numProducts];

    // Add a product entry for each order.
    for (int i = 0; i < numProducts; ++i) {
        string name;
        int units;
        cout << "Please enter the name of the product you wish to order: ";
        cin >> name;
        cout << "Please enter the number of units of product you wish to order: ";
        cin >> units;

        products[i] = new SmartProduct(i + 1, name, units, 9.99); //base price of $9.99
    }

    //Print out order summary.
    cout << "You ordered:\n";
    for (int i = 0; i < numProducts; ++i) {
        cout << "ID: " << products[i]->getProductID() << endl
             << "Name: " << products[i]->getProductName() << endl
             << "Units: " << products[i]->getUnitsOrdered() << endl
             << "Price: $" << fixed << setprecision(2) << products[i]->getPricePerUnit() << endl
             << "Total Cost: $" << products[i]->getTotalPrice() << endl;
    }

    cout << "The total cost of your order is: $" << fixed << setprecision(2) << calcTotal(products, numProducts) << endl;

    // Clean up dynamically allocated memory
    for (int i = 0; i < numProducts; ++i) {
        delete products[i];
    }
    delete[] products;

    return 0;
}