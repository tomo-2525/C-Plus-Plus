// Student ID : s1260032
#ifndef STACK_H
#define STACK_H
// 上の２行を追加することによって何回includeしても最初の一回しかインクルードされない

class Stack {
public:
//コンストラクタ
 Stack(int max_size) : _max_size(max_size), 
   _top(-1), _data(new int[max_size]) {}

//デストラクタ
 ~Stack() { delete[] _data;}

 // interface
 // check whether the stack is empty
 bool empty();

 // check whether the stack is full
 bool full();

 // return the number of elements
 int size();

 // insert element on top
 // print an error message on std::cerr when overflow
 void push(int);

 // remove element on top
 // print an error message on std::cerr when underflow
 void pop();

 // acces the topmost element
 int top();

private:
  int _max_size;
  int _top;
  int* _data;

};
#endif 