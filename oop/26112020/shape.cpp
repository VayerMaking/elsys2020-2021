#include<iostream>
#include<cmath>

using namespace std;

class Shape{
public:
  virtual float get_area() const{
    return 0;
  }
  virtual float get_parameter() const{
    return 0;
  }

};

class Square : public Shape{
public:
  float a;
  float get_area() const override {return a*a;}
  float get_parameter() const override {return 4*a;}
};

class Circle : public Shape{
public:
  float r;
  float get_area() const override {return 3.14*std::pow(r, 2);}
  float get_parameter() const override {return 2*3.14*r;}
};

class Rectangle : public Shape{
public:
  float a,b;
  float get_parameter() const override {return (a+b)*2;}
  float get_area() const override {return a*b;}
};

void print_area_and_shape(const Shape& s){
  cout << "Area: "<< s.get_area() << endl;
  cout << "Perimeter: "<< s.get_parameter() << endl;
}

int main(){
    Shape shape;
    //square/////////////////////////////
    Square squ;
    squ.a = 2;
    cout << squ.get_area() << endl;
    cout << squ.get_parameter() << endl;
    //circle////////////////////////////
    Circle circle;
    circle.r = 1;
    cout << circle.get_parameter() << endl;
    cout << circle.get_area() << endl;
    //rectangle//////////////////////////
    Rectangle rect;
    rect.a = 1;
    rect.b = 2;
    cout << rect.get_parameter() << endl;
    cout << rect.get_area() << endl;
    print_area_and_shape(rect);
    print_area_and_shape(circle);
    print_area_and_shape(squ);
    return 0;
}
