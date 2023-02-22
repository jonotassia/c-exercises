#include <assert.h>

// Define Point class
class Point {
    public:
        Point(int x, int y) : x(x), y(y) {};
        
        // TODO: Define + operator overload
        Point operator+(Point& p2) {
            return Point(this->x + p2.x, this->y + p2.y);
        }
        
        int x, y;
};


// Test in main()
int main() {
  Point p1(10, 5), p2(2, 4);
  Point p3 = p1 + p2; // An example call to "operator +";
  assert(p3.x == p1.x + p2.x);
  assert(p3.y == p1.y + p2.y);
}