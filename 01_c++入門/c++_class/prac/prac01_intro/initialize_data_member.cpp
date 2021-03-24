#include <iostream>
using namespace std;

class test
{
public:
    int a = 1; //①

    test(){
        this->a = 2;
    }
    
    void init(){
        this->a = 3;
    }
};
//クラスの定義の後ろにセミコロンを忘れない

int main()
{
    test a = test();
    return 0;
}

/**
 * c++11 より前のバージョンでは、メンバーを初期化するのは、コンストラクタと、メンバメソッドだけであった。①のようにするとコンパイルエラーになっていた。
**/