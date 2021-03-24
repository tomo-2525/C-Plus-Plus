// Student ID : s1260032
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    int count = 1;
    double num;
    ifstream input("data.txt");
    if (!input.is_open())
    {
        cerr << "Can not open file" << endl;
        exit(1);
    }
    cout << "---------------------+--------------------+---------------------" << endl;
    while (!input.eof())
    {
        cout << setw(20) << count << " |";
        input >> num;
        cout << setw(19) << num << " |";
        input >> num;
        cout << setw(21) << num << endl;
        count++;
    }
    input.close();
    return 0;
}