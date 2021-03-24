#include <iostream>
using namespace std;

class X
{
public:
   template <int j>
   struct S
   {
      void h()
      {
         cout << "member template's member function: " << j << endl;
      }
   };
   template <int i>
   void f()
   {
      cout << "Primary: " << i << endl;
   }
};

// テンプレートには特定の型や引数だけ違う処理をするテンプレートの特殊化の機能がある。
template <>
void X::f<20>()
{
   cout << "Specialized, non-type argument = 20" << endl;
}

template <class T>
void g(T *p)
{
   p->template f<100>();
   p->template f<20>();
   typename T::template S<40> s; // use of scope operator on a member template
   s.h();
}

int main()
{
   X temp;
   g(&temp);
}

/*
Primary: 100
Specialized, non-type argument = 20
member template's member function: 40
*/