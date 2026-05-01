#include <iostream>
#include <cstring>
using namespace std;

class Book {
public:
    int id;
    char title[50];
    char author[50];
    bool isIssued;

    void addBook() {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Title: ";
        cin.getline(title, 50);
        cout << "Enter Author: ";
        cin.getline(author, 50);
        isIssued = false;
    }

    void displayBook() {
        cout << "\nID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nStatus: " << (isIssued ? "Issued" : "Available") << endl;
    }
};

class Library {
    Book books[100];
    int count = 0;

public:
    void addBook() {
        books[count].addBook();
        count++;
        cout << "Book Added Successfully!\n";
    }

    void displayAll() {
        if (count == 0) {
            cout << "No books available!\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            books[i].displayBook();
        }
    }

    void searchByTitle() {
        char t[50];
        cin.ignore();
        cout << "Enter Title to search: ";
        cin.getline(t, 50);

        for (int i = 0; i < count; i++) {
            if (strcmp(books[i].title, t) == 0) {
                books[i].displayBook();
                return;
            }
        }
        cout << "Book not found!\n";
    }

    void searchByAuthor() {
        char a[50];
        cin.ignore();
        cout << "Enter Author to search: ";
        cin.getline(a, 50);

        for (int i = 0; i < count; i++) {
            if (strcmp(books[i].author, a) == 0) {
                books[i].displayBook();
                return;
            }
        }
        cout << "Book not found!\n";
    }

    void issueBook() {
        int id;
        cout << "Enter Book ID to issue: ";
        cin >> id;

        for (int i = 0; i < count; i++) {
            if (books[i].id == id) {
                if (!books[i].isIssued) {
                    books[i].isIssued = true;
                    cout << "Book Issued Successfully!\n";
                } else {
                    cout << "Book already issued!\n";
                }
                return;
            }
        }
        cout << "Book not found!\n";
    }

    void returnBook() {
        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;

        for (int i = 0; i < count; i++) {
            if (books[i].id == id) {
                if (books[i].isIssued) {
                    books[i].isIssued = false;
                    cout << "Book Returned Successfully!\n";
                } else {
                    cout << "Book was not issued!\n";
                }
                return;
            }
        }
        cout << "Book not found!\n";
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search by Title\n";
        cout << "4. Search by Author\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.displayAll(); break;
            case 3: lib.searchByTitle(); break;
            case 4: lib.searchByAuthor(); break;
            case 5: lib.issueBook(); break;
            case 6: lib.returnBook(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}