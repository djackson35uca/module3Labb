#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time {
private:
    int days;
    int hours;
    int minutes;
    int seconds;

    void normalize(); // keeps time values in valid ranges

public:
    // constructors
    Time();
    Time(int d, int h, int m, int s);
    Time(int h, int m, int s);
    Time(int h, int m);
    Time(const Time& other); // copy constructor

    // getters
    int getDays() const;
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    // setters
    void setDays(int d);
    void setHours(int h);
    void setMinutes(int m);
    void setSeconds(int s);

    // assignment
    Time& operator=(const Time& right);

    // arithmetic
    Time operator+(const Time& right) const;
    Time operator-(const Time& right) const;

    // relational operators
    bool operator>(const Time& right) const;
    bool operator<(const Time& right) const;
    bool operator>=(const Time& right) const;
    bool operator<=(const Time& right) const;
    bool operator==(const Time& right) const;
    bool operator!=(const Time& right) const;

    // stream overload
    friend ostream& operator<<(ostream& stream, const Time& right);

    // conversion
    operator int() const;  // total seconds
};

#endif
