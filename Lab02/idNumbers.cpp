/* Author: Andrew D'Angelo
   Date: 01/29/2024
   Description: This program generates random id numbers for four different patients.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
   // Seed the random number generator
   srand(time(0));

   //random letter generation
   char letters[4];
   for (int i = 0; i < 4; i++) {
       letters[i] = 'A' + rand() % 26;  
   }

   
   int numbers[8];
   for (int i = 0; i < 2; i++) {
       numbers[i] = 10 + rand() % 15;   // range 1
       numbers[i + 2] = 25 + rand() % 25; // range 2
       numbers[i + 4] = 50 + rand() % 25; // range 3
       numbers[i + 6] = 75 + rand() % 25; // range 4
   }


    //PRINT OUPUT
    cout << "Here are four id numbers: " << endl;
   
   for (int i = 0; i < 4; i++) {
       cout <<  letters[i] << numbers[i * 2] << "-" << numbers[i * 2 + 1] << endl;
   }

   return 0;
}
