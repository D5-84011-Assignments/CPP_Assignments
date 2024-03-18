#include <iostream>
using namespace std;

class InsufficientFunds
{
private:
    int accid;
    double cur_balance;
    double withdraw_balance;

public:
    InsufficientFunds(int accid, double cur_balance, double withdraw_balance)
    {
        this->accid = accid;
        this->cur_balance = cur_balance;
        this->withdraw_balance = withdraw_balance;
    }
    void display()
    {
        cout << "Insufficient funds- Withdraw should not be more than balance in account " << endl;
    }
};
enum AccountType
{
    SAVING = 1,
    CURRENT = 2,
    DMAT = 3
};
int acctmenu()
{
    int a;
    cout << "1.Savings  2.Current   3.DMAT   Enter type:  ";
    cin >> a;
    return a;
}

class Account
{
private:
    int id;
    AccountType type;
    double balance;

public:
    Account()
    {
        id = 0;
        type = SAVING;
        balance = 10000;
    }
    Account(int id, AccountType type, double balance)
    {
        this->id = id;
        this->type = type;
        this->balance = balance;
    }
    void accept()
    {
        cout << "Enter id: ";
        cin >> id;
        switch (acctmenu())
        {
        case SAVING:
            cout << "Savings Account" << endl;
            break;
        case CURRENT:
            cout << "Current Account" << endl;
            break;
        case DMAT:
            cout << "DMAT Account" << endl;
            break;
        default:
            cout << "Invalid Choice..." << endl;
            break;
        }

        cout << "Enter Balance: ";
        cin >> balance;
        if (balance < 0)
        {
            balance = 0;
            throw 2;
        }
    }
    void display()
    {
    }
    void setId(int id)
    {
        this->id = id;
    }
    int getId()
    {
        return id;
    }
    void setType(AccountType type)
    {
        this->type = type;
    }
    AccountType getType()
    {
        return type;
    }
    void setBalance(double balance)
    {
        this->balance = balance;
    }
    double getBalance()
    {
        return balance;
    }
    void deposit(double amount)
    {
        if (amount < 0)
        {
            amount = 0;
            throw 2;
        }
        balance = balance + amount;
        cout << "Balance = " << balance << endl;
    }
    void withdraw(double amount)
    {
        if (amount < 0)
        {
            // amount=0;
            throw 2;
        }
        if (balance < amount)
        {
            throw InsufficientFunds(getId(), balance, amount);
        }
        else
        {
            balance = balance - amount;
            cout << "Balance = " << balance << endl;
        }
    }
};

int main()
{
    int choice = 1;
    int size = 2;
    int acct;
    int amount;
    // int count=0;
    Account *a[size];
    cout << "Enter Account Details: " << endl;
    for (int i = 0; i < size; i++)
    {
        a[i] = new Account();
        try
        {
            a[i]->accept();
        }
        catch (int e)
        {
            cout << "Amount cannot be negative" << endl;
            i--;
        }
    }
    while (choice != 0)
    {
        cout << "0. Exit" << endl
             << "1. Deposit" << endl
             << "2. Withdraw" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "Enter account id to deposit" << endl;
            cin >> acct;
            for (int i = 0; i < size; i++)
            {
                if (acct == a[i]->getId())
                {
                    try
                    {
                        cout << "Enter amount to deposit: ";
                        cin >> amount;
                        a[i]->deposit(amount);
                    }
                    catch (int e)
                    {
                        cout << "Amount cannot be negative" << endl;
                    }
                    a[i]->display();
                }
            }
            break;
        case 2:
            cout << "Enter account id to withdraw" << endl;
            cin >> acct;
            for (int i = 0; i < size; i++)
            {
                if (acct == a[i]->getId())
                {
                    try
                    {
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                        try
                        {
                            a[i]->withdraw(amount);
                        }
                        catch (InsufficientFunds &error)
                        {
                            error.display();
                        }
                    }
                    catch (int e)
                    {
                        cout << "Amount cannot be negative" << endl;
                    }
                    
                }
            }
            break;
        default:
            cout << "Invalid Choice..." << endl;
            break;
        }
    }
    cout << "Thank you......" << endl;
    for (int i = 0; i < size; i++)
    {
        delete a[i];
        a[i] = NULL;
    }

    return 0;
}