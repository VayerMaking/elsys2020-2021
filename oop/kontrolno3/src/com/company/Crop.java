package com.company;

public class Crop {
    String name;
    private int daysToGrow;
    private int currentDays;
    private boolean isDead;
    private boolean isCollected;

    public Crop(String name, int daysToGrow, int currentDays, boolean isDead, boolean isCollected) {
        this.name = name;
        this.daysToGrow = daysToGrow;
        this.currentDays = currentDays;
        this.isDead = isDead;
        this.isCollected = isCollected;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setDead(boolean dead) {
        isDead = dead;
    }

    public int getDaysToGrow() {
        return daysToGrow;
    }

    public int getCurrentDays() {
        return currentDays;
    }

    public boolean isDead() {
        return isDead;
    }

    public boolean isCollected() {
        return isCollected;
    }

    public void setCollected(boolean collected) {
        isCollected = collected;
    }

    public boolean isAVegetable() {
        return this.getClass().getSimpleName() == "Vegetable";
    }

    public boolean isACactus() {
        return this.getClass().getSimpleName() == "Cactus";
    }

    public boolean isAFruit() {
        return this.getClass().getSimpleName() == "Fruit";
    }
}
