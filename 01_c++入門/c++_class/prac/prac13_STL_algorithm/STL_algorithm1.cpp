#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
// first から last によって指定した範囲を対象とし，nth で指定した要素より小さい要素をその前に，大きい要素をその後ろに移動します．2 引数の比較関数を指定することも可能です（下の表現）．


// template <class RandomAccessIterator> void nth_element(RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last);
// template <class RandomAccessIterator, class Compare> void nth_element(RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last, Compare comp);

bool less_a(int a, int b)
{
    return (bool)((a < b) ? 1 : 0);
};

class less_b : public binary_function<int, int, bool>
{
public:
    result_type operator()(first_argument_type a, second_argument_type b)
    {
        return (result_type)((a < b) ? 1 : 0);
    }
};

int main()
{
    vector<int> v1, v2, v3;
    vector<int>::iterator it;
    // 初期設定
    printf("**初期状態 v1**\n");
    v1.push_back(5);
    v1.push_back(10);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(7);
    v1.push_back(1);
    v1.push_back(9);
    v1.push_back(8);
    v1.push_back(6);
    v1.push_back(2);
    for (it = v1.begin(); it != v1.end(); it++)
        printf("  %d", *it);
    printf("\n");
    // 4 より小さいものを 4 の前に，大きいものを 4 の後ろに移動
    printf("4 より小さいものを 4 の前に，大きいものを 4 の後ろに移動\n");
    nth_element(v1.begin(), v1.begin() + 3, v1.end());
    // 以下の方法でも可能
    //	nth_element(v1.begin(), v1.begin()+3, v1.end(), less_a);
    //	nth_element(v1.begin(), v1.begin()+3, v1.end(), less_b());
    //	nth_element(v1.begin(), v1.begin()+3, v1.end(), less<int>());
    for (it = v1.begin(); it != v1.end(); it++)
        printf("  %d", *it);
    printf("\n");

    return 0;
}
