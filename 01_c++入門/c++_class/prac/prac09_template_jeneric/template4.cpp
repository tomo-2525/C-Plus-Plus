/**************/
/*型パラメータ*/
/**************/
/*
型パラメータ T を持ち，任意のデータ型について値の交換ができます。
このようなパラメータ T を持つ関数やクラスを，テンプレート (template) といいます。*/
#include <iostream>
template <class T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int m = 2, n = 3;
    swap(m, n); // swap(int&a, int& b) と具体化される
}

/* 値パラメータ
大きさ N の配列 arr を初期化
テンプレートには，型パラメータの他に，値パラメータを持たせることができます。
*/
template <class T, int N>
void init(T (&arr)[N])
{
    for (int i = 0; i < N; ++i)
        arr[i] = T();
}

int main()
{
    int arr[256];
    init(arr); // init(int (&arr)[256]) と具体化される
}

/********************/
/*クラステンプレート*/
/********************/
/*
次のプログラムは，スタックを実現するテンプレートクラス Stack を定義したものです。
クラステンプレートについては，型の指定 (<int> など) を省略することはできません。
*/
template <class T>
class Stack
{
private:
    T *stack;
    int index;

public:
    Stack(int size) : index(0) { stack = new T[size]; }
    ~Stack() { delete[] stack; }
    void push(T item) { stack[index++] = item; }
    T pop() { return stack[--index]; }
};

int main()
{
    Stack<int> stack(256);
    stack.push(123);
    stack.pop();
}

/**********************/
/*テンプレートの特殊化*/
/**********************/
/*
特定の型に対して異なる処理を行いたい場合，次のようにテンプレートを特殊化します。
この例では，T = bool の場合にだけ，下に定義された add が呼び出されます。
*/
template <class T>
T add(T a, T b) { return a + b; }

template <>
bool add(bool a, bool b) { return a || b; }
// クラステンプレートの特殊化は次のように書きます。

template <class T>
class Class1
{
    ...
};

template <>
class Class1<bool>
{
    ////////
};

/********************************/
/*テンプレートメタプログラミング*/
/********************************/
/*
次の Square のように，テンプレート引数からコンパイル時定数を計算するクラスを，メタ関数 (metafunction) といいます。
メタ関数はコンパイル時に評価されるため，コンパイル終了時点で Square<9>::value の値は 81 と求まっています。
*/

template <int N>
struct Square
{
    enum
    {
        value = N * N
    };
};

int main()
{
    std::cout << Square<9>::value << std::endl; // 出力: 81
}
// 次のプログラムは，同様の技法で階乗を求める Fact を定義したものです。

template <int N>
struct Fact
{
    enum
    {
        value = N * Fact<N - 1>::value
    };
};

template <>
struct Fact<0>
{
    enum
    {
        value = 1
    };
};

int main()
{
    std::cout << Fact<10>::value << std::endl; // 出力: 3628800
}