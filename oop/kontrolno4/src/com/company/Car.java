package com.company;

import java.util.List;

public class Car implements Runnable{
    static int carCount;
    int currentPos = 1;
    String driverName;
    int currentLap;
    List <Float> times;

    public Car(String driverName) {
        this.driverName = driverName;
    }

    public Car(int currentPos, String driverName, int currentLap) {
        this.currentPos = currentPos;
        this.driverName = driverName;
        this.currentLap = currentLap;
    }

    void reset(Car car){
        car.currentPos = 1;
        car.currentLap = 0;
        car.times.clear();
    }

    @Override
    public void run() {

    }
}
