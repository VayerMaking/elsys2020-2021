package com.company;

import java.util.ArrayList;
import java.time.LocalDateTime;

public class Visit {
    LocalDateTime date;
    ArrayList<Symptom> symptoms;
    Disease disease;

    public Visit(LocalDateTime date, ArrayList<Symptom> symptoms, Disease disease) {
        this.date = date;
        this.symptoms = symptoms;
        this.disease = disease;
    }
}
