// Student ID : s1260032
#ifndef DATE_INSIDE_H
#define DATE_INSIDE_H

class Date
{
public:
    Date() {}
    // One method how to implement inline method.
    void set(const int, const int, const int);
    void print() const;
    int get_month() const;
    int get_day() const;
    int get_year() const;

private:
    int month, day, year;
};

#endif
