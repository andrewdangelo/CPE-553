/* Author: Andrew D'Angelo
   Date: 02/05/2024
   Description: This is a conversion from if-else statements to a switch statement for a quiz about the spice of peppers.
*/


#include <iostream>

using namespace std;

int main()
{
    char choice;
    cout << "Welcome to the EE 553 quiz. Please choose the correct answer to the following question:" << endl;
    cout << "Which of the following peppers is, on average, the spiciest according to the Scoville Heat Scale?" << endl;
    cout << "A. Banana Pepper" << endl;
    cout << "B. Carolina Reaper" << endl;
    cout << "C. Trinidad Scorpion" << endl;
    cout << "D. Scotch Bonnet" << endl;
    cout << "E. Habanero" << endl;
    cout << "Please enter your choice (A, B, C, D, or E):" << endl;

    cin >> choice;

    switch(choice)
    {
        case 'A':
            cout << "That is incorrect, and this pepper is barely spicy with 0-100 SHUs." << endl;
            break;
        case 'B':
            cout << "That is correct! This pepper is super hot with 2,000,000-2,200,000 SHUs." << endl;
            break;
        case 'C':
            cout << "That is incorrect, but this pepper is still super hot with 1,500,000-2,000,000 SHUs." << endl;
            break;
        case 'D':
            cout << "That is incorrect, but this pepper is still hot with 100,000-350,000 SHUs." << endl;
            break;
        case 'E':
            cout << "That is incorrect, but this pepper is still hot with 100,000-350,000 SHUs." << endl;
            break;
        default:
            cout << "That is not a valid choice." << endl;
    }

    cout << "Goodbye" << endl;

    return 0;
}
