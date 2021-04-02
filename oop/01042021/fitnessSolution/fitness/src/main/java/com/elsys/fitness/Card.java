package com.elsys.fitness;

import com.elsys.fitness.util.RandomGenerator;

public class Card {
    public static final int DEFAULT_TRAININGS_COUNT = 10;
    private String number;
    private int remainingTrainings;

    public Card() {
        number = RandomGenerator.generateRandomString();
        remainingTrainings = DEFAULT_TRAININGS_COUNT;
    }

    public Card(int amountOfTrainings) {
        this();
        if(amountOfTrainings < 1) {
            throw new IllegalArgumentException("Amount of trainings should be more than 0!");
        }
        remainingTrainings = amountOfTrainings;
    }

    public String getCardNumber() {
        return number;
    }

    public int getRemainingTrainings() {
        return remainingTrainings;
    }

    public void performTraining() {
        remainingTrainings--;
    }

    @Override
    public String toString() {
        return "Card{" +
                "number='" + number + '\'' +
                ", remainingTrainings=" + remainingTrainings +
                '}';
    }
}
