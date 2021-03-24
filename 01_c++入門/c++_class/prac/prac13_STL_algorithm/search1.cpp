#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

int main() {
  std::vector<int> v = { 1,2,1,2,3 };
  std::list<int> ls = { 1,2 };

  // 1,2 と連続している最初のシーケンスを探す
  std::vector<int>::iterator it = std::search(v.begin(), v.end(), ls.begin(), ls.end());
  // v[0] の位置を指すイテレータが見つかる。
  if (it == v.end()) {
    std::cout << "not found" << std::endl;
  } else {
    std::cout << "found: index==" << std::distance(v.begin(), it) << std::endl;
  }
}