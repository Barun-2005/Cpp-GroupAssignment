#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Book {
    string book_id;
    string author_name;
    double price;
    int no_of_pages;
    string publisher;
    int year_of_publishing;
};
// Function to compare books by author name
bool compareByAuthor(const Book& a, const Book& b) {
    return a.author_name < b.author_name;
}

int main() {
    ifstream inFile("books.txt");
    vector<Book> books;
    string line;

    // Reading the file and parsing book details

