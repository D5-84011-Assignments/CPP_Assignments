#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    float sal;

public:
    Employee()
    {
        id = 0;
        sal = 0;
    }
    Employee(int id, float sal)
    {
        this->id = id;
        this->sal = sal;
    }
    void setId(int id)
    {
        this->id = id;
    }
    int getId()
    {
        return id;
    }
    void setSal(int sal)
    {
        this->sal = sal;
    }
    float getSal()
    {
        return sal;
    }

    virtual void display()
    {
        cout << "Id: " << id << endl;
        cout << "Salary: " << sal << endl;
    }
    virtual void accept()
    {
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter salary: ";
        cin >> sal;
    }

    virtual ~Employee()
    {
    }
};

class Manager : virtual public Employee
{
private:
    float bonus;

protected:
    void displayManager()
    {
        Employee::display();
        cout << "Bonus: " << bonus << endl;
    }
    void acceptManager()
    {
        Employee::accept();
        cout << "Enter bonus: ";
        cin >> bonus;
    }

public:
    Manager()
    {
        bonus = 0;
    }
    Manager(int id, float sal, float bonus) : Employee(id, sal)
    {

        this->bonus = bonus;
    }
    void setBonus(int bonus)
    {
        this->bonus = bonus;
    }
    float getBonus()
    {
        return bonus;
    }
    void display()
    {
        Employee::display();
        cout << "Bonus: " << bonus << endl;
    }
    void accept()
    {
        Employee::accept();
        cout << "Enter bonus: ";
        cin >> bonus;
    }

    virtual ~Manager()
    {
    }
};

class Salesman : virtual public Employee
{
private:
    float comm;

protected:
    void displaySalesman()
    {
        cout << "Commission: " << comm << endl;
    }
    void acceptSalesman()
    {
        cout << "Enter commission: ";
        cin >> comm;
    }

public:
    Salesman()
    {
        comm = 0;
    }
    Salesman(int id, float sal, float comm) : Employee(id, sal)
    {

        this->comm = comm;
    }
    void setComm(int comm)
    {
        this->comm = comm;
    }
    float getComm()
    {
        return comm;
    }
    void display()
    {
        Employee::display();
        cout << "Commission: " << comm << endl;
    }
    void accept()
    {

        Employee::accept();
        cout << "Enter commission: ";
        cin >> comm;
    }
    virtual ~Salesman()
    {
    }
};

class SalesManager : public Manager, public Salesman
{

public:
    SalesManager() {}
    SalesManager(int id, float sal, float bonus, float comm)
    {
        this->setId(id);
        this->setSal(sal);
        this->setBonus(bonus);
        this->setComm(comm);
    }
    void display()
    {
        Manager::displayManager();
        Salesman::displaySalesman();
    }
    void accept()
    {
        Manager::acceptManager();
        Salesman::acceptSalesman();
    }
    virtual ~SalesManager()
    {
    }
};

int menu()
{
    int choice;
    cout << "0. Exit" << endl;

    cout << "1. Add Manager" << endl;
    cout << "2. Add Salesman" << endl;
    cout << "3. Add SalesManager" << endl;
    cout << "4. Display All Managers" << endl;
    cout << "5. Display All Salesmen" << endl;
    cout << "6. Display All SalesMangers" << endl;
    cout << "7. Display All Employees" << endl;
    cout << "8. Display the count of all employees with respect to designation" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;
    return choice;
}

int main()
{
    int size = 10;
    int choice, count = 0;
    int nm = 0, ns = 0, nsm = 0;
    Employee *e[size];
    for (int i = 0; i < count; i++)
    {
        e[i] = NULL;
    }
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            if (count < size)
            {
                e[count] = new Manager();
                e[count]->accept();
                count++;
            }
            else
                cout << "Array is full" << endl;
            break;
        case 2:
            if (count < size)
            {
                e[count] = new Salesman();
                e[count]->accept();
                count++;
                
            }
            else
                cout << "Array is full" << endl;
            break;
        case 3:
            if (count < size)
            {
                e[count] = new SalesManager();
                e[count]->accept();
                count++;
                
            }
            else
                cout << "Array is full" << endl;
            break;
        case 4:
            for (int i = 0; i < count; i++)
            {
                if (typeid(*e[i]) == typeid(Manager)){
                    e[i]->display();
                nm++;
                }
            }
            break;
        case 5:
            for (int i = 0; i < count; i++)
            {
                if (typeid(*e[i]) == typeid(Salesman)){
                    e[i]->display();
                    ns++;
                }
            }
            break;
        case 6:
            for (int i = 0; i < count; i++)
            {
                if (typeid(*e[i]) == typeid(SalesManager)){
                    e[i]->display();
                    nsm++;
                }
            }
            break;
        case 7:
            for (int i = 0; i < count; i++)
            {
                e[i]->display();
            }
            break;
        case 8:
            cout << "No. of Managers: " << nm << endl
                 << "No. of Salesmen: " << ns << endl
                 << "No. of SalesManagers: " << nsm << endl;
            break;
        default:
            cout << "Invalid Choice....." << endl;
            break;
        }
    }

    for (int i = 0; i < count; i++)
    {

        delete e[i];
    }
    cout << "Thank you....." << endl;

    return 0;
}