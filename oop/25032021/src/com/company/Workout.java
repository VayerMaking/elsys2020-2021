package com.company;

public class Workout {
    protected String name;
    protected String type;

    public Workout(String name, String type) throws Exception {
        this.name = name;
        this.type = type;
        if(!type.equals("Fitness workout") && !type.equals("Group workout")){
            throw new Exception("Wrong type!");
        }
    }
    public String getName() {
        return name;
    }

    public String getType() {
        return type;
    }
}
