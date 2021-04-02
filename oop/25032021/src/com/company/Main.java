package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Main {
        public static void main(String[] args) throws Exception {
            Card card1 = new Card("34522");
            Card card2 = new Card("23417");
            Card card3 = new Card("10247");
            Client client1 = new Client("Gosho", "Petrov");
            Client client2 = new Client("Misho", "Sarbev");
            Client client3 = new Client("Katia", "Petrova");
            RegisterEmployee registerEmployee = new RegisterEmployee("Maria", "Ivanova", 450);
            FitnessTrainer fitnessTrainer1 = new FitnessTrainer("Marin", "Georgiev", 600);
            FitnessTrainer fitnessTrainer2 = new FitnessTrainer("Ovchar", "Marinov", 700);
            GroupTrainer groupTrainer1 = new GroupTrainer("Stefan", "Sotirov", 900);
            GroupTrainer groupTrainer2 = new GroupTrainer("Slavena", "Ivanova", 800);
            List<Card> cards = new ArrayList<>();
            cards.add(card1);
            cards.add(card2);
            cards.add(card3);

            List<Client> clients = new ArrayList<>();

            List<FitnessTrainer> fitnessTrainers = new ArrayList<>();
            fitnessTrainers.add(fitnessTrainer1);
            fitnessTrainers.add(fitnessTrainer2);

            List<GroupTrainer> groupTrainers = new ArrayList<>();
            groupTrainers.add(groupTrainer1);
            groupTrainers.add(groupTrainer2);

            registerEmployee.register(cards, clients, client1);
            registerEmployee.register(cards, clients, client2);
            registerEmployee.register(cards, clients, client3);

            train(fitnessTrainers, groupTrainers, clients, new Workout("Train", "Fitness workout"));
            train(fitnessTrainers, groupTrainers, clients, new Workout("Train2", "Group workout"));
        }

        protected static int getRandomNumberUsingNextInt(int min, int max) {
            Random random = new Random();
            return random.nextInt(max - min) + min;
        }
        public static void train(List<FitnessTrainer> fitnessTrainers, List<GroupTrainer> groupTrainers, List<Client> clients, Workout work) throws Exception {
            int rand;
            if(work.getType() == "Fitness workout"){
                rand = getRandomNumberUsingNextInt(0, fitnessTrainers.size());
                fitnessTrainers.get(rand).train(work, clients.get(0));
            }
            if(work.getType() == "Group workout"){
                rand = getRandomNumberUsingNextInt(0, groupTrainers.size());
                groupTrainers.get(rand).train(work, clients);
            }
        }
}
