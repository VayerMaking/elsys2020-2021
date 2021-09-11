package com.company;

import java.util.ArrayList;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Worker implements Runnable{
    String worker_id;
    int crystalsInWorker;
    ArrayList<Crystal> crystals;
    int currentCrystal;

    public Worker(String worker_id, int crystalsInWorker, ArrayList<Crystal> crystals) {
        this.worker_id = worker_id;
        this.crystalsInWorker = crystalsInWorker;
        this.crystals = crystals;
    }

    private Lock lock = new ReentrantLock();

    @Override
    public void run() {
        synchronized (lock) {

            try {
                System.out.println("Hello from worker" + worker_id);
                while (crystals.size() > 0) {
                    System.out.println(crystals.size());
                    lock.notifyAll();
                    for (Crystal crystal : crystals) {
                        if (crystal.currentAmount == 0) {
                            crystals.remove(crystal);
                        }
                    }
                    for (Crystal crystal : crystals) {
                        if (crystal.workersOnSite < 2) {
                            currentCrystal = crystals.indexOf(crystal);
                        }
                        Thread.sleep(500);
                    }
                    //lock.wait();
                    Thread.sleep(1000);
                    ///lock.notify();
                    for (Crystal crystal : crystals) {
                        if (crystal.workersOnSite < 2) {
                            currentCrystal = crystals.indexOf(crystal);
                        }
                        Thread.sleep(500);
                    }
                    //lock.wait();
                    System.out.println("Woker: " + worker_id + "Minging from " + crystals.get(0));
                    Thread.sleep(1500);
                    //lock.notify();
                    crystals.get(currentCrystal).currentAmount -= 20;
                    crystalsInWorker += 20;
                    System.out.println("Woker: " + worker_id + "Mined from " + crystals.get(0));
                    lock.wait();
                    System.out.println("Woker: " + worker_id + "returning to base");
                    Thread.sleep(1000);
                    Thread.sleep(500);
                }
                System.out.println("program ended, no more crystals");


            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
