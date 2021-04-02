package com.elsys.fitness.trainers;

import com.elsys.fitness.Customer;
import com.elsys.fitness.training.Training;
import com.elsys.fitness.exceptions.TrainingException;

import java.util.List;

public interface Trainer {
    int getTrainedCustomers();
    void performTraining(Training training, List<Customer> customers) throws TrainingException;
}
