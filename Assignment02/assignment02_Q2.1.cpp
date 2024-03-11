#include <iostream>

using namespace std;

class Tollbooth
{
private:
    unsigned int totalCars;
    double totalMoney;

public:
    Tollbooth()
    {
        this->totalCars = 0;
        this->totalMoney = 0.0;
    }

    void payingCars()
    {
        totalCars++;
        totalMoney += 0.50;
    }

    void nopayCars()
    {
        totalCars++;
    }

    void printOnConsole()
    {
        cout << "Total cars. " << totalCars << endl;
        cout << "Total money collected. " << totalMoney << endl;
        cout << "Number of paying carss. " << totalMoney / 0.50 << endl;
        cout << "Number of non paying cars " << totalCars - (totalMoney - 0.50) << endl;
    }
};

int main()
{
    Tollbooth T;

    T.payingCars();
    T.nopayCars();
    T.printOnConsole();
    T.printOnConsole();

    return 0;
}
