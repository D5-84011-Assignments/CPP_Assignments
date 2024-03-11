#include <iostream>

using namespace std;

class Box
{
private:
    double length;
    double width;
    double height;

public:
    Box()
    {
        this->length = 0;
        this->width = 0;
        this->height = 0;
    }

    void setDimension()
    {
        cout << "Enter the length \n";
        cin >> this->length;
        cout << "Enter the width \n";
        cin >> this->width;
        cout << "Enter the height \n";
        cin >> this->height;
    }

    void checkDimension()
    {
        cout << "Length is " << this->length << endl;
        cout << "Width is " << this->width << endl;
        cout << "Height is " << this->height << endl;
    }

    void calculateVolume()
    {
        double result;
        result = this->length * this->width * this->height;
        cout << "The volume of box is " << result << endl;
    }
};

int main()
{
    Box v;

    int choice;

    do
    {
        cout << "\nEnter the choice\n";
        cout << "0. Exit\n";
        cout << "1. Initialize box diemsion \n";
        cout << "2. Set  the box dimension \n";
        cout << "3. Check the box dimension: \n";
        cout << "4. Calculate the box dimension: \n";
        cin >> choice;
        switch (choice)
        {
        case 0:
            choice = 0;
            cout << "\nExitting\n";
            break;
        case 1:
            cout << "\nDimension of box initialized successfully \n";
            break;
        case 2:
            v.setDimension();
            break;
        case 3:
            v.checkDimension();
            break;
        case 4:
            v.calculateVolume();
            break;
        default:
            cout << "Your choice is invalid please re-enter your choice \n";
        }
    } while (choice != 0);

    return 0;
}