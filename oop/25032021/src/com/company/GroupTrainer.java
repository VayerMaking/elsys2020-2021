package com.company;

import java.util.List;

public class GroupTrainer extends Worker{
    public GroupTrainer(String firstName, String lastName, int salary) throws Exception {
        super(firstName, lastName, salary);
    }

    public void train(Workout work, List<Client> clients) throws Exception {
        if(clients.size() < 3) {
            throw new Exception("Not enough people for workout!");
        }
        if(!work.getType().equals("Group workout")){
            throw new Exception("Wrong workout type!");
        }
        for(Client client : clients){client.train();}
    }
}
