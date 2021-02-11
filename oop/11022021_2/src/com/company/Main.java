package com.company;

public class Main {

    public static void main(String[] args) {

        Point a = new Point(1, 2);
        Point b = new Point(3, 5);
        Point c = new Point(2, 6);

        Point a4 = new Point(0, 0);
        Point b4 = new Point(1, 1);
        Point c4 = new Point(2, 0);

        Point a1 = new Point(2, 2);
        Point b1 = new Point(-1, 0);
        Point c1 = new Point(10, 4);

        Point a3 = new Point(0, 5);
        Point b3 = new Point(1, 1);
        Point c3 = new Point(6, -2);

        Triangle t = new Triangle(a, b, c);
        Triangle t1 = new Triangle(a1, b1, c1);
        Triangle t2 = new Triangle(a3, b3, c3);
        Triangle t3 = new Triangle(a4, b4, c4);

        Triangle[] arr = {t, t1, t2, t3};

        Triangle demo = biggestArea(arr);
        System.out.println("Biggest area: " + demo.getArea());
        demo = smallestArea(arr);
        System.out.println("Smallest area: " + demo.getArea());

        demo = biggestPerimeter(arr);
        System.out.println("Biggest perimeter: " + demo.getPerimeter());
        demo = smallestPerimeter(arr);
        System.out.println("Smallest perimeter: " + demo.getPerimeter());

        for(int i = 0; i < arr.length; i++){
            System.out.println(arr[i]);
        }

    }

    public static Triangle biggestArea(Triangle[] arr){

        Triangle temp = arr[0];

        for(int i = 1; i < arr.length; i++){

            if(arr[i].getArea() > temp.getArea()){
                temp = arr[i];
            }
        }

        return temp;
    }

    public static Triangle smallestArea(Triangle[] arr){

        Triangle temp = arr[0];

        for(int i = 1; i < arr.length; i++){

            if(arr[i].getArea() < temp.getArea()){
                temp = arr[i];
            }
        }

        return temp;
    }

    public static Triangle biggestPerimeter(Triangle[] arr){

        Triangle temp = arr[0];

        for(int i = 1; i < arr.length; i++){

            if(arr[i].getPerimeter() > temp.getPerimeter()){
                temp = arr[i];
            }
        }

        return temp;
    }

    public static Triangle smallestPerimeter(Triangle[] arr){

        Triangle temp = arr[0];

        for(int i = 1; i < arr.length; i++){

            if(arr[i].getPerimeter() < temp.getPerimeter()){
                temp = arr[i];
            }
        }

        return temp;
    }

}
