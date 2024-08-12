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
