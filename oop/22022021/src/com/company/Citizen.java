package com.company;

public class Citizen extends Human implements ICommunist{
    public Citizen(String name, int age) {
        super(name, age);
    }

    @Override
    public void vote() {
        System.out.println("i vote with 1 vote");
    }
}
