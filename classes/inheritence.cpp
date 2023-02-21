#include <string>
#include <iostream>

using std::string;
using std::cout;

// Define base class Animal
class Animal {
    public:
        string color = "red";
        string name = "Buddy";
        int age = 0;
};

// Declare derived class Snake
class Snake : public Animal {
public:
    int length = 2;
    
    void MakeSound() {
        cout << "Hissss!" << "\n";
    }
};

// Declare derived class Cat
class Cat : Animal {
public:
    int height = 4;
    
    void MakeSound() {
        cout << "Meow!" << "\n";
    }
};


// Test in main()
int main() {
    Cat cat;
    Snake snake;
    cat.MakeSound();
    snake.MakeSound();
}