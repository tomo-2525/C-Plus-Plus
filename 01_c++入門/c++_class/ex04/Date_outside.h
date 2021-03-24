// Student ID : s1260032
#ifndef DATE_OUTSIDE_H
#define DATE_OUTSIDE_H
#include <iostream>

class Date
{
public:
  Date() {}
  // One method how to implement inline method.
  void Date::set(const int, const int, const int);
  void Date::print()const;
  int Date::get_month()const;
  int Date::get_day()const;
  int Date::get_year()const;

private:
  int month, day, year;
};

inline void Date::set(const int m, const int d, const int y)
{
    this->month = m;
    this->day = d;
    this->year = y;
}

inline void Date::print() const
{
    std::cout << "Year:" << Date::get_year() << " Month:" << get_month() << " Day:" << get_day() << std::endl;
}

inline int Date::get_month() const
{
    return this->month;
}

inline int Date::get_year() const
{
    return this->year;
}

inline int Date::get_day() const
{
    return this->day;
}
#endif
