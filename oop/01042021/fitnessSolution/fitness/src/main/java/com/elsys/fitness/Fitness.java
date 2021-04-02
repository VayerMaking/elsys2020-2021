package com.elsys.fitness;

import com.elsys.fitness.employee.EmployeeType;
import com.elsys.fitness.employee.RegisterEmployee;
import com.elsys.fitness.exceptions.FitnessException;
import com.elsys.fitness.exceptions.NoCardsAvailableException;
import com.elsys.fitness.exceptions.TrainingException;
import com.elsys.fitness.trainers.PersonalTrainer;
import com.elsys.fitness.trainers.GroupTrainer;
import com.elsys.fitness.trainers.Trainer;
import com.elsys.fitness.training.Training;
import com.elsys.fitness.training.TrainingType;
import com.elsys.fitness.util.RandomGenerator;

import java.util.*;

public class Fitness {
    static final int DEFAULT_CARDS_TO_GENERATE = 10;
    private List<Card> availableCards = new ArrayList<>();
    private List<Trainer> fitnessTrainers = new ArrayList<>();
    private List<Trainer> groupTrainers = new ArrayList<>();
    private List<RegisterEmployee> registerEmployees = new ArrayList<>();
    private Map<String, Customer> customers = new HashMap<>();
    private String name;
    private int id;

    public Fitness(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public List<Card> getAvailableCards() {
        return availableCards;
    }

    public void addCustomer(String cardNumber, Customer customer) {
        customers.put(cardNumber, customer);
    }

    private void createNewCards(int count) {
        for (int i = 0; i < count; i++) {
            Card card = new Card();
            availableCards.add(card);
        }
    }

    public void hireEmployee(String firstName, String lastName, EmployeeType employeeType) {
        switch (employeeType) {
            case GROUP_TRAINER:
                GroupTrainer groupTrainer = new GroupTrainer(firstName, lastName, this);
                groupTrainers.add(groupTrainer);
                break;
            case PERSONAL_TRAINER:
                PersonalTrainer personalTrainer = new PersonalTrainer(firstName, lastName, this);
                fitnessTrainers.add(personalTrainer);
                break;
            case REGISTER_EMPLOYEE:
                RegisterEmployee registerEmployee = new RegisterEmployee(firstName, lastName, this);
                registerEmployees.add(registerEmployee);
                break;
        }
    }

    public List<Trainer> getOrderedFitnessTrainers() {
        List<Trainer> allTrainers = new ArrayList();
        allTrainers.addAll(fitnessTrainers);
        allTrainers.addAll(groupTrainers);

        allTrainers.sort(new Comparator<Trainer>() {
            @Override
            public int compare(Trainer trainer, Trainer otherTrainer) {
                return (-(trainer.getTrainedCustomers() - otherTrainer.getTrainedCustomers()));
            }
        });

        return allTrainers;
    }

    public Customer registerCustomer(String firstName, String lastName) throws FitnessException {
        if (registerEmployees.size() < 1) {
            throw new FitnessException("No register employees available!");
        }

        RegisterEmployee employee = registerEmployees.get(RandomGenerator.generateRandomInt(registerEmployees.size()));
        try {
            return employee.registerCustomer(firstName, lastName);
        } catch (NoCardsAvailableException e) {
            createNewCards(DEFAULT_CARDS_TO_GENERATE);
            return registerCustomer(firstName, lastName);
        }
    }

    public void performTraining(String name, TrainingType trainingType, List<Customer> customers) throws TrainingException, FitnessException {
        checkCustomers(customers);
        switch (trainingType) {
            case GROUP_TRAINING:
                Trainer groupTrainer = getRandomTrainer(groupTrainers);
                groupTrainer.performTraining(new Training(name, trainingType), customers);
                break;
            case PERSONAL_TRAINING:
                Trainer fitnessTrainer = getRandomTrainer(fitnessTrainers);
                fitnessTrainer.performTraining(new Training(name, trainingType), customers);
                break;
        }
    }

    private void checkCustomers(List<Customer> customers) throws FitnessException {
        for (Customer customer : customers) {
            if(!this.customers.containsValue(customer)) {
                throw new FitnessException("Customer: " + customer + " is not registered in this fitness!");
            }
        }
    }

    private Trainer getRandomTrainer(List<Trainer> trainers) throws FitnessException {
        if (trainers.size() < 1) {
            throw new FitnessException("No trainers are available!");
        }
        return trainers.get(RandomGenerator.generateRandomInt(trainers.size()));
    }
}
