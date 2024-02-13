/* Author: Andrew D'Angelo
Date: 02/13/24
Description: This program opens a text file, reads the lines to get the author, title, content, and keeps track of the lines. Then it uses istringstream to preview the poem.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    // declare variables
    string poemTitle, poemAuthor, line, poemContent, fileName;
    int lineCount = 0;

    /* Prompt the user for the name of the file they wish to have read in and summarized and
    store it in a variable */
    cout << "Please input the name of the poem you wish summarized: ";
    cin >> fileName;

    //Open the file for reading using an ifstream
    ifstream poemFile(fileName);

    // Check if the file exists
    while (!poemFile.is_open()) {
        cout << fileName << " does not exist! Please input the name of the poem you wish summarized: ";
        cin >> fileName;
        poemFile.open(fileName);
    }

    // Read and store the poem's title and author
    getline(poemFile, poemTitle);
    getline(poemFile, poemAuthor);

    /*
    Read each line of the poem, concatenate it to the string variable, and keep track of
    the number of lines
    */
    while (getline(poemFile, line)) {
        poemContent += line + "\n";
        lineCount++;
    }

    // Close the poem file after reading
    poemFile.close();

    // Open Output.txt for writing
    ofstream output("Output.txt");

    // Write the summary to Output.txt
    output << "The name of the poem is " << poemTitle << endl;
    output << "The author of the poem is " << poemAuthor << endl;
    output << "The number of lines in the poem is " << lineCount << endl;
    output << "A preview of the poem is:" << endl;

    // Open the string containing the poem using an istringstream
    istringstream iss(poemContent);
    
    for (int i = 0; i < 3 && getline(iss, line); i++) {
        output << line << endl;
    }

    // Close the Output file
    output.close();

    cout << "Summary written to Output.txt" << endl;

    return 0;
}
