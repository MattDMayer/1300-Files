#include <iostream>
#include "Book.h"
#include <fstream>
using namespace std;

int main(){
    Book test("Harry Potter", "JK", "Fantasy");
    cout << test.getAuthor() << endl;
    cout << test.getTitle() << endl;
    cout << test.getGenre() << endl;
}
