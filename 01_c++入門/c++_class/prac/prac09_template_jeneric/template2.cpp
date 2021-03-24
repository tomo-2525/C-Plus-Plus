#include <iostream>

template <class T>
struct Node
{
    Node *next;
    T val;
};

template <class T>
class List
{
    Node<T> *head;

public:
    // append t to the list
    void push_back(const T &t);
};
template <class T>
void List<T>::push_back(const T &t)
{ //...
}

int main()
{
    List<int> l; // instantiates the list for int l.push_back(1);
}