package com.elsys.fitness.trainers;

import com.elsys.fitness.*;
import com.elsys.fitness.employee.Employee;
import com.elsys.fitness.exceptions.TrainingException;
import com.elsys.fitness.training.Training;
import com.elsys.fitness.training.TrainingType;

import java.util.List;

public class PersonalTrainer extends Employee implements Trainer {
    private int trainedCustomers = 0;

    public PersonalTrainer(String firstName, String lastName, Fitness fitness) {
        super(firstName, lastName, fitness);
    }

    public PersonalTrainer(String firstName, String lastName, double salary, Fitness fitness) {
        super(firstName, lastName, salary, fitness);
    }

    @Override
    public int getTrainedCustomers() {
        return trainedCustomers;
    }

    @Override
    public void performTraining(Training training, List<Customer> customers) throws TrainingException {
        if(training.getTrainingType() != TrainingType.PERSONAL_TRAINING) {
            throw new TrainingException("Fitness trainers can perform only fitness trainings");
        }

        if(customers.size() != 1) {
            throw new TrainingException("Only one customer can attend fitness training");
        }

        for(Customer customer : customers) {
            customer.performTraining(training);
            trainedCustomers++;
        }

    }
}
