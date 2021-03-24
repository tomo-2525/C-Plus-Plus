// Student ID : s1260032
// test_stack.cpp
#include <cassert>
#include "stack.h"
#include "stack.cpp"

int main(void)
{
  Stack stack(100);

  for (int i = 0; i < 40; ++i)
  {
    stack.push(i);
  }

  //trueの時何もしないで、falseの時に異常を出してプログラムを終了させる。
  assert(stack.full() == false);

  int i = 39;
  while (!stack.empty())
  {
    int element = stack.top();
    assert(element == i);
    stack.pop();
    i = i - 1;
  }

  return 0;
}