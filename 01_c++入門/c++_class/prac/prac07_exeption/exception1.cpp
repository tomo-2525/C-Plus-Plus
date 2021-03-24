#include <stdexcept>
#include <iostream>


void f()
{
  // 例外を投げる
  throw std::logic_error("an exception occurred");
}

int main()
{
  try {
    f();
  }
  catch (const std::logic_error& e) {
    // 例外が発生した！
    std::cout << e.what() << std::endl;
    std::exit(1);
  }
}