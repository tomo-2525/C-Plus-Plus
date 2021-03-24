#include <iostream>
#include <list>
#include <algorithm>

int main()
{
    std::list<int> ls;

    // 先頭から要素を追加
    ls.push_front(1);
    ls.push_front(2);

    // 末尾から要素を追加
    ls.push_back(3);
    ls.push_back(4);

    // 要素を先頭から順番に表示
    std::for_each(ls.cbegin(), ls.cend(), [](int x) {
        std::cout << x << " ";
    });
}