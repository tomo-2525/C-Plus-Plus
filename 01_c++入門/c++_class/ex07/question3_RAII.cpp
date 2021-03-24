//Student ID: s1260032
// exception.cpp
#include <stdexcept>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

class LogFile
{
public:
    string file_name;
    FILE *logfile;

    LogFile(const char *file_name)
    {
        this->file_name = (string)file_name;
        logfile = fopen(file_name, "w+");
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
    }
    ~LogFile()
    {
        fclose(logfile);
    }
};

void doSomeComputation()
{
    throw runtime_error("failure during doing some computation");
}

void example()
{
    const char *filename = "logfile.txt";
    LogFile logfile = LogFile(filename);

    fputs("log1", logfile.logfile);

    // call a function that performs some computation and may throw
    // an exception
    doSomeComputation();

    cout << "closing logfile" << endl;
    logfile.~LogFile();
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