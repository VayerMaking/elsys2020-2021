package com.company;

public class Main {

    public static void main(String[] args) {
        Archer a1 = new Archer();
        Mage m1 = new Mage(50, 50);
        Potion p1 = new Potion(10, 0, "mana potion");
        Potion p2 = new Potion(0, 20, "health potion");
        Scroll s1 = new Scroll(10,"sum scroll");
        Note n1 = new Note("note 1", "asdfffffffffff");
        Coffee c1 = new Coffee(3,"nescafe 3in1");

        a1.pick(p2);
        m1.pick(p1);
        a1.pick(s1);
        m1.pick(n1);
        a1.pick(n1);
        a1.pick(c1);

        System.out.println("a1 hotbar" + a1.hotbar);
        System.out.println("a1 inventory" + a1.inventory);
        System.out.println("m1 hotbar" + m1.hotbar);
        System.out.println("m1 inventory" + a1.inventory);

        System.out.println("archer before: " + a1);
        System.out.println("mage before: " + m1);
        a1.useAt(0, a1);
        System.out.println("archer after: " + a1);
        System.out.println("mage after: " + m1);

        System.out.println("intelligence before: " + a1.intelligence);
        System.out.println("intelligence before: " + m1.intelligence);
        a1.useAt(2, m1);
        System.out.println("intelligence after: " + a1.intelligence);
        System.out.println("intelligence after: " + m1.intelligence);


    }
}
