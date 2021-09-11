package com.company;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
	// write your code here
        ArrayList<Crystal> crystals = new ArrayList<>();
        Crystal crystal1 = new Crystal();
        Crystal crystal2 = new Crystal();
        Crystal crystal3 = new Crystal();
        //crystal1.currentAmount = 0;
        crystals.add(crystal1);
        crystals.add(crystal2);
        crystals.add(crystal3);

        Base base = new Base();

        System.out.println(base.crystalsInBase);
        while(true){
            try {
                System.out.println("curentcrystals: " + base.crystalsInBase);
                base.createWorker(crystals);

            }catch(Exception e){
                e.printStackTrace();
            }
        }


        //Worker worker1 = new Worker("1", 0, crystals);
        //worker1.run();
    }
}
