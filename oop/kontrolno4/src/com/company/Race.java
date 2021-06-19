package com.company;

import java.util.ArrayList;

public class Race implements Runnable{
    ArrayList <Car> cars;
    int laps;
    ArrayList <Float> track;

    public Race(int laps) {
        this.laps = laps;
        this.cars = new ArrayList<Car>();
    }

    void addCar(Car car ){
        cars.add(car);
    }

    void changeTrack(ArrayList <Float> newTrack, int newLaps){
        track = newTrack;
        laps = newLaps;
    }

    void reset(Race race){
        race.cars.clear();
        race.track.clear();
    }

    @Override
    public void run() {

    }
}
