// Student ID : s1260032
#include <iostream>
#include "Date_inside.h"
// #include "Date_outside.h"
using namespace std;
// * set() takes three arguments corresponding to the month, day and year and use these values to set its internal data (month, day and year)
// * print() prints out the date stored in the object
// * get_month(), get_day(), get_year() return respectively the month, the day and the year stored in a Date object
void Date::set(const int m, const int d, const int y)
{
    this->month = m;
    this->day = d;
    this->year = y;
}

void Date::print() const
{
    cout << "Year:" << Date::get_year() << " Month:" << get_month() << " Day:" << get_day() << endl;
}

int Date::get_month() const
{
    return this->month;
}

int Date::get_year() const
{
    return this->year;
}

int Date::get_day() const
{
    return this->day;
}
