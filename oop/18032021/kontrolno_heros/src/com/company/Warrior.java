package com.company;

import java.util.List;

public class Warrior extends Hero {

    public Warrior(int level, int power, int intelligence, String special) {
        super(level,  power, intelligence, special);

    }

    @Override
    double getPower(List<Hero> party, Monster monster) {
        double result= 0;

        switch (this.special){
            case "Knight":
                int clericCounter = 0;
                for(Hero member : party) {
                    if (member.special == "Cleric") clericCounter ++;
                }
                result = this.power * this.level + clericCounter * (0.25 * this.power);
                break;
            case "Barbarian":
                result = this.power * this.level;
                break;
        }
        return result;
    }
}