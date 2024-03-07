#include "Outbreak.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<iomanip>
#include <vector>

using namespace std;

int main()
{
    int height = 0, width = 0, infectiousThreshold = 0;
    
    Person** region = readData(height, width, infectiousThreshold);

    // the initial state of the region should be output as Day 0
    
    simulate(region,height,width,infectiousThreshold);


    return 0;
}