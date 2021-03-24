#include <algorithm>
#include <iostream>
#include <vector>

void print(const char *tag, const std::vector<int> &v)
{
    std::cout << tag << " : ";
    bool first = true;
    for (int x : v)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            std::cout << ',';
        }
        std::cout << x;
    }
    std::cout << std::endl;
}

int main()
{
    // 入力の配列がソート済みではない場合、
    // 隣り合った重複要素が取り除かれる
    {
        std::vector<int> v = {2, 5, 3, 3, 1, 2, 4, 2, 1, 1, 4, 4, 3, 3, 3};

        decltype(v)::iterator result = std::unique(v.begin(), v.end());

        // [v.begin(), result)の範囲に、重複を除いた結果が入っている。
        // 不要になった要素を削除
        v.erase(result, v.end());

        print("unsorted unique", v);
    }

    // 入力の配列がソート済みである場合、
    // 重複している全ての要素が取り除かれて一意になる
    {
        std::vector<int> v = {2, 5, 3, 3, 1, 2, 4, 2, 1, 1, 4, 4, 3, 3, 3};

        std::sort(v.begin(), v.end());
        decltype(v)::iterator result = std::unique(v.begin(), v.end());

        // 不要になった要素を削除
        v.erase(result, v.end());

        print("sorted unique", v);
    }
}