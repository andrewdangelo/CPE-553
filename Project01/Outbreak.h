#ifndef OUTBREAK_H
#define OUTBREAK_H

// Health states represented as an enum for setting up the required struct.
enum HealthState { Susceptible, Infectious, Recovered, Vaccinated };

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
void readData(int& height, int& width, int& infectiousThreshold, Person***& region);

/**
 * @brief Outputs the current state of the simulation to a file or console.
 * 
 * @param region Constant pointer to a 2D array of Person objects.
 * @param height The height of the region.
 * @param width The width of the region.
 * @param day The current simulation day.
 */
void outputState(const Person* const* region, int height, int width, int day);

/**
 * @brief Simulates the outbreak for a single time step.
 * 
 * @param region Pointer to a 2D array of Person objects to update based on simulation rules.
 * @param height The height of the region.
 * @param width The width of the region.
 * @param infectiousThreshold The threshold of days a person remains infectious.
 */
void simulateOutbreak(Person**& region, int height, int width, int infectiousThreshold);

#endif
