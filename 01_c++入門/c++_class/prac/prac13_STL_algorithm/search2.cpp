#include <iostream>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>

int main()
{
  //                      xxxx
  std::string text = "babcabaabaac";
  std::string pattern = "abaa";

  // ボイヤー・ムーア法で、文字列 (text) 内のサブ文字列 (pattern) を検索する。
  // patternを登録
  std::boyer_moore_searcher searcher {
    pattern.cbegin(),
    pattern.cend()
  };

  // textと検索器を指定して検索を実行
  std::string::const_iterator result = std::search(text.cbegin(), text.cend(), searcher);

  // 見つかった
  if (result != text.cend()) {
    // 見つかった位置を取得
    std::ptrdiff_t n = std::distance(text.cbegin(), result);

    // 見つかった文字列 (pattern) を取得
    std::string s {result, result + pattern.size()};

    std::cout << n << std::endl;
    std::cout << s << std::endl;
  }
  // 見つからなかった
  else {
    std::cout << "not found" << std::endl;
  }
}