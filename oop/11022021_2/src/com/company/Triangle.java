package com.company;

import static java.lang.Math.pow;
import static java.lang.Math.sqrt;

public class Triangle {

    private Point a;
    private Point b;
    private Point c;

    public Triangle(Point a, Point b, Point c){
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public double getPerimeter(){
        double sideA = distance(this.b, this.c);
        double sideB = distance(this.a, this.c);
        double sideC = distance(this.a, this.b);

        return sideA + sideB + sideC;
    }

    private double distance(Point a, Point b) {
        double side = sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
        return side;
    }

    public double getArea(){
        double p = this.getPerimeter() / 2;
        double sideA = distance(this.b, this.c);
        double sideB = distance(this.a, this.c);
        double sideC = distance(this.a, this.b);

        double area = sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));

        return area;
    }

    public Point getA() {
        return a;
    }

    public Point getB() {
        return b;
    }

    public Point getC() {
        return c;
    }

    @Override
    public String toString() {
        return "Triangle{" +
                "a=" + a +
                ", b=" + b +
                ", c=" + c +
                ", area=" + this.getArea() +
                ", perimeter=" + this.getPerimeter() +
                '}';
    }
}

