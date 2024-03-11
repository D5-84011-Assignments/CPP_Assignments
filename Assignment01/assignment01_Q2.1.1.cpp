#include <iostream>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;

    void initDate()
    {
        day = 0;
        month = 0;
        year = 0;
    }

    void printDateOnConsole()
    {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }

    void acceptDateFromConsole()
    {
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
    }

    bool isLeapYear()
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Date date;
    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Initialize date\n";
        cout << "2. Enter date\n";
        cout << "3. Print entered date\n";
        cout << "4. Check if leap year\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            date.initDate();
            cout << "Date initialized.\n";
            break;
        case 2:
            date.acceptDateFromConsole();
            break;
        case 3:
            if (date.day != 0 && date.month != 0 && date.year != 0)
            {
                date.printDateOnConsole();
            }
            else
            {
                cout << "Please enter a date first.\n";
            }
            break;
        case 4:
            if (date.year != 0)
            {
                if (date.isLeapYear())
                    cout << date.year << " is a leap year.\n";
                else
                    cout << date.year << " is not a leap year.\n";
            }
            else
            {
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