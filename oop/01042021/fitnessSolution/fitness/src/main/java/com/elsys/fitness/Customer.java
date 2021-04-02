package com.elsys.fitness;

import com.elsys.fitness.training.Training;

import java.util.ArrayList;
import java.util.List;

public class Customer {
    private String firstName;
    private String lastName;
    private Card card;
    private List<Training> trainings = new ArrayList<>();

    public Customer(String firstName, String lastName, Card card) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.card = card;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public void performTraining(Training training) {
        trainings.add(training);
        card.performTraining();
    }

    public List<Training> getTrainings() {
        return trainings;
    }

    public Card getCard() {
        return card;
    }

    @Override
    public String toString() {
        return "Customer{" +
                "firstName='" + firstName + '\'' +
                ", lastName='" + lastName + '\'' +
                ", card=" + card +
                '}';
    }
}
