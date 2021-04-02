package com.company;

import java.util.List;

public class FitnessTrainer extends Worker{

    public FitnessTrainer(String firstName, String lastName, int salary) throws Exception {
        super(firstName, lastName, salary);
    }
    public void train(Workout work, Client client) throws Exception {
        if(!work.getType().equals("Fitness workout")){
            throw new Exception("Wrong workout type!");
        }
        client.train();
    }
}
