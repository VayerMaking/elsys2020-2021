package com.company;

import java.util.ArrayList;

public class Order {
    int id;
    int userId;
    Address address;
    Status status;
    ArrayList<Product> products;
    float amount;
    float price;

    public Order(Status status, int userId) {
        this.status = status;
        this.userId = userId;
    }

}
