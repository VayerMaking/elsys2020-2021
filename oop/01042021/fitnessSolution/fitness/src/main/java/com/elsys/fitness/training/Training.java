package com.elsys.fitness.training;

public class Training {
    private String name;
    private TrainingType trainingType;

    public Training(String name, TrainingType trainingType) {
        this.name = name;
        this.trainingType = trainingType;
    }

    public TrainingType getTrainingType() {
        return trainingType;
    }
}
