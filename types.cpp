#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::cout;

int main() {
    // Primitive Datatypes
    int a = 5;
    std::string b = "b";
    
    cout << a << "\n";
    cout << b << "\n";

    // 1d Vectors
    vector<int> v_1{0, 1, 2};
    vector<std::string> v_2 = {"3", "4", "5"};
    vector<int> v_3;
    v_3 = {6};

    for (std::string i : v_2) {
        cout << i << "\n";
    }

    cout << "Everything worked!" << "\n";

    // 2d Vectors
    vector<vector<int>> v {{1,2}, {3,4}};
    cout << "Great! A 2d vector has been created." << "\n";

    // Enum
    enum class Friend {Jono, Wald, DevonDog, TheGreenMan};

    Friend bestFriend = Friend::Wald;

    if (bestFriend == Friend::Wald) {
        cout << "That is my best friend." << "\n";
    }
}