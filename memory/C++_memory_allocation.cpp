#include <stdlib.h>
#include <iostream>

class MyClass
{
private:
    long long _number;

public:
    MyClass()
    {
        std::cout << "Constructor Called\n";
    }
    ~MyClass()
    {
        std::cout << "Destructor Called\n";
    }

    void* operator new(size_t size) {
        std::cout << "New: Allocating " << size << " bytes of memory" << std::endl;
        void *p = malloc(size);

        return p;
    }

    void operator delete(void *p) {
        std::cout << "Delete: Memory is freed again" << std::endl;
        free(p);
    }
    
    void setNumber(long number)
    {
        _number = number;
        std::cout << "Number: " << _number << "\n";
    }
};


int main()
{
    // allocate memory using malloc
    // comment these lines out to run the example below
    // MyClass *myClass = (MyClass *)malloc(sizeof(MyClass));
    // myClass->setNumber(42); // EXC_BAD_ACCESS
    // free(myClass);
	  
	// allocate memory using new
    MyClass *myClass = new MyClass();
    myClass->setNumber(42); // works as expected
    delete myClass;

    return 0;
}