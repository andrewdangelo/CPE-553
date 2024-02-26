/* Author: Andrew D'Angelo
   Date: 02/26/2024
   Description: This program accepts heights of students of size SIZE, calculates the average height, determine which heights are above average and outputs all of this information.
*/

#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 8; //8 students
    int height[SIZE]; //array to store height of 8 students
    
    // Declare another array of the same size and type and call it above_average
    int above_average[SIZE];
    int sum = 0;
    int count = 0;
 
    for(int i = 0; i < SIZE; i++)
    {
        cout<<"Enter height in inches of student #"<<i+1<<":";
        cin>>height[i];// read heights, one student at a time
		//compute the sum of the heights
        sum += height[i];
    }
    
    //compute the average of the heights
    double average = static_cast<double>(sum) / SIZE;

    //modify code to check if height is above average
    //copy to the second array if it is

    // Check if height is above average and copy to the second array if it is
    for(int i = 0; i < SIZE; i++)
    {
        if(height[i] > average)
        {
            above_average[count] = height[i];
            count++;
        }
    }
    
    cout<<"You entered:"<<endl;
    for(int i = 0; i < SIZE; i++)
    {
        //display the heights entered by the user
        cout << "Height in inches of student #" << i + 1 << ":" << height[i] << endl; 
    }
	
    //display the heights above the average entered by the user
    cout << "Average height: " << average << " inches" << endl;

    cout << "Heights above the average:" << endl;
    for(int i = 0; i < count; i++)
    {
        cout << above_average[i] << " inches" << endl;
    }

    return 0;
}
