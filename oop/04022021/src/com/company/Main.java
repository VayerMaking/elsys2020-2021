package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Point p1 = new Point(0,0);
        Point p2 = new Point(1,0);
        Point p3 = new Point(2,5);
        Point p4 = new Point(1,1);
        Point p5 = new Point(2,2);
        Point p6 = new Point(3,4);
        Triangle t1 = new Triangle(p1, p2, p3);
        Rectangle r1 = new Rectangle(p4, p5);
        Circle c1 = new Circle(p1, 1);

        System.out.println(c1.area());
        System.out.println(c1.lenght());
        System.out.println(t1.area());
        System.out.println(t1.lenght());
        System.out.println(r1.area());
        System.out.println(r1.lenght());


    }
}
