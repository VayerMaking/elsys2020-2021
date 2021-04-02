package com.company;

public class Client {
    private String firstName;
    private String lastName;
    private Card card;

    public Client(String firstName, String lastName) throws Exception {
        this.firstName = firstName;
        this.lastName = lastName;
        if(firstName.length() == 0){
            throw new Exception("No first name");
        }
        if(lastName.length() == 0){
            throw new Exception("No last name");
        }
    }

    public void train(){
        card.setVisits(card.getVisits()-1);
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public Card getCard() {
        return card;
    }

    public void setCard(Card card) {
        this.card = card;
    }
}
