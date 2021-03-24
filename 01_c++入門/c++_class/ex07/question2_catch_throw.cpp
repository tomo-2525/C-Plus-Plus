//Student ID: s1260032
// exception.cpp
#include <stdexcept>
#include <cstdio>
#include <iostream>

using namespace std;

void doSomeComputation()
{
    throw runtime_error("failure during doing some computation");
}

void example()
{
    FILE *logfile = fopen("logfile.txt", "w+");
    if (!logfile)
    {
        try
        {
            throw runtime_error("failed to open file");
        }
        catch (const runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }

    fputs("log1", logfile);

    // call a function that performs some computation and may throw
    // an exception
    doSomeComputation();

    cout << "closing logfile" << endl;
    fclose(logfile);
}

int main(void)
{
    cout << "Calling example()" << endl;
    try
    {
        example();
    }
    catch (const runtime_error &e)
    {
        cerr << e.what() << endl;
    }
    cout << "After calling example()" << endl;
    return 0;
}