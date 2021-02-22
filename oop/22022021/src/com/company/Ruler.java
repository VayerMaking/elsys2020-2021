package com.company;

public class Ruler extends Human implements ICommunist{

    public Ruler(String name, int age) {
        super(name, age);
    }

    @Override
    public boolean canTravel() {
        System.out.println("Ruler can travel?");
        super.canTravel();
        return true;
    }

    @Override
    public boolean canPreformGenocide() {
        return false;
    }

    @Override
    public void vote() {
        System.out.println("Great Ruler voted with 25 000 votes");
    }
}
