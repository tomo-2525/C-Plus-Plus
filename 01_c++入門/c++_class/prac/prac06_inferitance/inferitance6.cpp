class A
{
public:
    int a_;
    A(int a) : a_(a) {}
    A(const A &an) : a_(an.a_) {} // コピーコンストラクタ
    ~A() {}
};
class B : public A
{
public:
    B() : A(1) {}
    B(const B &b) : A(b) {}
    ~B() {}
};

/*********************************************************/

class A
{
public:
    int a_;
    A(int a) : a_(a) {}
    ~A() {}
    A &operator=(const A &an) // コピーオペレータ
    {
        a_ = an.a_;
        return *this;
    }
};

class B : public A
{
public:
    B() : A(1) {}
    ~B() {}
    B &operator=(const B &b)
    {
        A::operator=(b);
        return *this;
    }
};