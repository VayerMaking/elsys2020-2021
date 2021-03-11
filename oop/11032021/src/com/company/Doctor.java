package com.company;

import java.util.ArrayList;

public class Doctor {
    String names;
    ArrayList <Disease> known_diseases;

    public Doctor(String names, ArrayList<Disease> known_diseases) {
        this.names = names;
        this.known_diseases = known_diseases;
    }

    public Disease diagnose(Patient client, ArrayList<Symptom> symptoms){
        return new Disease("covid 19 pro max", symptoms);
    }

}
