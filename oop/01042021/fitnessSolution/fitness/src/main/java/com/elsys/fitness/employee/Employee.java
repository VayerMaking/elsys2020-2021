package com.elsys.fitness.employee;

import com.elsys.fitness.Fitness;
import com.elsys.fitness.util.RandomGenerator;

public abstract class Employee {
    protected Fitness fitness;
    protected String firstName;
    protected String lastName;
    protected double salary;

    public Employee(String firstName, String lastName, double salary, Fitness fitness) {
        setFirstName(firstName);
        setLastName(lastName);
        setSalary(salary);
        this.fitness = fitness;
    }

    public Employee(String firstName, String lastName, Fitness fitness) {
        this(firstName, lastName, RandomGenerator.generateRandomDouble(), fitness);
    }

    public void setFirstName(String firstName) {
        if (firstName == null || firstName.isBlank()) {
            throw new IllegalArgumentException("First Name is mandatory!");
        }
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        if (lastName.isBlank()) {
            throw new IllegalArgumentException("Last Name is mandatory!");
        }
        this.lastName = lastName;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        if(salary < 0) {
            throw new IllegalArgumentException("Salary must be more tan 0!");
        }

        this.salary = salary;
    }
}
