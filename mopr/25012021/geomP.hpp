#include <iostream>
#include <cmath>
using namespace std;

bool eq(double d1, double d2, double eps = 0.001) {
    return abs(d2 - d1) < eps;
}

struct Point {
    double x, y;

    Point(double x, double y) : x(x), y(y) {}

    void print(ostream& out) const {
        out<< "("<< x<< ", "<< y<< ")";
    }
};

ostream& operator<<(ostream& out, const Point& p) {
    p.print(out);
    return out;
}

/* struct Vector {
    double x, y;

    Vector(double x, double y) : x(x), y(y) {}
    Vector(const Point& p) : x(p.x), y(p.y) {}
    Vector(const Point& p1, const Point& p2) : x(p2.x-p1.x), y(p2.y-p1.y) {}

    Vector operator+(const Vector& v2) const {
        return Vector(x+v2.x, y+v2.y);
    }

    Vector operator-() const {
        return Vector(-x, -y);
    }

    Vector operator-(const Vector& v2) const {
        return *this + (-v2);
    }

    Vector operator*(const double a) const {
        return Vector(a*x, a*y);
    }

    double operator*(const Vector& v2) const {
        return x*v2.x + y*v2.y;
    }

    void print(ostream& out) const {
        out<< "("<< x<< ", "<< y<< ")";
    }
};

ostream& operator<<(ostream& out, const Vector& v) {
    v.print(out);
    return out;
} */

struct Line {
    double A, B, C;

    Line(double A, double B, double C) : A(A), B(B), C(C) {}

    Line(const Point& p1, const Point& p2) {
      double x1 = p1.x, y1 = p1.y, x2 = p2.x, y2 = p2.y;

      A = (y2 - y1) / (x2 - x1);
      B = -1;
      C = y1 - x1*A;
    }

    bool parallel(const Line& other) const {
      return eq(A/other.A, B/other.B);
    }

    Line parallel(const Point& p) {
        return Line(A, B , - (A*p.x + B*p.y));
    }

    bool perpendicular(const Line& other) const {
        return eq(-B/other.A, A/other.B);
    }

    Line perpendicular(const Point& p) {
        return Line(-B, A, B*p.x - A*p.y);
    }

    void print(ostream& out) const {
        out<< A << "x + "<< B<< "y + "<< C<< " = 0";
    }
};

ostream& operator<<(ostream& out, const Line& l) {
    l.print(out);
    return out;
}
