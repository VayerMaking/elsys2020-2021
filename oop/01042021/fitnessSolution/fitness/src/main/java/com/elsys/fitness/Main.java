package com.elsys.fitness;

import com.elsys.fitness.employee.EmployeeType;
import com.elsys.fitness.exceptions.FitnessException;
import com.elsys.fitness.exceptions.TrainingException;
import com.elsys.fitness.training.TrainingType;
import com.elsys.fitness.util.RandomGenerator;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) throws FitnessException, TrainingException {
        Fitness fitness = new Fitness(1, "Pulse");
        fitness.hireEmployee("Ivan", "Ivanov", EmployeeType.REGISTER_EMPLOYEE);
        fitness.hireEmployee("Georgi", "Georgiev", EmployeeType.GROUP_TRAINER);
        fitness.hireEmployee("Petar", "Petrov", EmployeeType.PERSONAL_TRAINER);
        Customer customer = fitness.registerCustomer("Stoqn", "Stoqnov");
        fitness.performTraining("first", TrainingType.PERSONAL_TRAINING, Collections.singletonList(customer));
        Card card = new Card();
        Customer customer1 = new Customer("Test", "Test", card);
        List<Customer> customers = new ArrayList<>();
        Collections.addAll(customers, customer, customer1);
        fitness.performTraining("second", TrainingType.GROUP_TRAINING, customers);
        fitness.getOrderedFitnessTrainers();
    }
}
