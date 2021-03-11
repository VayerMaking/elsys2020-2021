package com.company;

import java.util.ArrayList;

public class Disease {
    String name;
    ArrayList <Symptom> symptoms;

    public Disease(String name, ArrayList<Symptom> symptoms) {
        this.name = name;
        this.symptoms = symptoms;
    }
}
