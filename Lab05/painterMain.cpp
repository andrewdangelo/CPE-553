/* Author: Andrew D'Angelo
   Date: 02/19/2024
   Description: This program allows a user to output an ASCII image and applies a border using a custom symbol around the whole image.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "painterFuncs.h" 
using namespace std;

int main() {
    char borderSymbol;
    int choice = intro(borderSymbol);

    switch (choice) {
        case 1:
            sleepingCat(borderSymbol);
            break;
        case 2:
            sailingShip(borderSymbol);
            break;
        case 3:
            appleComputer(borderSymbol);
            break;
        case 4:
            dogPic(borderSymbol);
            break;
        default:
            cout << "Hmmmm....we don't seem to have that painting." << endl;
            blank(borderSymbol);
            exit(-1);
    }

    cout << "Hope you enjoyed your art!" << endl;
    return 0;
}