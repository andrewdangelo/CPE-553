/* Author: Andrew D'Angelo
   Date: 01/29/2024
   Description: This program calculates the surface area of a cylinder.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double PI = 3.14;
    int radius = 0, height = 0;
    double area = 0.0;

    cout << "Please enter the numerical value for the radius of the cylinder: ";
    cin >> radius;
    cout << "Please enter the numerical value for the height of the cylinder: ";
    cin >> height;

    area = 2* PI * pow(radius, 2) + height * (2* PI * radius);

    cout<<"The surface area of the cylinder is: " << area << endl;

    return 0;
}