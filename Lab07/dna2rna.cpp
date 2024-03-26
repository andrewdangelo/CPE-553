/* Author: Andrew D'Angelo
   Date: 03/25/2024
   Description: This program accepts an input file that contains a DNA sequence and output the corresponding RNA translation to a new file. 
   This program optimizes memory space by reading in a single character at a time and performs analysis on a character basis versus and sequence basis.
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/**
 * @brief Checks if the character is a valid DNA character.
 * @param ch Character from DNA sequence.
 * @return Boolean indicating if the character is a DNA char or not.
*/
bool isValidDNACharacter(char ch) {
    return ch == 'A' || ch == 'C' || ch == 'G' || ch == 'T';
}

/**
 * @brief Performs a character conversion for the DNA nucleotides T and U. Standard DNA to RNA conversion translates T to U where U stands for Uracil.
 * @param dnaChar Character from DNA sequence.
 * @return Returns the updated character if the input was a T.
*/
char convertDNAToRNACharacter(char dnaChar) {
    if (dnaChar == 'T') {
        return 'U';
    }
    return dnaChar;
}

int main() {
    char fileName[256];
    ifstream inputFile;

    // Define output RNA file.
    ofstream outputFile("RNA.txt");
    char ch;
    bool isValidDNA = true;

    while (true) {
        //Get the input DNA filename.
        cout << "Please enter the name of the DNA file: ";
        cin >> fileName;

        inputFile.open(fileName);

        //Check if the DNA file exists.
        if (!inputFile.is_open()) {
            cout << fileName << " does not exist! Please input the name of the DNA file: " << endl;
            continue;
        }

        // Check the character
        while (inputFile.get(ch)) {

            // Exit the loop if an invalid character is found
            if (!isValidDNACharacter(ch)) {
                isValidDNA = false;
                break; 
            }

            // Write the character to the RNA file.
            outputFile << convertDNAToRNACharacter(ch);
        }

        //Clean-up
        inputFile.close();
        outputFile.close();

        // Check if the sequence is valid.
        if (!isValidDNA) {
            cout << "Your sequence is not a DNA sequence!" << endl;

            // Delete the RNA.txt file since the input was invalid
            remove("RNA.txt"); 

            // Exit the program with an error code
            return 1; 
        }

        cout << "RNA.txt has been successfully created..." << endl;
        break;
    }

    return 0;
}

