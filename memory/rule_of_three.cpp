#include <stdlib.h>
#include <iostream>

class MyMovableClass
{
private:
    int _size;
    int *_data;

public:
    MyMovableClass(size_t size) // constructor
    {
        _size = size;
        _data = new int[_size];
        std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = " << _size*sizeof(int)  << " bytes" << std::endl;
    }

    ~MyMovableClass() // 1 : destructor
    {
        std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
        delete[] _data;
    }
    MyMovableClass(const MyMovableClass& src) { // Copy constructor (deep copy)
        this->_size = src._size;
        _data = new int[this->_size];
        *this->_data = *src._data;
        std::cout << "COPYING content of instance " << &src << " to instance " << this << std::endl;
    }
    MyMovableClass &operator=(const MyMovableClass& src) { // Copy assignment constructor
        if (this == &src) {
            return *this;
        }
        delete[] this->_data; // Delete data if it is present before assigning
        this->_size = src._size;
        _data = new int[this->_size];
        *this->_data = *src._data;
        return *this;
    }
    MyMovableClass(MyMovableClass&& src) {  // Move constructor (NOTE: It is not defined as const because the source will be modified)
        std::cout << "MOVING instance " << &src << " to instance " << this << std::endl;
        this->_size = src._size;
        this->_data = src._data;
        src._data = nullptr;
        src._size = 0;
    }
    MyMovableClass &operator=(MyMovableClass&& src) {  // Move constructor
        if (this == &src) {
            return *this;
        }
        std::cout << "MOVING instances " << &src << " to instance" << this << std::endl;
        
        // Remove any previous data
        delete[] this->_data;
        
        // Move to this object
        this->_size = src._size;
        this->_data = src._data;

        // Remove data from source object
        src._data = nullptr;
        src._size = 0;
    }
    static MyMovableClass createObject(int size);
};

MyMovableClass MyMovableClass::createObject(int size) {
    MyMovableClass obj(size); // regular constructor
    return obj; // return MyMovableClass object by value
}

int main()
{
    MyMovableClass obj1(10); // regular constructor
    MyMovableClass obj2(obj1); // copy constructor
    obj2 = obj1; // copy assignment operator

      // call to copy constructor, (alternate syntax)
    MyMovableClass obj3 = obj1;
    // Here, we are instantiating obj3 in the same statement; hence the copy assignment operator would not be called.

    MyMovableClass obj4 = MyMovableClass::createObject(10);
    // createObject(10) returns a temporary copy of the object as an rvalue, which is passed to the copy constructor.

    MyMovableClass obj4(MyMovableClass::createObject(10));
    // Automatically initializes the object from the rvalue returned from createObject

    return 0;
}

// Example Output:
// CREATING instance of MyMovableClass at 0x7ffeefbff618 allocated with size = 40 bytes

// COPYING content of instance 0x7ffeefbff618 to instance 0x7ffeefbff608

// ASSIGNING content of instance 0x7ffeefbff618 to instance 0x7ffeefbff608

// DELETING instance of MyMovableClass at 0x7ffeefbff608

// DELETING instance of MyMovableClass at 0x7ffeefbff618