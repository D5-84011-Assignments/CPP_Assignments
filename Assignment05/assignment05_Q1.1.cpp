#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() {}
    Date(int day, int month, int year) : day(day), month(month), year(year) {}

    void display() {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }

    void accept() {
        cout << "day: ";
        cin >> day;
        cout << "month: ";
        cin >> month;
        cout << "year: ";
        cin >> year;
    }
};

class Person {
private:
    string name;
    string addr;
    Date birthdate;

public:
    Person() {}
    Person(string name, string addr, Date birthdate) : name(name), addr(addr), birthdate(birthdate) {}

    void display() {
        cout << "Name: " << name << endl;
        cout << "Address: " << addr << endl;
        cout << "Birth ";
        birthdate.display();
    }

    void accept() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter address: ";
        cin >> addr;

        cout << "Enter birthdate" << endl;
        birthdate.accept();
    }
};

class Employee : public Person {
private:
    int id;
    float sal;
    string dept;
    Date joining;

public:
    Employee() {}
    Employee(int id, float sal, string dept, Date joining) : id(id), sal(sal), dept(dept), joining(joining) {}

    void display() {
        Person::display();
        cout << "Id: " << id << endl;
        cout << "Salary: " << sal << endl;
        cout << "Department: " << dept << endl;
        cout << "Joining ";
        joining.display();
    }

    void accept() {
        Person::accept();
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter salary: ";
        cin >> sal;
        cout << "Enter department: ";
        cin >> dept;
        cout << "Enter joining date" << endl;
        joining.accept();
    }
};

int main() {
    Employee e;
    e.accept();
    e.display();

    return 0;
}