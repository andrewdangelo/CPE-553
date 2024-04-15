/* Author: Andrew D'Angelo
   Date: 04/15/2024
   Description: This program accepts a text file full of words and counts the number of words in chunk of text. To do so the text file is broken into words and stored in a frequency map.
*/

#ifndef FREQCOUNTV1_H
#define FREQCOUNTV1_H

#include <map>
#include <string>
#include<iostream>

using namespace std;
// Declare a function readTextFile() that takes in a reference to a map of string,int pairs and returns nothing.
void readTextFile(map<string, int>& frequencyMap);

//Declare a function outputFreq() that takes in a reference to a map of string,int pairs and returns nothing.
void outputFreq(const map<string, int>& frequencyMap);

//Declare a function toLower() that takes in a reference to a string and returns nothing
void toLower(string& str);

/*
Define a class named FileNotFound which contains:
• A private string to store the error message
• A public constructor that takes in a string representing the name of a file and uses it to
create a message informing the user that that file does not exist
• A public function named what() that returns the error message string
*/
class FileNotFound {
private:
    string errMsg;

public:
    FileNotFound(const string& fileName);
    string what() const;
};

#endif
