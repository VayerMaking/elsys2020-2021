package com.company;

public class Potion extends Item implements Equipable, Consumable{
    int restoreMana;
    int restoreHealth;

    public Potion(int restoreMana, int restoreHealth, String name) {
        super(name);
        this.restoreMana = restoreMana;
        this.restoreHealth = restoreHealth;
    }


    @Override
    public void consume(Character target) {
        target.currentHealth += restoreHealth;
        if(target instanceof Mage) {
            ((Mage) target).currentMana += restoreMana;
        }
    }
}
