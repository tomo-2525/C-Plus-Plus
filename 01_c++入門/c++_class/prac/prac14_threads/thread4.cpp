#include <iostream>
#include <thread>
#include <exception>
using namespace std;
void
do_worker1 (int& a) {
        std::cout << __PRETTY_FUNCTION__ << " " << a++ << std::endl;
}
 
int
main (int argc, char *argv[]) {
        int a = 1000;
        try {
                std::thread t1(do_worker1, std::ref(a) );
                t1.join();
                cout << __PRETTY_FUNCTION__ << " " << a << endl;
        } catch (std::exception &ex) {
                std::cerr << ex.what() << std::endl;
        }
        return (0);
}