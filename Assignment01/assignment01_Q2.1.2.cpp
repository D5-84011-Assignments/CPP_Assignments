#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() {
        day = 0;
        month = 0;
        year = 0;
    }

    void initDate() {
        day = 0;
        month = 0;
        year = 0;
    }

    void printDateOnConsole() {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }

    void acceptDateFromConsole() {
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
    }

    bool isLeapYear() {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            return true;
        else
            return false;
    }

    // Getter functions
    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }
};

int main() {
    Date date;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Initialize date\n";
        cout << "2. Enter date\n";
        cout << "3. Print entered date\n";
        cout << "4. Check if leap year\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                date.initDate();
                cout << "Date initialized.\n";
                break;
            case 2:
                date.acceptDateFromConsole();
                break;
            case 3:
                if (date.getDay() != 0 && date.getMonth() != 0 && date.getYear() != 0) {
                    date.printDateOnConsole();
                } else {
                    cout << "Please enter a date first.\n";
                }
                break;
            case 4:
                if (date.getYear() != 0) {
                    if (date.isLeapYear())
                        cout << date.getYear() << " is a leap year.\n";
                    else
                        cout << date.getYear() << " is not a leap year.\n";
                } else {
                    cout << "Please enter a date first.\n";
                }
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}