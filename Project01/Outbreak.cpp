#include "Outbreak.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>



using namespace std;

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
                grid[row][col].infectionLen = (grid[row][col].state == I) ? config->infectiousPeriod : 0; // Initialize based on state
            }
            ++row;
        }
    }
    
    regionFile.close();
    return grid;
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
    int infectiousCounter = 0;

    do{
        //Check for infectious in the region and increase counter when found.
        for (int i = 0; i<height; i++){
            for (int j = 0; j< width; j++){
                if (region[i][j].state == I){
                    infectiousCounter++;
                }
            }
        }

        cout<<infectiousCounter<<endl;
        break;
    }
    while (infectiousCounter > 0);
}

int main(){
    int height, width, infectiousThreshold;
    string regionFileName;
    Person** region = readData(height, width, infectiousThreshold);

    // the initial state of the region should be output as Day 0
    outputRegionState(region,height,width,0);
    simulate(region,height,width,0);

    return 0;
}