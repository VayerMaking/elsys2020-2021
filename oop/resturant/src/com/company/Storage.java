package com.company;

import java.util.Map;

public class Storage {
    Map<Product, Integer> products;

    void addProduct(Product product, int amount){
        products.put(product, amount);
        System.out.println(products);
    }

    void getProduct(Product product, int amount){
        int newAmount = products.get(product) - amount;
        products.put(product, newAmount);
        System.out.println(products);
    }
}
