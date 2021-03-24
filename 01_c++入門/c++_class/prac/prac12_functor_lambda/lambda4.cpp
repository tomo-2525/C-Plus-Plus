#include <iostream>
template<typename Func>
void f(Func func){
        func();
}
int main(int argc, char const* argv[])
{
        f( []{ std::cout<<"Hello world"<<std::endl;} );
        return 0;
}