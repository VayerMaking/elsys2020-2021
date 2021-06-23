package com.company;

import java.util.Map;

public class Dish {
    String name;
    Map<Product, Integer> products;
    int timeToCook;

    Float getSalePrice(){
        Float sum = map.values()
                .stream()
                .mapToInt(Float::valueOf)
                .sum();
        return sum * 2;
    }
}
