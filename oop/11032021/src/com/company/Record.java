package com.company;

import java.util.ArrayList;

public class Record {
    Patient patient;
    ArrayList<Visit> visits;

    public Record(Patient patient, ArrayList<Visit> visits) {
        this.patient = patient;
        this.visits = visits;
    }
}
