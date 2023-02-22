#include <assert.h>
#include <cmath>

// TODO: Define PI
#define PI 3.14159

// TODO: Declare abstract class VehicleModel
class VehicleModel {
    public:
        virtual void Move(double v, double theta) = 0;
};

// TODO: Derive class ParticleModel from VehicleModel
class ParticleModel : public VehicleModel {
    public:
        void Move(double v, double phi) {
            theta += phi;
            x += v * cos(theta);
            y += v * cos(theta);
        }

        double x, y, theta;
};

// TODO: Derive class BicycleModel from ParticleModel
class BicycleModel : public ParticleModel {
    public:
        void Move(double v, double phi) override {
            theta += v / L * tan(phi);
            x += v * cos(theta);
            y += v * cos(theta);
        }

        double L;
};

// TODO: Pass the tests
int main() {
  // Test function overriding
  ParticleModel particle;
  BicycleModel bicycle;
  particle.Move(10, PI / 9);
  bicycle.Move(10, PI / 9);
  assert(particle.x != bicycle.x);
  assert(particle.y != bicycle.y);
  assert(particle.theta != bicycle.theta);
}