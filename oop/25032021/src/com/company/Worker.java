package com.company;

public class Worker {
    protected String firstName;
    protected String lastName;
    protected int salary;

    public Worker(String firstName, String lastName, int salary) throws Exception {
        this.firstName = firstName;
        this.lastName = lastName;
        this.salary = salary;
        if(salary <= 0){
            throw new Exception("Salary cant be negative!");
        }
        if(firstName.length() == 0){
            throw new Exception("No first name!");
        }
        if(lastName.length() == 0){
            throw new Exception("No last name!");
        }
    }
    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public int getSalary() {
        return salary;
    }
}
