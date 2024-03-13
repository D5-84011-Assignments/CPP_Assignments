#include <iostream>

using namespace std;

class date
{
private:
    int day;
    int month;
    int year;

public:
    date()
    {
        this->day;
        this->month;
        this->year;
    }

    date(int day, int month, int hour)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void acceptDate()
    {
        cout << "Enter the day - ";
        cin >> day;
        cout << "Enter the month - ";
        cin >> month;
        cout << "Enter the year - ";
        cin >> year;
    }

    void displayDate()
    {
        cout << "Date - " << day << "/" << month << "/" << year << endl;
    }

    int getDay()
    {
        return this->day;
    }

    void setDay(int day)
    {
        this->day = day;
    }

    int getMonth()
    {
        return this->month;
    }

    void setMonth(int month)
    {
        this->month = month;
    }

    int getYear()
    {
        return this->year;
    }

    void setYear(int year)
    {
        this->year = year;
    }
};

class employee
{
private:
    int id;
    float salary;
    string department;
    date doj;

public:
    employee()
    {
        this->id;
        this->salary;
        this->department;
    }

    employee(int id, float salary, string department)
    {
        this->id = id;
        this->salary = salary;
        this->department = department;
    }

    void acceptEmployee()
    {
        cout << "Enter the id - ";
        cin >> id;
        cout << "Enter the salary - ";
        cin >> salary;
        cout << "Enter the department - ";
        cin >> department;
        cout << "Enter date of joining " << endl;
        doj.acceptDate();
    }

    void displayEmployee()
    {
        cout << "id - " << id << endl;
        cout << "salary - " << salary << endl;
        cout << "department - " << department << endl;
        cout << "joining - ";
        doj.displayDate();
    }

    int getId()
    {
        return this->id;
    }

    void setId(int id)
    {
        this->id = id;
    }

    float getSalary()
    {
        return this->salary;
    }

    void setSalary(float salary)
    {
        this->salary = salary;
    }

    string getDepartment()
    {
        return this->department;
    }

    void setDepartment(string getDepartment)
    {
        this->department = department;
    }
};

class person
{
private:
    string name;
    string address;
    date dob;

public:
    person()
    {
        this->name;
        this->address;
    }

    person(string name, string address)
    {
        this->name = name;
        this->address = address;
    }

    void acceptPerson()
    {
        cout << "Enter the name - ";
        cin >> name;
        cout << "Enter the address - ";
        cin >> address;
        cout << "Enter date of birth - " << endl;
        dob.acceptDate();
    }

    void displayPerson()
    {
        cout << "name - " << name << endl;
        cout << "address - " << address << endl;
        cout << "Birth ";
        dob.displayDate();
    }

    string getName()
    {
        return this->name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getAddress()
    {
        return this->address;
    }

    void setAddress(string address)
    {
        this->address = address;
    }
};

int main()
{
    employee e1;
    e1.acceptEmployee();
    e1.displayEmployee();

    date d1;
    d1.acceptDate();
    d1.displayDate();

    person p1;
    p1.acceptPerson();
    p1.displayPerson();

    return 0;
}
