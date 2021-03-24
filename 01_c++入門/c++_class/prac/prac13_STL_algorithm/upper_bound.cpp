#include <iostream>
#include <vector>
#include <algorithm>

struct X
{
    int key;   // プライマリキー
    int value; // 補助的な値

    bool operator<(const X &rhs) const
    {
        // 型Xはプライマリキーでのみ順序付けされる。
        return key < rhs.key;
    }
};

void push_stable(std::vector<X> &queue, X elem)
{
    // 挿入対象の値 elem よりも大きい要素の位置、すなわち
    // elem と同値な要素グループの次の位置を検索する。
    auto it = std::upper_bound(queue.begin(), queue.end(), elem);
    queue.insert(it, elem);
}

int main()
{
    // この関数単体としての使い方
    {
        // upper_bound で 3 より大きい要素の位置を検索する場合、
        // 3 以下の物と 3 より大きい物がその順に並んでいれば、
        // 必ずしもソートされている必要はない。
        std::vector<int> v = {3, 1, 4, 6, 5};

        // 3より大きい要素を二分探索で検索
        decltype(v)::iterator it = std::upper_bound(v.begin(), v.end(), 3);
        std::cout << *it << std::endl;
    }

    // 応用例：安定順序・優先順位付きキューの実装
    {
        std::vector<X> queue;
        push_stable(queue, {100, 1});
        push_stable(queue, {200, 1});
        push_stable(queue, {300, 1});
        push_stable(queue, {300, 2});
        push_stable(queue, {200, 2});
        push_stable(queue, {100, 2});

        // プライマリキー key は同値だが異なる値 value を持つ要素間では
        // キュー queue への要素挿入順序が維持されている。
        // （std::priority_queue クラスでは挿入順序は保持されない。）
        for (const auto &e : queue)
        {
            std::cout << e.key << ':' << e.value << ' ';
        }
        std::cout << std::endl;
    }
}