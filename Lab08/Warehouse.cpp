/* Author: Andrew D'Angelo
   Date: 04/01/2024
   Description: This program simulates a warehouse inventory tracker.In this program you can add, remove, and/or output the quantity of items in your inventory.
*/

#include "Warehouse.h"
using namespace std;

Warehouse::Warehouse(int initialGoods) : totalGoods(initialGoods) {}

/**
 * @brief Getter function that returns the total number of goods
*/
int Warehouse::getTotalGoods() const {
    return totalGoods;
}

/**
 * @brief Setter function that requests the user how many goods to add and increments a counter.
*/
void Warehouse::addGoods() {
    int goodsToAdd;
    cout << "How many goods would you like to add: ";
    cin >> goodsToAdd;
    totalGoods += goodsToAdd;
}

/**
 * 
 * @brief Setter function that requests the user how many goods to remove and decrements a counter.
*/
void Warehouse::removeGoods() {
    int goodsToRemove;
    cout << "How many goods would you like to remove: ";
    cin >> goodsToRemove;
    if (goodsToRemove > totalGoods) {
        cout << "You do not have that many goods!\n";
    } else {
        totalGoods -= goodsToRemove;
    }
}