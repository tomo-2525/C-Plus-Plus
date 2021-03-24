#include <iostream>
#include <thread>
#include <exception>
using namespace std;
void
do_worker1 () {
        std::cout << "do_worker1" << std::endl;
}
 
int
main (int argc, char *argv[]) {
        try {
                std::thread t1(do_worker1);
                t1.join();
        } catch (std::exception &ex) {
                std::cerr << ex.what() << std::endl;
                cout << "error occured" << endl;
        }
        return (0);
}