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
    
    inFile.close();

    // Sort the books by author name
    sort(books.begin(), books.end(), compareByAuthor);

    // Output the sorted book details
    ofstream outFile("sorted_books.txt");
    for (const auto& book : books) {



    
outFile << book.book_id << ","
                << book.author_name << ","
                << book.price << ","
                << book.no_of_pages << ","
                << book.publisher << ","
                << book.year_of_publishing << endl;
    }
    outFile.close();

    cout << "Books sorted by author name and saved to sorted_books.txt." << endl;

    return 0;
}
