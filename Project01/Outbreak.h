#ifndef OUTBREAK_H
#define OUTBREAK_H


#include <string>

using namespace std;

// Health states represented as an enum for setting up the required struct.
enum HealthState { S, I, R, V };

/**
 * @brief  person that contains at least the person’s health state and how long they
    have been infectious.
 * 
 * @param state The current health state of the person.
 * @param infectionLen # of days the person has been infectious.
 */

struct Person {
    HealthState state;
    int infectionLen;
};

/**
 * @brief Reads initial simulation data from a file or input source.
 * 
 * @param height Reference to store the height of the region.
 * @param width Reference to store the width of the region.
 * @param infectiousThreshold Reference to store the threshold of days a person remains infectious.
 * @param region Pointer to a 2D array of Person objects representing the population.
 */
Person** readData(int& height, int& width, int& infectiousThreshold);

/**
 * @brief Outputs the current state of the region console.
 * 
 * @param region Constant pointer to a 2D array of Person objects that define the region.
 * @param height The height of the region.
 * @param width The width of the region.
 * @param day The current day.
 */
void outputRegionState(const Person* const* region, int height, int width, int day);

/**
 * @brief Simulates the outbreak for a single time step.
 * 
 * @param region Pointer to a 2D array of Person objects to update based on simulation rules.
 * @param height The height of the region.
 * @param width The width of the region.
 * @param infectiousThreshold The threshold of days a person remains infectious.
 */
void simulate(Person** region, int height, int width, int infectiousThreshold);

/**
 * @brief This is a custom data structure to hold the configuration file information
 * 
 * @param height represents the regions height
 * @param width represents the regions width
 * @param infectiousPeriod How many days the persion will be infectious
 * @param infectiousThreshold How many infectious people need to be adjacent to a susceptible person for the susceptible person to become infectious on the next day.
 * @param regionFileName The region file name.
*/

struct ConfigData {
    int height;
    int width;
    int infectiousPeriod;
    int infectiousThreshold;
    string regionFileName;
};

/**
 * @brief This function checks all around a susceptible person for infection.
 * 
 * @param region Pointer to a 2D array of Person objects to update based on simulation rules.
 * @param x Coordinate of i.
 * @param Coordinate of j.
 * @param height The height of the region.
 * @param width The width of the region.
 * 
 * @return Returns the number of infected people around a particular susceptible person.
*/
int checkAround(Person** region, int x, int y, int height, int width);


#endif
