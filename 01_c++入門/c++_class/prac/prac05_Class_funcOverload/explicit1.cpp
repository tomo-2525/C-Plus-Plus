struct A
{
    A(int) {}      // 変換コンストラクタ。
    A(int, int) {} // 変換コンストラクタ (C++11)。
    operator bool() const { return true; }
};

struct B
{
    explicit B(int) {}
    explicit B(int, int) {}
    explicit operator bool() const { return true; }
};

int main()
{
    A a1 = 1;      // OK、コピー初期化は A::A(int) を選択します。
    A a2(2);       // OK、直接初期化は A::A(int) を選択します。
    A a3{4, 5};    // OK、直接リスト初期化は A::A(int, int) を選択します。
    A a4 = {4, 5}; // OK、コピーリスト初期化は A::A(int, int) を選択します。
    A a5 = (A)1;   // OK、明示的なキャストは static_cast を行います。
    if (a1){}       // OK、A::operator bool()
    bool na1 = a1;                    // OK、コピー初期化は A::operator bool() を選択します。
    bool na2 = static_cast<bool>(a1); // OK、 static_cast は直接初期化を行います。

    
    //  B b1 = 1;      // エラー、コピー初期化は B::B(int) を考慮しません。
    B b2(2);    // OK、直接初期化は B::B(int) を選択します。
    B b3{4, 5}; // OK、直接初期化は B::B(int, int) を選択します。
    //  B b4 = {4, 5}; // エラー、コピーリスト初期化は B::B(int,int) を考慮しません。
    B b5 = (B)1; // OK、明示的なキャストは static_cast を行います。
    if(b2);     // OK、B::operator bool()
    //  bool nb1 = b2; // エラー、コピー初期化は B::operator bool() を考慮しません。
    bool nb2 = static_cast<bool>(b2); // OK、 static_cast は直接初期化を行います。
}