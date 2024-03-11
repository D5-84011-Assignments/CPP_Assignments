#include <iostream>
using namespace std;

class Address
{
    string building;
    string street;
    string city;
    int pin;

    public:

    Address()
    {
        this->building = "Sunbeam";
        this->street = "Hinjewadi";
        this->city = "Pune";
        this->pin = 123;
    }

    Address(string building,string street,string city,int pin)
    {
        this->building = building;
        this->street = street;
        this->city = city;
        this->pin = pin;
    }

    void accept()
    {
        cout<<"Enter building name"<<endl;
        cin>>this->building;
        cout<<"Enter street name"<<endl;
        cin>>this->street;
        cout<<"Enter city name"<<endl;
        cin>>this->city;
        cout<<"Enter pincode"<<endl;
        cin>>this->pin;
    }

    void display()
    {
        cout<<"Building name: "<<this->building<<endl;
        cout<<"Street name: "<<this->street<<endl;
        cout<<"Name of the city: "<<this->city<<endl;
        cout<<"Pincode: "<<this->pin<<endl;

    }

    string getBuilding() const
    {
        return this->building;
    }

    void setBuilding(const string &val)
    {
        this->building = val;
    }

     string getStreet() const
    {
        return this->street;
    }

    void setStreet(const string &val)
    {
        this->street = val;
    }

     string getCity() const
    {
        return this->city;
    }

    void setCity(const string &val)
    {
        this->city = val;
    }
     int getPin() const
    {
        return this->pin;
    }

    void setPin(const int val)
    {
        this->pin = val;
    }


};

int main(void)
{
    Address a1;
    a1.display();
    a1.accept();
    a1.display();
    a1.setCity("Bangalore");
    a1.setPin(411057);
    string v = a1.getCity();
    cout<<v<<endl;
    a1.display();
}
