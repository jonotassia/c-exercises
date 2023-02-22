// Example solution for Rectangle and Square friend classes
#include <assert.h>

// Declare class Rectangle
class Rectangle;

// Define class Square as friend of Rectangle
class Square {
    public:
        Square(int side) : side(side) {};
    
    private:
        friend class Rectangle;
        int side;
};

// Define class Rectangle
class Rectangle {
    public:
    // Add public function to Rectangle: Area() and constructor        
        Rectangle(Square& square);
        int Area() const;
    
    // Add private attributes width, height;
    private:
        int width;
        int height;
};

// Define a Rectangle constructor that takes a Square
Rectangle::Rectangle(Square& square) {
    this->width = square.side;
    this->height = square.side;
};

// Define Area() to compute area of Rectangle
int Rectangle::Area() const {
    return width * height;
}

// Update main() to pass the tests
int main()
{
    Square square(4);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16); 
}