// Student ID : s1260032
// check whether the stack is empty
#include <iostream>
#include "stack.h"
bool Stack::empty()
{
    if (_top == -1)
        return true;
    else
        return false;
}

// check whether the stack is full
bool Stack::full()
{
    if (_max_size-1 == (_top))
        return true;
    else
        return false;
}

// return the number of elements
int Stack::size()
{
    return _top + 1;
}

// insert element on top
// print an error message on std::cerr when overflow
void Stack::push(int num)
{
    if (full() == true)
        std::cerr << "overflow occured" << std::endl;
    else{
        _top++;
        _data[_top] = num;
    }
}

// remove element on top
// print an error message on std::cerr when underflow
void Stack::pop()
{
    if (_top == -1)
        std::cerr << "underflow occured" << std::endl;
    else{
        _top--;
    }
}

// acces the topmost element
int Stack::top()
{
    return _data[_top];
}