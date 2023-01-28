#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>

class Sphere {
 public:
  Sphere(int radius) : radius_(radius) {
    if (radius <= 0) throw std::invalid_argument("radius must be positive");
  }

  int Radius() const { return radius_; }
  static float Volume(float radius) { return pi_ * 4 / 3 * pow(radius, 3); }

  void Radius(int radius) {
    if (radius <= 0) throw std::invalid_argument("radius must be positive");
    radius_ = radius;
  }

 private:
  static float constexpr pi_{3.14159};
  int radius_;
};

// Test
int main(void) {
  float vol = Sphere::Volume(5);
  assert(abs(vol - 523.6) < 1);
  std::cout << vol;
}