#include <iostream>

using namespace std;

// This class for managing a template-based heap ressource implements move semantics
template <class T>
class MyClass
{
    T *data = nullptr;

public:
    MyClass() {}

    // move constructor
    MyClass(MyClass &&other)
    {
        data = other.data;
        other.data = nullptr;
    }

    // move assignment operator
    MyClass &operator=(MyClass &&other)
    {
        if (this != &other)
        {
            if (data)
            {
                delete data;
            }
            data = other.data;
            other.data = nullptr;
        }

        return *this;
    }

    ~MyClass()
    {
        if (data)
        {
            delete data;
        }
    }
private:
    // copy constructor
    MyClass(const MyClass &);

    // copy assignment operator
    MyClass &operator=(const MyClass &);
};

int main()
{
    /* EXERCISE 3-1: create an instance h1 of class MyClass with data of type 'double' using the regular constructor */
    MyClass<double> h1;
    
    // /* EXERCISE 3-2: create an instance h2 of class MyClass using the move constructor (moving from h1) */
    MyClass<double> h2(std::move(h1));

    /* EXERCISE 3-3: disable copying for class MyClass */
    // See private variables
}