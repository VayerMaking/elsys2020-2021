package com.company;

import java.util.ArrayList;
import java.time.format.DateTimeFormatter;
import java.time.LocalDateTime;
import com.company.Symptom;

public class Main {

    public static void main(String[] args) {
        ArrayList <Symptom> s1;
        s1.set(0, Symptom.cough);
        s1.set(1, Symptom.troubled_breathing);
        Disease disease1 = new Disease("covid19 pro max duo", s1);
        ArrayList <Disease> known_diseases;
        known_diseases.set(0, disease1);
        Doctor doctor1 = new Doctor("Ivan Petrov", known_diseases);
        Patient patient1 = new Patient("0808080808080", "Petar Beron");
        ArrayList <Visit> visits;
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        visits.set(0, new Visit(now, s1, disease1));
        Record record1 = new Record(patient1, visits);
        ArrayList <Record> medical_records = null;
        Office office1 = new Office(doctor1, medical_records);

    }
}
