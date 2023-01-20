#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::istringstream;
using std::string;
using std::vector;
using std::cout;

int main() {
    string s = "I have 1 puppy.";

    istringstream stream(s);

    char c;
    vector<char> v;

    while (stream >> c) {
        v.push_back(c);
    }
    cout << v[2] << "\n";
    cout << "\n" << "Complete.";
}