/* Author: Andrew D'Angelo
Date: 02/13/24
Description: finds the sum of all odd numbers between any two randomly generated numbers.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    
    srand((time(0)));

    // Generate the first random integer between 5 and 15, inclusively
    int num1 = rand() % (15 - 5 + 1) + 5;

    // Generate the second random integer between 15 and 25, inclusively
    int num2 = rand() % (25 - 15 + 1) + 15;

    int sum = 0;
    int minInt, maxInt;

    // Determine the minimum and maximum integers
    if (num1 < num2) {
        minInt = num1;
        maxInt = num2;
    } else {
        minInt = num2;
        maxInt = num1;
    }

    /* Inside a for loop, compute the sum of all odd integers between the two random integers. The
    random integers should be included in sum if they are odd*/

    for (int i = minInt; i <= maxInt; i++) {
        // Check if the number is odd
        if (i % 2 != 0) {
            sum += i;
        }
    }

    // Display the random integers as well as the sum on the screen with suitable messages
    cout << "The minimum integer was " << minInt << " and the maximum integer was " << maxInt << endl;
    cout << "The sum of all odd integers between " << minInt << " and " << maxInt << " was " << sum << endl;

    return 0;
}
