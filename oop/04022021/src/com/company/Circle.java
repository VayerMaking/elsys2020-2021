package com.company;

public class Circle {
    Point p1;
    float r;

    public Circle(Point p1, int r) {
        this.p1 = p1;
        this.r = r;
    }

    float area(){
        float area = (float) (r * 3.14 * 3.14);
        return area;
    }

    float lenght(){
        float lenght = (float) (2 * 3.14 * r);
        return lenght;
    }
}
