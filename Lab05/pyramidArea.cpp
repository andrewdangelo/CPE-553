/* Author: Andrew D'Angelo
   Date: 02/19/2024
   Description: This program takes in the height and side length of a square pyramid and returns its proper dimensions.
*/

#include <iostream>
#include <cmath>
using namespace std;

// function prototypes

float calcBaseArea(float a);
float calcSideArea(float a, float h);
void prntSurfArea(float baseArea, float sideArea);
// add your function prototypes/declarations here

int main()
{
	float h; 	 	 // height
	float a;	 	 // length of one side of the base
	float base_area; // area of base
	float side_area; // area of side

	cout << "Enter the side length of the base of the square pyramid in feet: ";
	cin  >> a;

	cout << "Enter the height of the square pyramid in feet: ";
	cin  >> h;

	base_area = calcBaseArea(a);
	cout << "Base surface area of the square pyramid is " << base_area
	     << " square feet." << endl;

	// add your function to to calculate the side area and assign
    // the result to side_area, then print the result
	side_area = calcSideArea(a, h);
	cout.precision(3); // Set precision for floating-point output
    cout << fixed; // Ensure precision specifies decimal places
    cout << "Total surface area of all four sides of the square pyramid is " << side_area << " square feet." << endl;
	// add your function call to print the total surface area
	prntSurfArea(base_area, side_area);

	return 0;
}

// @brief This function calculates the area of the base of the pyramid
// @param a The length of one edge of the base of the pyramid
// @return The area of the base of the pyramid
float calcBaseArea(float a)
{
	return pow(a, 2);
}

// add your function definition for calcSideArea here
/**
 * @brief This function computes the area of the four triangular sides of a square pyramid using the side length and pyramid height.
 * @param a The side length of the square base of the pyramid, in feet.
 * @param h The height of the pyramid, from the base to the apex, in feet.
 * @return The total side area of the pyramid, in square feet.
 */
float calcSideArea(float a, float h) {
    float slantHeight = sqrt(pow(h, 2) + pow(a / 2, 2));
    float sideArea = (a * slantHeight) / 2 * 4;
    return sideArea;
}

// add your function definition for prntSurfArea here
/**
 * @brief This function takes the base area and side area as input, calculates the total surface area, and prints it out.
 * @param baseArea The area of the base of the pyramid, in square feet.
 * @param sideArea The total side area of the pyramid, in square feet.
 */
void prntSurfArea(float baseArea, float sideArea) {
    float totalSurfaceArea = baseArea + sideArea;
    cout << "Total surface area of the square pyramid is " << totalSurfaceArea << " square feet." << endl;
}

