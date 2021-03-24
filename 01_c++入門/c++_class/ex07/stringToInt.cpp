// Student ID: s1260032
// stringToInt.cpp
#include <string>
#include <sstream>
#include <iostream>
#include <typeinfo>
using namespace std;

int stringToInt(const string &input)
{
    stringstream instream;
    instream << input;
    int number;
    instream >> number;
    cout << "num: "<< number << endl;
    try
    {
        // Error: the input can not be converted
        if (instream.fail())
            throw invalid_argument("input can not be converted to an int");
    }
    catch (const logic_error& e)
    {
        cerr << e.what() << endl;
        return -1;
    }
    
    char left;
    instream >> left;
    cout << "left: "<< left << endl;
   
    try
    {
        // Error: there are some characters left after the int
        if (!instream.fail())
            throw invalid_argument("input can not be converted to an int");
    }
    catch(const logic_error& e)
    {
        cerr << e.what() << endl;
        return -1;
    }


    // everything went fine: returns the int
    return number;
}

int main(void)
{
    string test1 = "11";
    cout << stringToInt(test1) << endl;
    cout << endl;

    string test2 = "cc11";
    cout << stringToInt(test2) << endl;
    cout << endl;

    string test3 = "11cc";
    cout << stringToInt(test3) << endl;
    cout << endl;

    string test4 = "-1";
    cout << stringToInt(test4) << endl;
    cout << endl;

    cout << "Tests passed" << endl;

    return 0;
}