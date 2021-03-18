package com.company;

import java.util.List;

public class Wizard extends Hero{
    public Wizard(int level, int power, int intelligence, String special) {
        super(level,  power, intelligence, special);

    }

    @Override
    double getPower(List<Hero> party, Monster monster) {
        int d = 0, e = 0, s = 0, h = 0;
        int power = this.level * this.intelligence;

            for(int i =0; i < monster.traits.size(); i++) {
            String trait = monster.traits.get(i);

            switch(trait) {
                case "Darkness": d += 1;
                case "Evil": e += 1;
                case "Summoned": s += 1;
                case "Holy": h += 1;
            }
        }

            switch(this.special) {
            case "Cleric": power += (d+e)*(1/4)*power;
            case "Sorcerer": power += (s+e)*(1/4)*power;
            case "Warlock": power += h*(1/4)*power;
        }

            return power;
    }
}
