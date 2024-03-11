#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    float marks;

public:
    void initStudent()
    {
        rollNo = 0;
        name = "";
        marks = 0.0;
    }

    void printStudentOnConsole()
    {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }

    void acceptStudentFromConsole()
    {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore(); 
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }
};

int main()
{
    Student student;
    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Initialize student\n";
        cout << "2. Enter student details\n";
        cout << "3. Print student details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            student.initStudent();
            cout << "Student initialized.\n";
            break;
        case 2:
            student.acceptStudentFromConsole();
            break;
        case 3:
            cout << "\nStudent Details:\n";
            student.printStudentOnConsole();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}