#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

using namespace std;

int main() {
    srand(time(0)); // Seed for random number generation, ensuring different numbers each run

    int rows = 0;
    int cols = 0;

    //Prompt the user for a row and column size for a two-dimensional array, and then declare that array

    cout << "Please enter the number of rows for the array: ";
    cin >> rows;
    cout << "Please enter the number of columns for the array: ";
    cin >> cols;

    // Intialize array
    int arr2D[rows][cols];

    // Fill the 2D array with random numbers between 0 and 10
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr2D[i][j] = rand() % 11; // Numbers from 0 to 10
        }
    }

    // Declare a 1D integer array with 11 slots in which every slot is initialized to 0
    int frequency[11] = {0};

    // Iterate through the 2D array and use the 1D array to keep track of how frequently each of the numbers between 0 and 10 occur. 
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            frequency[arr2D[i][j]]++;
        }
    }

    // Determine which number(s) represent the mode of the series.
    int maxFrequency = 0;
    for(int i = 0; i < 11; i++) {
        if(frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
        }
    }

    // Output the 2D array in a neat, grid format and output the mode with an appropriate message
    cout << "The 2D array:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << arr2D[i][j] << " ";
        }
        cout << endl;
    }

    // Output the mode(s)
    cout << "The mode(s) for this set of numbers are: ";
    for(int i = 0; i < 11; i++) {
        if(frequency[i] == maxFrequency) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
