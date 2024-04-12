#include "FreqCountV1.h"
#include <fstream>
#include <cctype>

void toLower(string &str) {
    for (char &ch : str) {
        ch = tolower(static_cast<unsigned char>(ch));
    }
}

void readTextFile(map<string, int> &freqMap) {
    string fileName;
    cout << "Please enter the name of the file to process: ";
    cin >> fileName;

    ifstream file(fileName);
    if (!file) {
        throw FileNotFound(fileName);
    }

    string word;
    while (file >> word) {
        toLower(word);
        freqMap[word]++;
    }

    file.close();
}

void outputFreq(const map<string, int> &freqMap) {
    for (const auto &pair : freqMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    map<string, int> wordFreq;

    try {
        readTextFile(wordFreq);
        outputFreq(wordFreq);
    } catch (const FileNotFound &e) {
        cout << e.what() << endl;
        return -1;
    }

    return 0;
}
