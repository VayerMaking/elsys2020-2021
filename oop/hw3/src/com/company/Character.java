package com.company;

import java.util.ArrayList;

public abstract class Character {
    int currentHealth;
    int maxHealth;
    int intelligence;
    int dexterity;
    ArrayList<Item> hotbar = new ArrayList<>(3);
    ArrayList<Item> inventory = new ArrayList<>(10);

    public Character(int currentHealth, int maxHealth, int intelligence, int dexterity) {
        this.currentHealth = currentHealth;
        this.maxHealth = maxHealth;
        this.intelligence = intelligence;
        this.dexterity = dexterity;
    }

    public int getCurrentHealth() {
        return currentHealth;
    }

    public int getMaxHealth() {
        return maxHealth;
    }

    public int getIntelligence() {
        return intelligence;
    }

    public int getDexterity() {
        return dexterity;
    }

    public void setCurrentHealth(int currentHealth) {
        this.currentHealth = currentHealth;
    }

    abstract protected String  getCharacterClass();

    public String toString(){
        return "current health: " + String.valueOf(currentHealth) + ", class: " + getCharacterClass();
    }

    public void pick(Item newItem){
        if(newItem instanceof Equipable){
            hotbar.add(newItem);
        }else{
            inventory.add(newItem);
        }
    }

    public void useAt(int index, Character target){
        Item item = hotbar.get(index);
        if(item instanceof Consumable){
            ((Consumable) item).consume(this);
        }else if(item instanceof Usable){
            ((Usable) item).use(this, target);
        }
    }

}
