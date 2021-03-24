#include <iostream>
#include <functional>
using namespace std;

void print_num(int i)
{
    cout << i << "\n";
}

int main(){

function<void(int)> f1 = print_num;
f1(-9);

function<void()> f2 = []() { print_num(2); };
f2();
return 0;
}