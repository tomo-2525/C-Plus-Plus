#include <iostream>
#include <thread>
#include <exception>
using namespace std;
void do_worker1()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << "do_werker1" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
void do_worker2()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << "do_werker1" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main(int argc, char *argv[])
{
    try
    {
        std::thread t1(do_worker1);
        std::thread t2(do_worker2);
        t1.join();
        t2.join();
    }
    catch (std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    return (0);
}