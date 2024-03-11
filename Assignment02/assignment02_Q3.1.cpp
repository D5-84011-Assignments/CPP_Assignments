#include <iostream>
#include <string>

namespace Nstudent
{
    class Student
    {
    private:
        int rollNo;
        std::string name;
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
            std::cout << "Roll No: " << rollNo << std::endl;
            std::cout << "Name: " << name << std::endl;
            std::cout << "Marks: " << marks << std::endl;
        }

        void acceptStudentFromConsole()
        {
            std::cout << "Enter Roll No: ";
            std::cin >> rollNo;
            std::cout << "Enter Name: ";
            std::cin.ignore();
            std::getline(std:: cin,name);
            std::cout << "Enter Marks: ";
            std::cin >> marks;
        }
    };
}

int main()
{
    Nstudent ::Student student;
    int choice;

    do
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Initialize student\n";
        std::cout << "2. Enter student details\n";
        std::cout << "3. Print student details\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            student.initStudent();
            std::cout << "Student initialized.\n";
            break;
        case 2:
            student.acceptStudentFromConsole();
            break;
        case 3:
            std::cout << "\nStudent Details:\n";
            student.printStudentOnConsole();
            break;
        case 4:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 0);

    return 0;
}