#include <iostream>
#include <deque>
#include <algorithm>

int main()
{
    std::deque<int> deq;

    deq.push_front(3); // 先頭に要素を追加
    deq.push_back(1);  // 末尾に要素を追加

    // イテレータを介して全要素に対して操作を行う
    std::for_each(deq.begin(), deq.end(), [](int x) {
        std::cout << x << std::endl;
    });
}