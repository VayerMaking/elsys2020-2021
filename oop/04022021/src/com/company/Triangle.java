package com.company;

public class Triangle {
    Point p1;
    Point p2;
    Point p3;

    public Triangle(Point p1, Point p2, Point p3) {
        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;
    }

    int area(){
        int a = p2.x - p1.x;
        int h = p3.y - p1.y;
        int area = a * h / 2;
        return area;
    }

    int lenght(){
        return 4;
    }
}
