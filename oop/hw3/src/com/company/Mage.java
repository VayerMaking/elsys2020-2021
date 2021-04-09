package com.company;

public class Mage extends Character{
    int maxMana;
    int currentMana;

    public Mage(int maxMana, int currentMana) {
        super(60, 60, 10, 5);
        this.maxMana = maxMana;
        this.currentMana = currentMana;
    }

    @Override
    protected String getCharacterClass() {
        return "Mage";
    }
}
