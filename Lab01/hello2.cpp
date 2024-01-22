/* 
Author: Andrew D'Angelo
Date: 01/22/24
Description: This program outputs the phrase Hello, World!
*/

#include <iostream>
using namespace std;

int main()
{
    string userName;

    cout<<"Please enter your name: "<< endl;
    cin>> userName;
    cout<< "Hello, "<< userName << endl;
    return 0;
} // namespace std