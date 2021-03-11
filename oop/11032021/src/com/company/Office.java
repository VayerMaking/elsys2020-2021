package com.company;

import java.util.ArrayList;

public class Office {
    Doctor doctor;
    ArrayList <Record> medical_records;

    public Office(Doctor doctor, ArrayList<Record> medical_records) {
        this.doctor = doctor;
        this.medical_records = medical_records;
    }
}
