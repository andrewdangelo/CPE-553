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
    int userAge;

    cout<<"Please enter your name: "<< endl;
    cin>> userName;
    cout<<"Please enter your Age: "<< endl;
    cin>> userAge;
    cout<< "Hello, "<< userName << " you are "<< userAge << " years old!" << endl;
    return 0;
} // namespace std