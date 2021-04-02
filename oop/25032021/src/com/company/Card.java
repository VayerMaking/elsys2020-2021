package com.company;

public class Card {
    private String number;
    private int visits;

    public Card(String number) {
        this.number = number;
        this.visits = 10;
    }

    public String getNumber() {
        return number;
    }

    public int getVisits() {
        return visits;
    }
    public void setVisits(int visits) {
        this.visits = visits;
    }
}
