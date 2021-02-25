package com.company;

public class Main {

    public static void main(String[] args) throws Exception{
        Hero player1 = new Hero();
        player1.name = "Pesho";

        Weapon weapon1 = new Weapon();
        weapon1.name = "w1";
        weapon1.damage = 10;

        Armor armor1 = new Armor();
        armor1.name = "ar1";
        armor1.defence = 10;

        Potion potion1 = new Potion();
        potion1.name = "p1";

        Weapon weapon2 = new Weapon();
        weapon2.name = "w2";
        weapon2.damage = 20;

        Armor armor2 = new Armor();
        armor2.name = "ar2";
        armor2.defence = 10;

        Potion potion2 = new Potion();
        potion2.name = "p2";

        player1.equipItem(weapon1);
        player1.equipItem(armor1);
        player1.equipItem(potion1);
    }
}
