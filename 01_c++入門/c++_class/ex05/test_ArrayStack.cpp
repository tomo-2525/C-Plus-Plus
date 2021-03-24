//Student ID: s1260032
// test_ArrayStack.cpp
#include <iostream>
#include "ArrayStack.h"
using namespace std;
int main(void)
{
    // Create an instance of ArrayStack named stack1 using the default constructor
    ArrayStack stack1 = ArrayStack();
    // Push 1,2,3,4,5 in this stack
    for (int i = 1; i <= 5; i++)
    {
        stack1.push(i);
    }

    // Create another instance of ArrayStack named stack2 using the other constructor, specify an original size of 5
    ArrayStack stack2 = ArrayStack(5);
    // Push 1,2,...,10 in this stack
    for (int i = 1; i <= 10; i++)
    {
        stack2.push(i);
    }

    std::cout << std::endl;
    // above is the code from question 1
    // Copy
    ArrayStack stack3(stack1);
    stack3.print_stack();
    ArrayStack stack4 = stack2;
    stack4.print_stack();
    
    // Assignment
    ArrayStack stack5;
    stack5 = stack1;
    ArrayStack stack6(10);
    stack6 = stack6;

    // above is the code from question 1 and 2
    // Move
    std::cout << std::endl;
    ArrayStack stack7 = std::move(stack5);
    stack7.print_stack();
    stack6 = std::move(stack2);
    stack6.print_stack();

    return 0;
}