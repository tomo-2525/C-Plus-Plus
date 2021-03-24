#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string name;

public:
    Person(string n) : name(n) {}
    void set_name(string n);
    string get_name();
};

class Student : public Person
{
private:
    int student_id;
    int year;

public:
    Student(std::string n, int y, int id) : Person(n), student_id(id), year(y) {}
    void set_student_id(int id);
    int get_student_id();
    void set_year();
    int get_year();
};