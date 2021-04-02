package com.elsys.fitness.trainers;

import com.elsys.fitness.*;
import com.elsys.fitness.employee.Employee;
import com.elsys.fitness.exceptions.TrainingException;
import com.elsys.fitness.training.Training;
import com.elsys.fitness.training.TrainingType;

import java.util.List;

public class GroupTrainer extends Employee implements Trainer {
    public GroupTrainer(String firstName, String lastName, Fitness fitness) {
        super(firstName, lastName, fitness);
    }

    public GroupTrainer(String firstName, String lastName, double salary, Fitness fitness) {
        super(firstName, lastName, salary, fitness);
    }

    private int trainedCustomers = 0;

    @Override
    public int getTrainedCustomers() {
        return trainedCustomers;
    }

    @Override
    public void performTraining(Training training, List<Customer> customers) throws TrainingException {
        if(training.getTrainingType() != TrainingType.GROUP_TRAINING) {
            throw new TrainingException();
        }

        if(customers.size() < 3) {
            throw new TrainingException();
        }

        for(Customer customer : customers) {
            customer.performTraining(training);
            trainedCustomers++;
        }
    }
}
