#include <iostream>
using namespace std;

class Cars
{
private:
    static int num_produced;

public:
    Cars() { num_produced++; }
    static int get_num_produced()
    {
        return num_produced;
    }
};

int Cars::num_produced = 0;
int main()
{
    cout << Cars::get_num_produced() << endl; // 0
    Cars c1;
    cout << Cars::get_num_produced() << endl;  // 1
    Cars c2;
    cout << Cars::get_num_produced() << endl;  // 2
}