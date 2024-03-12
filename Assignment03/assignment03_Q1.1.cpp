#include <iostream>

using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time()
    {
        this->hour;
        this->minute;
        this->second;
    }
    Time(int h, int m, int s)
    {
        this->hour = h;
        this->minute = m;
        this->second = s;
    }
    int getHour()
    {
        return hour;
    }

    void setHour(int h)
    {
        this->hour = h;
    }

    int getMinute()
    {
        return minute;
    }

    void setMinute(int m)
    {
        this->minute = m;
    }

    int getSecond()
    {
        return second;
    }

    void setSecond(int s)
    {
        this->second = s;
    }

    void printTime()
    {
        cout << "Time : " << hour << "," << minute << "," << second << endl;
    }
};

int main()
{
    int size;
    cout << "Enter the number of Time objects: ";
    cin >> size;

    Time *timeArray = new Time[size];

    for (int i = 0; i < size; i++)
    {
        int h, m, s;
        cout << "Enter hour for object " << i + 1 << ": ";
        cin >> h;
        cout << "Enter minute for object " << i + 1 << ": ";
        cin >> m;
        cout << "Enter second for object " << i + 1 << ": ";
        cin >> s;

        timeArray[i] = Time(h, m, s);
    }

    for (int i = 0; i < size; i++)
    {
        cout << "Time for object " << i + 1 << ": ";
        timeArray[i].printTime();
    }

    delete[] timeArray;
    timeArray = NULL;

    return 0;
}
