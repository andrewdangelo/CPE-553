#include "Outbreak.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<iomanip>
#include <vector>



using namespace std;


/**
 * @brief helper function to convert the characters to enum states
 * @param state the healthstate enum value
 * @return state character
*/
HealthState charToState(char c) {
    switch(c) {
        case 'S': return S;
        case 'I': return I;
        case 'R': return R;
        case 'V': return V;
        default: return S; // Default case
    }
}

/**
 * @brief helper function to convert the enum states to characters
 * @param state the healthstate enum value
 * @return state character
*/
char stateToChar(HealthState state) {
    switch (state) {
        case S: return 'S';
        case I: return 'I';
        case R: return 'R';
        case V: return 'V';
        default: return ' ';
    }
}

/**
 * @brief Reads simulation configuration and initial population state from an input source.
 * 
 * @param height Reference to store the height of the simulation region.
 * @param width Reference to store the width of the simulation region.
 * @param infectiousThreshold Reference to store the number of days a person remains infectious.
 
 */
Person**  readData(int& height, int& width, int& infectiousThreshold) {
    string configFileName;
    ifstream configFile;
    ifstream regionFile;
    string line;
    ConfigData* config = new ConfigData;

    do{
        cout << "Please enter the name of the file containing the simulation configuration: ";
        cin >> configFileName;

        // Check if the file exists
        configFile.open(configFileName);
        if (!configFile) {
            cout << "File does not exist. Please try again." << endl;
        }
    } while (!configFile);
    
    //Read in data from simulation config file
    while(getline(configFile, line)){
        // Parses the information from the config file by looking for the data after the : and the text information.
        //All information is saved to config data structure
        size_t position = line.find(":");
        if (position != string::npos) {
                string info = line.substr(position + 1);
                info.erase(0, info.find_first_not_of(" \t"));

                if (line.find("Region Height") != string::npos) {
                    config->height = stoi(info);
                } else if (line.find("Region Width") != string::npos) {
                    config->width = stoi(info);
                } else if (line.find("Threshold") != string::npos) {
                    config->infectiousThreshold = stoi(info);
                } else if (line.find("Infectious Period") != string::npos) {
                    config->infectiousPeriod = stoi(info);
                } else if (line.find("Region File") != string::npos) {
                    config->regionFileName = info;
                }
            }
    }

    //Set width and height
    width = config->width;
    height = config->height;
    infectiousThreshold = config->infectiousThreshold;
    //Allocate the 2D array
    Person** grid = new Person*[height];
    
    //Open the region file and read in data one line at a time.
    regionFile.open(config->regionFileName);
    if(!regionFile.is_open()){
        //File doesn't exist
        cout<<"Incorrect region file. Could not open: "<<config->regionFileName<<endl;

    } else {
       //Populate dynamic 2D array
        for (int i = 0; i < height; ++i) {
            grid[i] = new Person[width];
        }


        int row = 0;
        while (getline(regionFile, line) && row < height) {
            int col = 0;
            for (size_t i = 0; i < line.length() && col < width; i += 2, ++col) { // Account for comma-separated values
                grid[row][col].state = charToState(line[i]);
               // grid[row][col].infectionLen = (grid[row][col].state == I) ? config->infectiousPeriod : 0; // Initialize based on state
               grid[row][col].infectionLen = config->infectiousPeriod;
            }
            ++row;
        }
    }
    
    regionFile.close();
    return grid;
}


/**
 * @brief A function to output the entire state of the region and the day.
 * @param region Two-dimensional array of person structs.
 * @param height Integer height value.
 * @param width Integer width value.
 * @param day Represents the day.
*/

void outputRegionState(Person** region, int height, int width, int day) {
    cout << "Region state on Day " << day << ":" << endl;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << stateToChar(region[i][j].state) << ' ';
        }
        cout << endl;
    }
}


void simulate(Person** region, int height, int width, int infectiousThreshold){
    vector<vector<int>> infectionTimer(height, vector<int>(width, 0));
    bool hasInfectious = true;
    int day = 0, totalInfectious = 0, peakInfectious = 0, peakDay = 0;
    int susceptibleCount = 0, recoveredCount = 0, vaccinatedCount = 0;
    
    //intial region pass
    //Check for infectious in the region and increase counter when found.
    for (int i = 0; i<height; i++){
        for (int j = 0; j< width; j++){
            if (region[i][j].state == I){
                hasInfectious = true;
            }
        }
    }

    while (hasInfectious){
        vector<vector<int>> infectionChange; // Keeps track of susceptible people who have become infected
        vector<vector<int>> recoverChange; // Keeps track of infected people who have become recovered
        vector<vector<int>> infectionPeriodChange; // Keeps track of which infection periods need to be decreased
        int dailyInfectiousCount = 0;
        int countS = 0; // Count susceptible each round
        int countR = 0; // Count recovered each round
        int countV = 0; // Count vaccinated each round
        // Set flag
        hasInfectious = false;

        outputRegionState(region,height,width,day);

        

        //Run through for susceptibility analysis
        int infectedAround = 0;
        for (int i = 0; i<height; i++){
            for (int j = 0; j< width; j++){
                
                 // Check for and apply recovery or infection based on the state at the day's start
                if (region[i][j].state == I) {
                    
                    //check for howmany infected
                    dailyInfectiousCount++;
                    hasInfectious = true;

                    if (region[i][j].infectionLen <= 0) {
                        recoverChange.push_back({i,j}); // Infectious period is over, recover
                    } else {
                        hasInfectious = true;
                        infectionPeriodChange.push_back({i,j}); //The infected person is still recovering
                    }
                } else if (region[i][j].state == S) {
                    int infectedAround = checkAround(region, i, j, height, width);
                    if (infectedAround >= infectiousThreshold) {
                        //There are alot of infected around so this person has become infected
                        infectionChange.push_back({i,j});
                        hasInfectious = true;
                    }
                } else if (region[i][j].state == R){
                    countR++;
                } 
                else if (region[i][j].state == V){
                    countV++;
                } 
                
            }
        }

       // Apply the accumulated changes for the day
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
              if(!infectionChange.empty()){  
                    for (const auto& coord : infectionChange) {
                        if (coord[0] == i && coord[1] == j) {
                            region[i][j].state = I;
                            region[i][j].infectionLen--;
                            break; // Coordinate found, no need to continue the inner loop
                        }
                    }
                }
                if(!infectionPeriodChange.empty()){  
                    for (const auto& coord : infectionPeriodChange) {
                        if (coord[0] == i && coord[1] == j) {
                            region[i][j].infectionLen--;
                            break; // Coordinate found, no need to continue the inner loop
                        }
                    }
                }
                if(!recoverChange.empty()){  
                    for (const auto& coord : recoverChange) {
                        if (coord[0] == i && coord[1] == j) {
                            region[i][j].state = R;
                            region[i][j].infectionLen = 0;
                            break; // Coordinate found, no need to continue the inner loop
                        }
                    }
                }
                
            }
            
        }

        //next day

        if (dailyInfectiousCount > peakInfectious) {
            peakInfectious = dailyInfectiousCount;
            peakDay = day;
        }
        totalInfectious += dailyInfectiousCount;
        vaccinatedCount = countV;
        susceptibleCount = countS;
        recoveredCount = countR;

        

        day++;
    }

    cout << "The outbreak took " << day << " days to end." << endl;
    cout << "The peak infectious count was " << peakInfectious << " people at day " << peakDay << "." << endl;
    double averageInfectious = static_cast<double>(totalInfectious) / day;
    cout << "The average number of infectious people per day was " << fixed << setprecision(2) << averageInfectious << " people." << endl;
    cout << "The final counts of susceptible, infectious, recovered, and vaccinated people was: " << endl;
    cout << "Susceptible: " << susceptibleCount << endl;
    cout << "Infectious:  " << "0" << endl;
    cout << "Recovered:   " << recoveredCount << endl;
    cout << "Vaccinated:  " << vaccinatedCount << endl;
} 

int checkAround(Person** region, int x, int y, int height, int width){
    int counter = 0;

    // Above
    if (x > 0 && region[x-1][y].state == I)
        counter++;
    // Below
    if (x < height-1 && region[x+1][y].state == I)
        counter++;
    // Left
    if (y > 0 && region[x][y-1].state == I)
        counter++;
    // Right
    if (y < width-1 && region[x][y+1].state == I)
        counter++;
    // Top left diagonal
    if (x > 0 && y > 0 && region[x-1][y-1].state == I)
        counter++;
    // Top right diagonal
    if (x > 0 && y < width-1 && region[x-1][y+1].state == I)
        counter++;
    // Bottom left diagonal
    if (x < height-1 && y > 0 && region[x+1][y-1].state == I)
        counter++;
    // Bottom right diagonal
    if (x < height-1 && y < width-1 && region[x+1][y+1].state == I)
        counter++;

    return counter;
}
