#include <iostream>
#include <vector>

using namespace std;

struct Student
{
    string name;
    int id;
    Student(string p_name, int p_id)
        : name(move(p_name)), id(p_id)
    {
        cout << "In ctor\n";
    }
    Student(Student &&other)
        : name(move(other.name)), id(other.id)
    {
        std::cout << "In move ctor\n";
    }
    Student &operator=(const Student &other) = default;
};

void print_vector(vector<Student> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << "name:" << v[i].name << " id:" << v[i].id << endl;
    }
}

int main()
{
    vector<Student> v1;
    v1.emplace_back("Foo1", 1);
    cout << endl;
    v1.emplace_back("Foo2", 2);
    cout << endl;
    v1.emplace_back("Foo3", 3);
    cout << endl;
    v1.emplace_back("Foo4", 4);
    cout << endl;

    print_vector(v1);
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    vector<Student> v2;
    v2.push_back(Student("Foo1", 1));
    cout << endl;
    v2.push_back(Student("Foo2", 2));
    cout << endl;
    v2.push_back(Student("Foo3", 3));
    cout << endl;
    v2.push_back(Student("Foo4", 4));
    cout << endl;

    print_vector(v2);
    return 0;
}

/*
In ctor

In ctor
In move ctor

In ctor
In move ctor
In move ctor

In ctor

name:Foo1 id:1
name:Foo2 id:2
name:Foo3 id:3
name:Foo4 id:4
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
In ctor
In move ctor

In ctor
In move ctor
In move ctor

In ctor
In move ctor
In move ctor
In move ctor

In ctor
In move ctor

name:Foo1 id:1
name:Foo2 id:2
name:Foo3 id:3
name:Foo4 id:4
*/
