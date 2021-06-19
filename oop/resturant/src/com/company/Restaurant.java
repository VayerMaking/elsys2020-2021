package com.company;

import java.util.ArrayList;

public class Restaurant {
    ArrayList<Dish> dishes;
    ArrayList<Chef> chefs;
    ArrayList<Waiter> waiters;
    Storage storage;
    Float money;
    ArrayList<Order> activeOrders;
    ArrayList<Order> completedOrders;
    ArrayList<Order> failedOrders;

    void addOrder(){}
    void completeOrder(int id){
        completedOrders.add(activeOrders.get(id));
        activeOrders.remove(activeOrders.get(id));
    }

    void addChef(Chef chef){
        chefs.add(chef);
    }

    void addWaiter(Waiter waiter){
        waiters.add(waiter);
    }
}
