package com.company;

import java.util.ArrayList;

public class Base {
    int crystalsInBase;
    int workerCount;

    public Base() {
        this.crystalsInBase = 50;
        this.workerCount = 0;
    }

    void createWorker(ArrayList<Crystal> crystals){
        if(workerCount < 20 && crystalsInBase >= 50){
            System.out.println("Creating worker...");
            Worker newWorker = new Worker(String.valueOf(workerCount + 1), 0, crystals);
            crystalsInBase -= 50;
            workerCount += 1;
            System.out.println("Worker created...");
            System.out.println("Starting worker...");
            newWorker.run();
        }

    }
}
