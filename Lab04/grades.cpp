/* Author: Andrew D'Angelo
Date: 02/13/24
Description: This program uses a Do-while loop to accept different grade values and returns the average of all the inputs.
*/


#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float grade, sum = 0;
    int count = 0;
    char choice;

    do {
        cout << "Please enter a grade in a range of 0-100:";
        cin >> grade;

        // Establish range
        if (grade >= 0 && grade <= 100) {
            sum += grade;
            count++;

            cout << "Would you like to enter another grade (Y/N):";
            cin >> choice;
        } else {
            // Incorrect grade, prompt user to try again
            cout << "Your grade is outside of the allowed range. Please try again." << endl;
        }
        // Accept Y or y
    } while (choice == 'Y' || choice == 'y');

    // Compute the average and display the average grade
    if (count > 0) {
        float average = sum / count;
        cout << "Your grade average is:" << fixed << setprecision(4) << average << endl;
    } else {
        cout << "No valid grades entered." << endl;
    }

    return 0;
}
