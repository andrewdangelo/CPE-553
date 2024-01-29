
//Error #1: need to changed / to /*
/* Author: Andrew D'Angelo
   Date: 01/29/2024
   Description: This program is dedicated towards error correction. There were a bunch of errors that are in the file that I have bug
   fixed and commented.
*/

//Error #2: Changed <stream> to <iostream> and added # symbol
#include <iostream>

//Error #3: Forgot ; at the end of line 13
using namespace std;

int main() 
//Error #4: wrong character for opening a function block. Changed } to {
{
        //Error #5: Changed cout < to cout <<
        cout  <<  "This code contains multiple syntax errors.\n";
        //Error #6: Wrong use of quotation
        cout  << "These need to be fixed before you submit it.\n"; 
        //Error #7: Used count rather than count, forgot ; at the end of the line, used the wrong << symbol, and replaced my name in the line.
        cout << "Fixed by Andrew D'Angelo.\n";

        //Error #8: Needed space between return and 0
        return 0; 
}