#include <iostream>
#include <cmath>
#include <assert.h>

// Define pi
#define pi 3.14159

// Define Line Class
class LineSegment {
    public:
        LineSegment(int length) : length(length) {}
        int length = 1;
};

// Define Circle subclass
class Circle {
    public:
        Circle(LineSegment radius) : radius(radius) {}
    
        float Area() {
            return pi * pow(radius.length, 2);
        }
    
    private:
        LineSegment radius;
};

    // Define public setRadius() and getArea()
    
// Test in main()
int main() 
{
    LineSegment radius {3};
    Circle circle(radius);
    assert(int(circle.Area()) == 28);
}