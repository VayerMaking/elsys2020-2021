package com.company;

import java.util.List;
import java.util.Random;

public class RegisterEmployee extends Worker{

    public RegisterEmployee(String firstName, String lastName, int salary) throws Exception {
        super(firstName, lastName, salary);
    }

    protected int getRandomNumberUsingNextInt(int min, int max){
        Random random = new Random();
        return random.nextInt(max - min) + min;
    }

    public void register(List<Card> cards, List<Client> clients, Client client){
        int randomNumber = getRandomNumberUsingNextInt(0, cards.size());
        Card card = cards.get(randomNumber);
        cards.remove(randomNumber);
        client.setCard(card);
        clients.add(client);
    }
}
