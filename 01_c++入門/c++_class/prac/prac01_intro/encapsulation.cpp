#include <iostream>
 
using namespace std;
 

class Sample{
public:
    int a;      //  publicなメンバ変数
private:
    int b;      //  privateなメンバ変数

public:
    void func1();
private:
    void func2();
};

void Sample::func1(){
    cout << "func1" << endl;
    a = 1;
    b = 1;
    func2();                    //  func2ないから、func1を呼び出す
}
void Sample::func2(){
    a = 2;
    b = 2;
    cout << "a=" << a  << "," << "b=" << b << endl;
}

 
int main(){
    Sample s;
    s.a = 1;
    // s.b = 2; コンパイルエラー
    s.func1();
    //s.func2(); コンパイルエラー
    return 0;
}