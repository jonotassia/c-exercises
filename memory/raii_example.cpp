#include <iostream>

class MyInt {
    int* _p;

public:
    MyInt(int *p = nullptr) {
        _p = p;
    }
    
    ~MyInt() {
        delete _p;
    }
    int &operator*() {
        // Overload dereferencing to ensure normal experience of pointer
        return *_p;
    }
};

int main()
{
    double den[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    for (size_t i = 0; i < 5; ++i)
    {
        // allocate the resource on the heap
        MyInt en(new int(i));

        // use the resource
        std::cout << *en << "/" << den[i] << " = " << *en / den[i] << std::endl;
    }

    return 0;
}