/* Author: Andrew D'Angelo
   Date: 04/01/2024
   Description: This program simulates a warehouse inventory tracker.In this program you can add, remove, and/or output the quantity of items in your inventory.
*/

#include "Warehouse.h"
using namespace std;

int main() {
    Warehouse warehouse(0); // Start with 0 goods
    int choice;

    // Persistent menu with options to add, remove, output and quit.

    do {
        cout << "Please select from the following options:\n"
             << "1: Add Goods\n"
             << "2: Remove Goods\n"
             << "3: Output Total Goods\n"
             << "4: Quit\n"
             << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                warehouse.addGoods();
                break;
            case 2:
                warehouse.removeGoods();
                break;
            case 3:
                cout << "There are " << warehouse.getTotalGoods() << " number of goods in the warehouse.\n";
                break;
            case 4:
                cout << "Good bye!\n";
                break;
            default:
                cout << "Invalid option, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
