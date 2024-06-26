/* Author: Andrew D'Angelo
   Date: 04/15/2024
   Description: This program accepts a text file full of words and counts the number of words in chunk of text. To do so the text file is broken into words and stored in a frequency map.
*/

#include "FreqCountV1.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>

/*
Define the toLower() function such that:
• It iterates through every character in the string and converts it to lowercase
*/
void toLower(string &str) {
    for (char &ch : str) {
        ch = tolower(static_cast<unsigned char>(ch));
    }
}

// Definition of FileNotFound constructor and what() method
FileNotFound::FileNotFound(const string& fileName) {
    errMsg = fileName + " does not exist!";
}

string FileNotFound::what() const {
    return errMsg;
}

/*
Define the readTextFile() function such that:
• It prompts the user for the name of the file, and if the file does not exist throw a
FileNotFound exception, being sure to pass in the name of the file
• Otherwise, read the file one word at a time and for each word:
    • Convert all of the characters to lowercase using the appropriate function
    • If the word exists in the map, increment its frequency by 1
    • If the word does not exist in the map, set its frequency to 1
*/
void readTextFile(map<string, int>& frequencyMap) {
    string fileName;
    cout << "Please enter the name of the file to process: ";
    cin >> fileName;

    ifstream inFile(fileName);
    if (!inFile) {
        throw FileNotFound(fileName);
    }

    string word;
    while (inFile >> word) {
        toLower(word);
        frequencyMap[word]++;
    }
}

/*
Define the outputFreq() function such that:
• Using an iterator, output each word and its associated count from the map
• A public constructor that takes in a string representing the name of a file and uses it to
create a message informing the user that that file does not exist

*/
void outputFreq(const map<string, int>& frequencyMap) {
    for (const auto& pair : frequencyMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

/*
Define the main() function such that it:
    • Instantiates a map of string,int pairs
    • In a try block, attempts to read the text file, using the appropriate function, and
    catches any FileNotFound exceptions that may be thrown
    • If a FileNotFound exception is thrown, output the exception’s message using
    the appropriate function, and return -1
    • Outputs the frequency of all of the words in the map using the appropriate function
*/
int main() {
    map<string, int> frequencyMap;
    try {
        readTextFile(frequencyMap);
        outputFreq(frequencyMap);
    } catch (const FileNotFound& e) {
        cout << e.what() << endl;
        return -1;
    }
    return 0;
}
