package com.company;

public class Product {
    int id;
    String name;
    float price;
    Measure measure;
    float quantity;

    public Product(int id, float quantity) {
        this.id = id;
        this.quantity = quantity;
    }
}
