package com.company;

public class Cactus extends Crop{
    String toolRequirement;
//    когато стане готово за бране се нуждае от Ръкавици за събиране
//    расте 3 дни
//    времето му за растеж се намалява с 1 ден ако съседните му посеви(този преди и този след него) НЕ са дървета

    public Cactus(String name) {
        super(name, 3, 0, false, false);
        this.toolRequirement = "Gloves";
    }
}
