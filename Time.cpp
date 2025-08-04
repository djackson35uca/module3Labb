#include "Time.h"


void Time::normalize() {
    
    if (seconds >= 60 || seconds < 0) {
        int total = days * 86400 + hours * 3600 + minutes * 60 + seconds;
        days = total / 86400;
        total %= 86400;
        hours = total / 3600;
        total %= 3600;
        minutes = total / 60;
        seconds = total % 60;
    }
}

// constructors 
Time::Time() : days(0), hours(0), minutes(0), seconds(0) {}

Time::Time(int d, int h, int m, int s)
    : days(d), hours(h), minutes(m), seconds(s) {
    normalize();
}

Time::Time(int h, int m, int s)
    : days(0), hours(h), minutes(m), seconds(s) {
    normalize();
}

Time::Time(int h, int m)
    : days(0), hours(h), minutes(m), seconds(0) {
    normalize();
}

Time::Time(const Time& other)
    : days(other.days), hours(other.hours), minutes(other.minutes), seconds(other.seconds) {
}

// getters
int Time::getDays() const { return days; }
int Time::getHours() const { return hours; }
int Time::getMinutes() const { return minutes; }
int Time::getSeconds() const { return seconds; }

// setters
void Time::setDays(int d) { days = d; }
void Time::setHours(int h) { hours = h; normalize(); }
void Time::setMinutes(int m) { minutes = m; normalize(); }
void Time::setSeconds(int s) { seconds = s; normalize(); }

// assignment
Time& Time::operator=(const Time& right) {
    if (this != &right) {
        days = right.days;
        hours = right.hours;
        minutes = right.minutes;
        seconds = right.seconds;
    }
    return *this;
}

// arithmetic 
Time Time::operator+(const Time& right) const {
    return Time(days + right.days, hours + right.hours, minutes + right.minutes, seconds + right.seconds);
}

Time Time::operator-(const Time& right) const {
    int total = int(*this) - int(right);
    return Time(0, 0, 0, total);
}

// relational ops
bool Time::operator>(const Time& right) const { return int(*this) > int(right); }
bool Time::operator<(const Time& right) const { return int(*this) < int(right); }
bool Time::operator>=(const Time& right) const { return int(*this) >= int(right); }
bool Time::operator<=(const Time& right) const { return int(*this) <= int(right); }
bool Time::operator==(const Time& right) const { return int(*this) == int(right); }
bool Time::operator!=(const Time& right) const { return !(*this == right); }

// overload
ostream& operator<<(ostream& stream, const Time& right) {
    stream << right.days << "d " << right.hours << "h "
        << right.minutes << "m " << right.seconds << "s";
    return stream;
}

// conversion
Time::operator int() const {
    return days * 86400 + hours * 3600 + minutes * 60 + seconds;
}

