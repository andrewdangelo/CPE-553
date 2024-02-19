/* Author: Andrew D'Angelo
   Date: 02/19/2024
   Description: This program allows a user to output an ASCII image and applies a border using a custom symbol around the whole image.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

// Function prototypes
void readFile(const string& filePath);
int intro(char &borderSymbol);
void printHeaderFooter(char border, int size);
void sleepingCat(char border);
void sailingShip(char border);
void appleComputer(char border);
void dogPic(char border);
void blank(char border);

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

// Reads the txt file and adds a border around the image for a size of 40x40
void readFile(const string& filePath, char border) {
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << border; 
        
        
        int padding = 38 - line.length();
        if (padding < 0) padding = 0; 
        
        
        cout << left << setw(38) << line;
        
        cout << border << endl;
    }

    file.close();
}

int intro(char &borderSymbol) {
    int choice;
    cout << "Welcome to the ASCII art painter program!" << endl;
    cout << "Please choose an ASCII art painting:" << endl;
    cout << "1. Sleeping Cat" << endl;
    cout << "2. Sailing Ship" << endl;
    cout << "3. Apple Computer" << endl;
    cout << "4. Dog" << endl;
    cin >> choice;
    cout << "Enter a single symbol for the border: ";
    cin >> borderSymbol;
    return choice;
}

void printHeaderFooter(char border, int size) {
    for (int i = 0; i < size; i++) {
        cout << border;
    }
    cout << endl;
}

void sleepingCat(char border) {
    printHeaderFooter(border, 40); 
    string filePath = "sleepingCat.txt";
    readFile(filePath, border);
    printHeaderFooter(border, 40); 
}

void sailingShip(char border) {  
    printHeaderFooter(border, 40); 
    string filePath = "sailingShip.txt";
    readFile(filePath, border);
    printHeaderFooter(border, 40); 
}

void appleComputer(char border) {
    printHeaderFooter(border, 40); 
    string filePath = "computer.txt";
    readFile(filePath, border);
    printHeaderFooter(border, 40); 
}

void dogPic(char border) {
    printHeaderFooter(border, 40); 
    string filePath = "dog.txt";
    readFile(filePath, border);
    printHeaderFooter(border, 40); 
}

void blank(char border) {
    // Function to display a blank canvas
    printHeaderFooter(border, 40); 
    for (int i = 0; i < 5; i++) {
        cout << border << "                                      " << border << endl;
    }
    printHeaderFooter(border, 40); 
}
