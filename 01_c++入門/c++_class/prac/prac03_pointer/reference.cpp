#include <iostream>
#include <string>

using namespace std;

void inc(int &i){
    i++;
}

int main()
{
    int j = 1;
    int &k = j;
    cout << "j:" << j << " k:" << k << endl; // j:1 k:1
    j += 10;
    cout << "j:" << j << " k:" << k << endl; // j:11 k:11
    k += 10;
    cout << "j:" << j << " k:" << k << endl; // j:21 k:21

    int *p = &k;
    cout << "*p:" << *p << endl; // *p:21

    int a = 0;
    cout << "a:" << a << endl; // a:0
    inc(a);
    cout << "a:" << a << endl; // a:1

    return 0;
}
