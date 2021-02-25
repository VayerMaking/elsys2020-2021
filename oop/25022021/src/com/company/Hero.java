package com.company;

public class Hero {
    String name;
    Equip equip = new Equip();
    Bag bag = new Bag();

    void equipItem(Item item) throws Exception{
        if(item instanceof Weapon){
            for(int i = 0; i<equip.weapons.length; i++){
                if(equip.weapons[i] == null){
                    equip.weapons[i] = (Weapon) item;
                    break;
                }else{
                    //System.out.println("no more weapon slots");
                    throw new Exception("no more weapon slots");
                }
            }
        }

        if(item instanceof Armor){
            for(int i = 0; i<equip.armor.length; i++){
                if(equip.armor[i] == null){
                    equip.armor[i] = (Armor) item;
                    break;
                }else{
                    //System.out.println("no more armor slots");
                    throw new Exception("no more armor slots");
                }
            }
        }

        if(item instanceof Potion){
            for(int i = 0; i<equip.potions.length; i++){
                if(equip.potions[i] == null){
                    equip.potions[i] = (Potion) item;
                    break;
                }else{
                    //System.out.println("no more potion slots");
                    throw new Exception("no more potion slots");
                }
            }
        }
    }

    void pickUpItem(Item item) throws Exception{
        for(int i = 0; i < bag.items.length; i++){
            if(bag.items[i] == null){
                bag.items[i] = item;
                break;
            }else{
                throw new Exception("no more space in bag");
            }
        }
    }
}
