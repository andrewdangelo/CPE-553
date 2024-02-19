/* Author: Andrew D'Angelo
   Date: 02/19/2024
   Description: This program allows a user to output an ASCII image and applies a border using a custom symbol around the whole image.
*/

#ifndef PAINTER_FUNCS_H
#define PAINTER_FUNCS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void readFile(const string& filePath);

int intro(char &borderSymbol);
void printHeaderFooter(char border, int size);
void sleepingCat(char border);
void sailingShip(char border);
void appleComputer(char border);
void dogPic(char border);
void blank(char border);

#endif
