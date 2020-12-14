#include <iostream>
#include <cmath>

using namespace std;

struct Point{
  double x;
  double y;

  Point(double x, double y) : x(x), y(y) {}
};

class Vector{
public:
  double x;
  double y;
  Vector(double x, double y) : x(x), y(y) {}
  Vector(Point p1, Point p2) : x(p2.x - p1.x), y(p2.y - p1.y) {}
  void sum(const Vector& other) const{
    cout << "(" << x << ", " << y << ") + (" << other.x << ", " << other.y << ")" << " = ";
    cout << "(" << x + other.x << ", " << y + other.y << ")" << endl;
  }

  void difference(const Vector& other) const {
    cout << "(" << x << ", " << y << ") - (" << other.x << ", " << other.y << ")" << " = ";
    cout << "(" << x + (-other.x) << ", " << y + (-other.y) << ")" << endl;
  }

  Vector operator+(const Vector& other) const {
    return Vector(x + other.x, y + other.y);
  }

  Vector operator-() const {
    return Vector(-x, -y);
  }

  Vector operator-(const Vector& other) const {
    return *this + (-other);
  }

  bool is_colinear(const Vector& other) const {
    return x/y == other.x/other.y;
  }

  double lenght() const {
    return sqrt(x*x + y*y);
  }

  double angle(const Vector& other) const {
    double dot = x*other.x + y*other.y;
    double Acos = (dot / (this->lenght() * other.lenght()));
    return acos(Acos);
  }
};

int main(){
  Vector v1 = Vector(Point(0, 0), Point(3, 5));
  Vector v2 = Vector(Point(3, 5), Point(7, 3));
  v1.sum(v2);
  return 0;
}
