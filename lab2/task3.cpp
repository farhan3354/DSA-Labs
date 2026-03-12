#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    int pages;

    Book() {}

    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};
class Newspaper {
public:
    string name;
    string date;
    string edition;

    Newspaper() {}

    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};
class Library {
private:
    Book books[50];
    Newspaper newspapers[50];
    int bookCount = 0;
    int newspaperCount = 0;

public:

    void addBook(Book b) {
        books[bookCount] = b;
        bookCount++;
    }

    void addNewspaper(Newspaper n) {
        newspapers[newspaperCount] = n;
        newspaperCount++;
    }

    void displayCollection() {
        cout << "\nBooks "<<endl;
        for (int i = 0; i < bookCount; i++) {
            books[i].display();
            cout << endl;
        }
        cout << "\nNewspapers "<<endl;
        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i].display();
            cout << endl;
        }
    }

    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = i + 1; j < bookCount; j++) {
                if (books[i].pages > books[j].pages) {
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; i++) {
            for (int j = i + 1; j < newspaperCount; j++) {
                if (newspapers[i].edition > newspapers[j].edition) {
                    Newspaper temp = newspapers[i];
                    newspapers[i] = newspapers[j];
                    newspapers[j] = temp;
                }
            }
        }
    }

    Book* searchBookByTitle(string title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].title == title) {
                return &books[i];
            }
        }
        return NULL;
    }

    Newspaper* searchNewspaperByName(string name) {
        for (int i = 0; i < newspaperCount; i++) {
            if (newspapers[i].name == name) {
                return &newspapers[i];
            }
        }
        return NULL;
    }
};
int main() {

Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
Book book2("To Kill a Mockingbird", "Harper Lee", 324);

Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

Library library;

library.addBook(book1);
library.addBook(book2);
library.addNewspaper(newspaper1);
library.addNewspaper(newspaper2);

cout << "Before Sorting:\n";
library.displayCollection();

library.sortBooksByPages();
library.sortNewspapersByEdition();

cout << "\nAfter Sorting:\n";
library.displayCollection();

Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");

if (foundBook) {
    cout << "\nFound Book:\n";
    foundBook->display();
}
else {
    cout << "\nBook not found.\n";
}

Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");

if (foundNewspaper) {
    cout << "\nFound Newspaper:\n";
    foundNewspaper->display();
}
else {
    cout << "\nNewspaper not found.\n";
}

return 0;
}