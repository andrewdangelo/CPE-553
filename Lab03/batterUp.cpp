/* Author: Andrew D'Angelo
   Date: 02/05/2024
   Description: This is a simulation program for a baseball scenario where a batter hits the ball.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;


int main() {
  // Seed the random number generator
  srand(time(0));

  // Generate a random distance between 0 and 450 feet
  int distance = rand() % 451;


  if (distance > 400) {
    cout << "Batter hit a homerun! A run has been scored for the team! Distance: " << distance << endl;
  } else if (distance >= 135) {
    cout << "Batter hit the ball into the outfield! The batter has made it to third base. Distance: " << distance << endl;
  } else if (distance >= 10) {
    cout << "Batter hit the ball into the infield! The batter has made it to second base. Distance: " << distance << endl;
  } else if (distance >= 1) {
    cout << "Batter bunted the ball! The batter has made it to first base. Distance: " << distance << endl;
  } else {
    cout << "Batter struck out." << endl;
  }

  return 0;
}