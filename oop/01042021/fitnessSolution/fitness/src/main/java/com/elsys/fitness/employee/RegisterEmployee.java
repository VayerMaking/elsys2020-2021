package com.elsys.fitness.employee;

import com.elsys.fitness.Card;
import com.elsys.fitness.Customer;
import com.elsys.fitness.Fitness;
import com.elsys.fitness.exceptions.NoCardsAvailableException;
import com.elsys.fitness.util.RandomGenerator;

public class RegisterEmployee extends Employee {

    public RegisterEmployee(String firstName, String lastName, Fitness fitness) {
        super(firstName, lastName, fitness);
    }

    public RegisterEmployee(String firstName, String lastName, double salary, Fitness fitness) {
        super(firstName, lastName, salary, fitness);
    }

    public Customer registerCustomer(String firstName, String lastName) throws NoCardsAvailableException {
        if (fitness.getAvailableCards().size() < 1) {
            throw new NoCardsAvailableException();
        }

        Card card = fitness.getAvailableCards().remove(RandomGenerator.generateRandomInt(fitness.getAvailableCards().size()));
        Customer customer = new Customer(firstName, lastName, card);

        fitness.addCustomer(card.getCardNumber(), customer);

        return customer;
    }
}
