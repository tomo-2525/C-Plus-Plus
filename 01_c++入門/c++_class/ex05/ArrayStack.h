//Student ID: s1260032
// ArrayStack.h

#include <string>
#include <iostream>

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

class ArrayStack
{
private:
    int _num_items;      // number of items in the stack
    int *_items;         // stack items
    int _allocated_size; // size of memory allocated

    void resize(int max_size)
    {
        if (max_size == 0)
            max_size++;

        // Move stack to a new array of size max
        _allocated_size = max_size;
        int *temp = new int[max_size];
        // Copy
        for (int i = 0; i < _num_items; ++i)
        {
            temp[i] = _items[i];
        }
        delete[] _items;
        _items = temp;
    }

public:
    // Constructors:
    ArrayStack()
    {
        /* COMPLETE ... init _num_items to 0, _allocated_size to 0, and
     * set _items to a null pointer, */
        _num_items = 0;
        _allocated_size = 0;
        _items = nullptr;
        std::cout << "default constructor...ArrayStack() is called" << std::endl;
    }

    explicit ArrayStack(int allocated_size)
    {
        /* COMPLETE ... init _num_items to 0, 
     * pre-allocate memory for an array of size allocated_size
     * and make _items point to it */
        _num_items = 0;
        _items = new int[allocated_size];
        std::cout << "explicit ArrayStack(int allocated_size) is called" << std::endl;
    }

    ArrayStack(const ArrayStack &obj)
        : _allocated_size(obj._allocated_size), _num_items(obj._num_items)
    {
        std::cout << "Copy Constructor...ArrayStack(const ArrayStack &obj)is called" << std::endl;
        this->_items = new int[_allocated_size];
        for (int i = 0; i < obj._num_items; i++)
        {
            this->_items[i] = obj._items[i];
        }
    }
    
    ArrayStack& operator=(const ArrayStack &obj)
    {
        std::cout << "Assignment Operator...&ArrayStack::operator=(const &obj) is called" << std::endl;
        this->_allocated_size = obj._allocated_size;
        this->_num_items = obj._num_items;
        this->_items = new int[_allocated_size];
        for (int i = 0; i < obj._num_items; i++)
        {
            this->_items[i] = obj._items[i];
        }
        return *this;
    }

    ArrayStack(const ArrayStack &&obj)
        : _allocated_size(obj._allocated_size), _num_items(obj._num_items)
    {
        std::cout << "Move Constructor...ArrayStack(const ArrayStack &&obj)is called" << std::endl;
        this->_items = new int[_allocated_size];
        for (int i = 0; i < obj._num_items; i++)
        {
            this->_items[i] = obj._items[i];
        }
    }
    
    ArrayStack& operator=(const ArrayStack &&obj)
    {
        std::cout << "Move assignment operator...&ArrayStack::operator=(const &&obj) is called" << std::endl;
        this->_allocated_size = obj._allocated_size;
        this->_num_items = obj._num_items;
        this->_items = new int[_allocated_size];
        for (int i = 0; i < obj._num_items; i++)
        {
            this->_items[i] = obj._items[i];
        }
        return *this;
    }



    // Destructor::
    ~ArrayStack()
    {
        // COMPLETE
        delete[] _items;
    }

    void push(int item)
    {
        if (_num_items == _allocated_size)
            resize(2 * _allocated_size);
        _items[_num_items++] = item;
    }

    int pop()
    {
        int ret = _items[--_num_items];
        if (_num_items > 0 && _num_items == _allocated_size / 4)
            resize(_allocated_size / 2);
        return ret;
    }

    bool empty() const { return _num_items == 0; }

    int size() const { return _num_items; }

    // I added the print function.
    void print_stack()
    {
        for (int i = 0; i < _num_items; i++)
        {
            std::cout << this->_items[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif // ARRAY_STACK_H
