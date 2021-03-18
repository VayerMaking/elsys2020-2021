package com.company;

import java.util.List;

public abstract class Hero {
    protected int level;
    protected int power;
    protected int intelligence;
    protected String special;

    public Hero(int level, int power, int intelligence, String special) {
        this.level = level;
        this.power = power;
        this.intelligence = intelligence;
        this.special = special;
    }

    abstract double getPower(List<Hero> party, Monster monster);

}
