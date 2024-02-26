/* Author: Andrew D'Angelo
   Date: 02/26/2024
   Description: This program creates a 2 dimensional array of random numbers and determines the mode of the array.
*/

#include <iostream>
using namespace std;

/*
Declare and define a function named sortIt() that returns an integer and takes in a character
array and a constant integer representing the array’s size as parameters and should
*/
int sortIt(char arr[], const int size) {
    //Have an integer variable to keep track of the number of iterations
    int iterations = 0;
    bool sorted = false;

    // Loop until the array is sorted
    while (!sorted) {
        sorted = true; // Assume the array is sorted
        for (int i = 0; i < size - 1; i++) {
            // any time it detects two characters that are next to each other but are out of order
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }
        
        // After an iteration, the function should output the array to show the sorting progression
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        iterations++; // Increment the iteration count
    }
    return iterations;
}

int main() {
    // Define a character array and set its default data to the letters b, f, a, z, m, g, r, x, t, n
    char char_arr[10] = {'b', 'f', 'a', 'z', 'm', 'g', 'r', 'x', 't', 'n'};

    // Define a constant integer variable and assign it the value 10, representing the number of characters in the array
    const int size = 10;
    int numIterations;

    // Call your sorting function, pass in the array and the constant integer, and store the functions output in an appropriate variable
    numIterations = sortIt(char_arr, size);

    // Output to the user, with an appropriate message, the newly sorted array along with the number of iterations required to sort it

    cout << "The letters are now in order:" << endl;
    for (int i = 0; i < size; i++) {
        cout << char_arr[i] << " ";
    }
    cout << endl;
    cout << "It took " << numIterations << " iterations to sort the char_arr." << endl;

    return 0;
}