package com.company;

public class Vegetable extends Crop{
    String toolRequirement;
//    всеки ден се нуждае от поливане с Лейка
//    когато стане готово за бране се нуждае от мотика за изкопаване
//    расте 2 дни

    public Vegetable(String name) {
        super(name, 2, 0, false, false);
        this.toolRequirement = "Hoe";
    }

}
