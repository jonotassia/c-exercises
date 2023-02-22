#include <iostream>

using std::cout;

void Hello() {
    cout << "Hello, World!" << "\n";
};

class Human {};

void Hello(Human human) {
    cout << "Hello, Human!" << "\n";
};

int main() {
    Hello();
    Hello(Human());
}