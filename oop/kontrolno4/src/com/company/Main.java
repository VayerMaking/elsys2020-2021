package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Car car1 = new Car(2, "julio", 0);
        Car car2 = new Car(1, "rodrigo", 0);
        Car car3 = new Car(4, "sulio", 0);
        Car car4 = new Car(3, "pulio", 0);

        Race race = new Race(5);
        race.cars.add(car1);
        race.cars.add(car2);
        race.cars.add(car3);
        race.cars.add(car4);

        System.out.println(race.cars);
    }
}
