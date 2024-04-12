#ifndef FREQCOUNTV1_h
#define FREQCOUNTV1_h

#include <iostream>
#include <string>
#include <map>

using namespace std;


//Declare functions that takes in a reference to a map of string,int pairs and returns nothing
void readTextFile(map<string, int>&frequencyMap);

void outputFreq(map<string, int>&frequencyMap);

void toLower(string &str);

class FileNotFound {
private:
    string message;
public:
    FileNotFound(const string &fileName) : message(fileName + " does not exist!") {}
    const string &what() const { return message; }
};





#endif