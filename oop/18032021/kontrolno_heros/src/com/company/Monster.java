package com.company;

import com.company.Hero;

import java.util.List;

public class Monster {
    int level;
    int power;
    String name;
    List<String> traits;

    public Monster(int level, int power, String name, List<String> traits) {
        this.level = level;
        this.power = power;
        this.name = name;
        this.traits = traits;
    }

    int getPower(List<Hero> party) {
        double output = 0;
        int counter = 0;

        switch (name){
            case "Darkness":
                for (Hero member : party) {
                    if(member.special == "Cleric") counter++;
                }
                output = power*level + counter*(0.25*power*level);
                break;

            case "Evil":
                for (Hero member : party) {
                    if(member.special == "Knight" || member.special == "Monk") counter++;
                }
                output = power*level + counter*(0.25*power*level);
                break;

            case "Summoned":
                for (Hero member : party) {
                    if(member.special == "Barbarian") counter++;
                }
                output = power*level + counter*(0.25*power*level);
                break;

            case "Holy":
                for (Hero member : party) {
                    if(member.special == "Warlock") counter++;
                }
                output = power*level + counter*(0.25*power*level);
                break;

        }

        return (int) output;
    }
}