/* Author: Andrew D'Angelo
   Date: 03/25/2024
   Description: This program accepts an input quote and is able to identify the number of letters, whitespaces, integers and characters in the phrase.
*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

/**
 * @brief Check if the character is a letter and returns true or false.
 * @param ch Character
 * @return Boolean value to indicate if the character is a letter as true or false.
*/
bool isLetter(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

/**
 * @brief Check if the character is a number and returns true or false.
 * @param ch Character
 * @return Boolean value to indicate if the character is a number as true or false.
*/
bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

/**
 * @brief Check if the character is whitespace and returns true or false.
 * @param ch Character
 * @return Boolean value to indicate if the character is whitespace as true or false.
*/
bool isWhitespace(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\t';
}

int main() {
    int letters = 0, digits = 0, whitespaces = 0, specialChars = 0;
    string input;

    cout << "Please enter the quote to analyze: ";
    getline(cin, input);

    // Need to convert the string to c-string
    const char* quote = input.c_str();

    // iterivaley check if the character is a letter, number, whitespace, or special character
    for (int i = 0; i < strlen(quote); ++i) {
        char ch = quote[i];
        if (isLetter(ch)) {
            ++letters;
        } else if (isDigit(ch)) {
            ++digits;
        } else if (isWhitespace(ch)) {
            ++whitespaces;
        } else { // None of those, therefore, it is a special character.
            ++specialChars;
        }
    }

    //Output values.
    cout << "Number of letters: " << letters << endl;
    cout << "Number of digits: " << digits << endl;
    cout << "Number of whitespaces: " << whitespaces << endl;
    cout << "Number of special characters: " << specialChars << endl;

    return 0;
}
