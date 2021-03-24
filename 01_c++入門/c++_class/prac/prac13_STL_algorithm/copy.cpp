#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main()
{
    std::vector<int> v = {3, 1, 2};

    // v から v2 へ普通にコピーする
    std::vector<int> v2(v.size()); // ちゃんと確保しておくこと
    std::copy(v.begin(), v.end(), v2.begin());

    // back_inserter を使って v3 へ設定。
    // back_inserter は要素をコピーするときに v3.push_back() するイテレータを作る関数。
    std::list<int> ls3;
    std::copy(v2.begin(), v2.end(), std::back_inserter(ls3));

    // ostream_iterator を使って出力。
    // ostream_iterator<int>(cout, ",") は要素をコピーするときに cout << x << "," としてくれるイテレータ。
    std::copy(ls3.begin(), ls3.end(), std::ostream_iterator<int>(std::cout, ","));
}