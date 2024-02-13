/* Author: Andrew D'Angelo
   Date: 02/05/2024
   Description: This program determines the proper order for a bookshelf based on the alphabetical significance of the title.
*/


#include <iostream>
#include <string>

using namespace std;

int main() {
    // Existing books (in lowercase)
    string book1 = "cryptonomicon";
    string book2 = "i, robot";
    string book3 = "neuromancer";

    
    // Get the title of the new book
    string newBook, lastBook;;
    cout << "Please enter the name of your new book (in all lowercase): ";
    getline(cin, newBook);

    // Convert new book title to lowercase
    for (char& c : newBook) {
        c = tolower(c);
    }

    // Check if the new book matches any of the existing books
    if (newBook.compare(book1) == 0 || newBook.compare(book2) == 0 || newBook.compare(book3) == 0) {
        cout << "You already have a copy of " << newBook<< endl;
    } else {
        if (newBook.compare(book1) < 0) {
            lastBook = book3;
            book3 = book2;
            book2 = book1;
            book1 = newBook;
        } else if (newBook.compare(book2) < 0) {
            lastBook = book3;
            book3 = book2;
            book2 = newBook;
        } else if (newBook.compare(book3) < 0) {
            lastBook = book3;
            book3 = newBook;
        } else {
            lastBook = newBook; // If the new book does not precede any existing books
        }
        
        // Output all books in the correct order
        cout << "Books on the bookshelf in ascending lexicographic order (i.e. a-z):" << endl;
        cout << book1 << endl;
        cout << book2 << endl;
        cout << book3 << endl;

        //Manage the output if there is a newBook that is last
        if (!lastBook.empty()) {
            cout << lastBook << endl;
        }
    }

    return 0;
}