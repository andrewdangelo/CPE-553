#include "Outbreak.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

struct configData {
    int height;
    int width;
    int infectiousPeriod;
    int infectiousThreshold;
    string regionFileName;
};

/**
 * @brief Reads simulation configuration and initial population state from an input source.
 * 
 * @param height Reference to store the height of the simulation region.
 * @param width Reference to store the width of the simulation region.
 * @param infectiousThreshold Reference to store the number of days a person remains infectious.
 
 */
void readData(int& height, int& width, int& infectiousThreshold) {
    string configFileName;
    ifstream configFile;
    string line;
    configData config;

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
        size_t position = line.find(":");
        if (position != string::npos) {
                string info = line.substr(position + 1);
                info.erase(0, info.find_first_not_of(" \t"));

                if (line.find("Region Height") != string::npos) {
                    config.height = stoi(info);
                } else if (line.find("Region Width") != string::npos) {
                    config.width = stoi(info);
                } else if (line.find("Threshold") != string::npos) {
                    config.infectiousThreshold = stoi(info);
                } else if (line.find("Infectious Period") != string::npos) {
                    config.infectiousPeriod = stoi(info);
                } else if (line.find("Region File") != string::npos) {
                    config.regionFileName = info;
                }
            }
    }
    
    cout<<config.height<< config.width<< config.regionFileName<<endl;
}

int main(){
    int height = 0;
    int width = 0;
    int infectiousThreshold = 0;

    readData(height, width, infectiousThreshold);

    return 0;
}