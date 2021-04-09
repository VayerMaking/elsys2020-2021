package com.company;

public class Archer extends Character{

    public Archer() {
        super(100, 100, 5, 10);
    }

    @Override
    protected String getCharacterClass() {
        return "Archer";
    }
}
