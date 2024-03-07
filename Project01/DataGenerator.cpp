#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime> 
#include <string>

using namespace std;

/**
 * @brief This function generates and write out the user information for a config file using the fstream library.
 * @param configFileName Name of the config file the user wants to generate.
 * @param regionFileName Name of the region file the user will generate or point to.
 * @param height Region height.
 * @param width Region width.
 * @param threshold Infectious threshold for simulation.
 * @param infectiousPeriod Infectious period for individuals in the region.
*/
void writeConfigFile(const string& configFileName, const string& regionFileName, int height, int width, int threshold, int infectiousPeriod) {
    ofstream configFile(configFileName);
    if (configFile.is_open()) {
        configFile << "Region Height:" << height << "\n";
        configFile << "Region Width:" << width << "\n";
        configFile << "Threshold:" << threshold << "\n";
        configFile << "Infectious Period:" << infectiousPeriod << "\n";
        configFile << "Region File:" << regionFileName << "\n";
        configFile.close();
    } else {
        cout << "Unable to open the config file for writing." << endl;
    }
}


/**
 * @brief Writes the region file with randomly distributed infectious and vaccinated individuals using the srand function from cstdlib.
 *
 * 
 * @param regionFileName Name of the region file the user will generate
 * @param height Region height.
 * @param width Region width.
 * @param infectious The initial number of infectious individuals in the region.
 * @param vaccinated The number of vaccinated individuals in the region.
 */
void writeRegionFile(const string& regionFileName, int height, int width, int infectious, int vaccinated) {
    vector<vector<char>> region(height, vector<char>(width, 'S')); // Initialize region with susceptible to make a grid so I don't forget about susceptibles :)
    
    // Initialize random seed for the random placement of positions
    srand(time(nullptr));


    // Randomly distribute infectious individuals throughout the region
    int placed = 0;
    while (placed < infectious) {
        int row = rand() % height;
        int col = rand() % width;
        if (region[row][col] == 'S') {
            region[row][col] = 'I';
            placed++;
        }
    }

    // Randomly distribute vaccinated individuals throughout the region
    placed = 0;
    while (placed < vaccinated) {
        int row = rand() % height;
        int col = rand() % width;
        if (region[row][col] == 'S') {
            region[row][col] = 'V';
            placed++;
        }
    }

    // Open the region and write the grid to match the proper region format.
    ofstream regionFile(regionFileName);
    if (regionFile.is_open()) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                regionFile << region[i][j];
                if (j < width - 1) regionFile << ","; //insert the commas
            }
            regionFile << "\n";
        }
        regionFile.close();
    } else {
        cout << "Unable to open the region file for writing." << endl;
    }
}

int main() {
    string configFileName, regionFileName;
    int height, width, infectious, vaccinated, threshold, infectiousPeriod;

    // Get user input for the generation of the files
    cout << "Enter the name of the configuration file: ";
    cin >> configFileName;
    cout << "Enter the name of the region file: ";
    cin >> regionFileName;
    cout << "Enter the initial number of infectious individuals: ";
    cin >> infectious;
    cout << "Enter the number of vaccinated individuals: ";
    cin >> vaccinated;
    cout << "Enter the height of the region: ";
    cin >> height;
    cout << "Enter the width of the region: ";
    cin >> width;
    cout << "Enter the infectious threshold: ";
    cin >> threshold;
    cout << "Enter the infectious period: ";
    cin >> infectiousPeriod;

    // Call functions to generate files
    writeConfigFile(configFileName, regionFileName, height, width, threshold, infectiousPeriod);
    writeRegionFile(regionFileName, height, width, infectious, vaccinated);

    cout << "Files generated..." << endl;
    return 0;
}
