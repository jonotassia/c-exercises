// Example solution for Shape inheritance
#include <assert.h>
#include <cmath>

// TODO: Define pi
#define pi 3.14159

// TODO: Define the abstract class Shape
class Shape {
    public:
        virtual double Area() const = 0;
        virtual double Perimeter() const = 0;
};

class Rectangle : public Shape {
    public:
        Rectangle(float width, float height) : width_(width), height_(height) {};
    
        double Area() const override {
            return width_ * height_;
        }
    
        double Perimeter() const override {
            return 2*(width_ + height_);
        }
    
    private: 
        float width_, height_;
};

class Circle : Shape {
    public:
        Circle(float radius) : radius_(radius) {};
    
        double Area() const override {
            return pi * pow(radius_, 2);
        }
    
        double Perimeter() const override {
            return 2 * pi * radius_;
        }
    
    private:
        float radius_;
};

// Test in main()
int main() {
  double epsilon = 0.1; // useful for floating point equality

  // Test circle
  Circle circle(12.31);
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);

  // Test rectangle
  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
}