package com.company;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class Shop {
    Countries country;
    ArrayList<Countries> shipTo;
    Set<Product> products = new HashSet<>();
    Set<Product> cart = new HashSet<>();
    Set<Order> orders = new HashSet<>();
    User currentUser;
    Set<User> users = new HashSet<>();

    public void registerUser(User user){
        Random rand = new Random();
        int randId = rand.nextInt(100000);
        user.id = randId;
        users.add(user);
    }

    public void addProduct(Product product, float amount){
        Random rand = new Random();
        int randId = rand.nextInt(100000);
        if(product.id > 0){
            product.quantity += amount;
        }else{
            product.id = randId;
            product.quantity = amount;
            products.add(product);
        }

    }

    public void removeProduct(Product product, float quantity){
        try {
            products.remove(product);
        }catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void addProductToCart(int id, float quantity){
        try {
            cart.add(new Product(id, quantity));
        }catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void checkoutCart() throws Exception {
        if(cart.isEmpty()){
            throw new Exception("empty cart");
        }
        for(Product product : products){
            if(product.quantity < cart.get(product.id).amount){
                throw new Exception("no quantity");
            }
        }
        if(currentUser.id == 0){
            Random rand = new Random();
            int randId = rand.nextInt(100000);
            currentUser.id = randId;
        }
        Order order = new Order(Status.Open, currentUser.id);

    }

    public void shipOrder(int id) throws Exception {
        if(orders[id] > 0){
            throw new Exception("no order with this id");
        }
        if(shipTo.contains(orders[id].address.country)) {
            orders[id].status = Status.Shipped;
        }else{
            orders[id].status = Status.Failed;
            throw new Exception("we do not ship to this country");
        }
    }

    public void completeOrder(int id) throws Exception {
        if(orders[id] > 0){
            orders[id].status = Status.Completed;
        }else{
            throw new Exception("no order with this id");
        }
    }

    public void failOrder(int id) throws Exception {
        if(orders[id] > 0){
            orders[id].status = Status.Failed;
        }else{
            throw new Exception("no order with this id");
        }
    }


}
