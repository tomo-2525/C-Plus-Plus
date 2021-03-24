#include <string>
#include <iostream>
using namespace std;

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

    ArrayStack &operator=(const ArrayStack &obj)
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

    ArrayStack &operator=(const ArrayStack &&obj)
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

int main(void)
{
    // Create an instance of ArrayStack named stack1 using the default constructor
    cout << "ArrayStack stack1 = ArrayStack();  ";
    ArrayStack stack1 = ArrayStack();
    cout << endl;
    // Push 1,2,3,4,5 in this stack
    for (int i = 1; i <= 5; i++)
    {
        stack1.push(i);
    }

    // Create another instance of ArrayStack named stack2 using the other constructor, specify an original size of 5
    cout << "ArrayStack stack2 = ArrayStack(5);";
    ArrayStack stack2 = ArrayStack(5);
    cout << endl;
    // Push 1,2,...,10 in this stack
    for (int i = 1; i <= 10; i++)
    {
        stack2.push(i);
    }

    cout << "ArrayStack stack3(stack1);";
    ArrayStack stack3(stack1);
    cout << endl;
    cout << "ArrayStack stack4 = stack2;";
    ArrayStack stack4 = stack2;
    cout << endl;
    cout << "ArrayStack stack5;";
    ArrayStack stack5;
    cout << endl;
    cout << "stack5 = stack1;";
    stack5 = stack1;
    cout << endl;
    cout << "ArrayStack stack6(10);";
    ArrayStack stack6(10);
    cout << endl;
    cout << "stack6 = stack6;";
    stack6 = stack6;
    cout << endl;
    cout << "ArrayStack stack7 = std::move(stack5);";
    ArrayStack stack7 = std::move(stack5);
    cout << endl;
    cout << "stack6 = std::move(stack2);";
    stack6 = std::move(stack2);
    cout << endl;

    return 0;
}