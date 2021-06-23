package com.company;

public class Fruit extends Crop{
    String toolRequirement;
//    всеки ден се нуждае от поливане с Лейка
//    когато стане готово за бране се нуждае от Стълба за качване
//    расте 4 дни

    public Fruit(String name) {
        super(name, 4, 0, false, false);
        this.toolRequirement = "Ladder";
    }
}
