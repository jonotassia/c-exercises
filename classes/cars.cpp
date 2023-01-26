#include <string>
#include <cstring>
#include <iostream>

using std::string;

class Car {
    // TODO: Declare private attributes
    private:
        char* brand_;
        
    // TODO: Declare getter and setter for brand
    public:
        string GetBrand();
        void SetBrand(string s);

        int horsepower_{0};
        int weight_{0};
};

// Define setters

string Car::GetBrand() { 
    string s(brand_);
    return s;
}

void Car::SetBrand(string s) {
    brand_ = &(s[0]);
}

// Test in main()
int main() 
{
    Car car;
    car.SetBrand("Peugeot");
    std::cout << car.GetBrand() << "\n";   
}