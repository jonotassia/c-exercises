#include <cassert>
#include <stdexcept>

// TODO: Define class Pyramid

class Pyramid {
    public:
       Pyramid(int h, int w, int l);
       int Height() const;
       void SetHeight(int h);
       int Width() const;
       void SetWidth(int w);
       int Length() const;
       void SetLength(int l);
       int Volume() const;

    private:
        int height_{0};
        int length_{0};
        int width_{0};
};

// constructor
Pyramid::Pyramid(int h, int w, int l) const {
    height_ = h;
    width_ = w;
    length_ = l;
};

// accessors
int Pyramid:: Height() const {
    return height_;
};

int Pyramid::Length() const {
    return length_;
};

int Pyramid::Width() const {
    return width_;
};

// mutators
void Pyramid::SetHeight(int h) {
    if (h > 0) {
        height_ = h;
    }
};

void Pyramid::SetWidth(int w) {
    if (w > 0) {
        width_ = w;
    }
};

void Pyramid::SetLength(int l) {
    if (l > 0) {
        length_ = l;
    }
};

// public Volume() function
int Pyramid::Volume() const {
    return (Length() * Width() * Height())/3;
}

// Test
int main() {
  Pyramid pyramid(6, 5, 4);
  assert(pyramid.Length() == 4);
  assert(pyramid.Width() == 5);
  assert(pyramid.Height() == 6);
  assert(pyramid.Volume() == 40);

  bool caught{false};
  try {
    Pyramid invalid(3, 2, -1);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}