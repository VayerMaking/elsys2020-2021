package com.company;

// coffee takes intelligence from the target and gives it to the one that used it
public class Coffee extends Item implements Equipable, Usable{
    int mindPower;

    public Coffee(int mindPower, String name) {
        super(name);
        this.mindPower = mindPower;
    }

    @Override
    public void use(Character source, Character target) {
        source.intelligence += mindPower;
        target.intelligence -= mindPower;
    }
}
