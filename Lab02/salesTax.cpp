/* Author: Andrew D'Angelo
   Date: 01/29/2024
   Description: This program computes the sales tax of a purchase.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double value = 0.0;
    double totalAmount = 0.0;
    const double taxRate = 0.104;
    double salesTax = 0.0;

    cout << "Please input the value of your purchase: ";
    cin >> value;

    salesTax = taxRate * value;
    totalAmount = salesTax + value;

    cout << fixed << setprecision(2);
    cout << "The total amount is: $" << totalAmount << endl;

    return 0;
}