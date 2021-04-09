package com.company;

import static java.lang.Math.abs;

public class Scroll extends Item implements Equipable, Usable{
    int baseDamage;

    public Scroll(int baseDamage, String name) {
        super(name);
        this.baseDamage = baseDamage;
    }

    @Override
    public void use(Character source, Character target) {
        int diff = abs(source.getIntelligence() - target.getIntelligence());
        target.setCurrentHealth(target.getCurrentHealth() - (baseDamage + 10 / 100 * baseDamage));
    }
}
