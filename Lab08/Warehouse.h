/* Author: Andrew D'Angelo
   Date: 04/01/2024
   Description: This program simulates a warehouse inventory tracker.In this program you can add, remove, and/or output the quantity of items in your inventory.
*/

#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <string>
#include <iostream>

using namespace std;

class Warehouse {
private:
    int totalGoods;

public:
    Warehouse(int initialGoods);
    int getTotalGoods() const;
    void addGoods();
    void removeGoods();
};

#endif