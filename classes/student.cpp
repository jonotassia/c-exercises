#include <cassert>
#include <stdexcept>
#include <string>
#include <iostream>

using std::string;

// TODO: Define "Student" class
class Student {
 public:
  // constructor
  Student(string name, int grade, float gpa) {
    SetName(name);
    SetGrade(grade);
    SetGPA(gpa);
  }

  // accessors
  string Name() const {
    return name_;
  }

  int Grade() const {
    return grade_;
  }

  float GPA() const {
    return gpa_;
  }

  // mutators
  void SetName(string n) {
    if (n.size() > 0) {
        name_ = n;
    }

    else {
        throw std::invalid_argument("Undefined value");
    }
  }

  void SetGrade(int g) {
    if (g >= 0 && g <= 12) {
        grade_ = g;
    }

    else {
        throw std::invalid_argument("Undefined value");
    }
  }

  void SetGPA(float gpa) {
    if (gpa >= 0 && gpa <= 4.0) {
        gpa_ = gpa;
    }

    else {
        throw std::invalid_argument("Undefined value");
    }
  }

 private:
  string name_;
  int grade_;
  float gpa_{0};
};

// TODO: Test
int main() {
    bool caught;
    
    Student jono("Jono", 1, 3.3);
    assert(jono.Name() == "Jono");
    assert(jono.Grade() == 1);
    assert(abs(jono.GPA() - 3.3) < 0.005f);

    try
    {
        jono.SetGrade(-1);
    }
    catch(...)
    {
        std::cout << "Not allowed.";
    }
}