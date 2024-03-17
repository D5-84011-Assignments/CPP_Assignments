#include <iostream>
#include <string>

using namespace std;

class Product {
protected:
    int id;
    string title;
    double price;

public:
    Product(int _id, const string& _title, double _price) : id(_id), title(_title), price(_price) {}
    virtual double calculateDiscountedPrice() = 0;
    virtual void displayInfo() = 0;
    double getPrice() const { return price; }
    int getId() const { return id; } // Getter method for id
};

class Book : public Product {
private:
    string author;

public:
    Book(int _id, const string& _title, const string& _author, double _price) : Product(_id, _title, _price), author(_author) {}
    double calculateDiscountedPrice() override {
        return price - (0.1 * price); // 10% discount for books
    }
    void displayInfo() override {
        cout << "Book ID: " << id << ", Title: " << title << ", Author: " << author << ", Price: Rs." << price << endl;
    }
};

class Tape : public Product {
private:
    string artist;

public:
    Tape(int _id, const string& _title, const string& _artist, double _price) : Product(_id, _title, _price), artist(_artist) {}
    double calculateDiscountedPrice() override {
        return price - (0.05 * price); // 5% discount for tapes
    }
    void displayInfo() override {
        cout << "Tape ID: " << id << ", Title: " << title << ", Artist: " << artist << ", Price: Rs." << price << endl;
    }
};

int main() {
    const int numProducts = 6;
    Product* products[numProducts] = {
        new Book(1, "The boy who loved", "Durjoy Datta", 200.0),
        new Tape(2, "RED", "Taylor Swift", 1500.5),
        new Book(3, "Two States", "Chetan Bhagat", 188.0),
        new Tape(4, "Amazing Dragons", "Dan Raynolds", 1299.0),
        new Book(5, "The kite runner", "Khaleed Houseini", 422.0),
        new Tape(6, "Atomic Habits", "James Clear", 417.0)
    };

    int choice;
    double totalBill = 0;

    cout << "Welcome to the Book & Tape Store!" << endl;

    for (int i = 0; i < 3; ++i) {
        cout << "\nChoose a product category:" << endl;
        cout << "1. Books" << endl;
        cout << "2. Tapes" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Available Books:" << endl;
            for (int j = 0; j < numProducts; ++j) {
                if (dynamic_cast<Book*>(products[j]) != nullptr) {
                    products[j]->displayInfo();
                }
            }
        } else if (choice == 2) {
            cout << "Available Tapes:" << endl;
            for (int j = 0; j < numProducts; ++j) {
                if (dynamic_cast<Tape*>(products[j]) != nullptr) {
                    products[j]->displayInfo();
                }
            }
        } else {
            cout << "Invalid choice! Please enter 1 or 2." << endl;
            --i; // To repeat the loop for invalid choice
            continue;
        }

        cout << "Enter the ID of the product you want to purchase: ";
        cin >> choice;

        bool found = false;
        for (int j = 0; j < numProducts; ++j) {
            if (products[j]->getPrice() > 0 && products[j]->calculateDiscountedPrice() > 0 && products[j]->getId() == choice) {
                totalBill += products[j]->calculateDiscountedPrice();
                products[j]->displayInfo();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Product not found or out of stock!" << endl;
        }
    }

    cout << "\nYour total bill is: Rs." << totalBill << endl;

    // Free memory
    for (int i = 0; i < numProducts; ++i) {
        delete products[i];
    }

    return 0;
}