package com.elsys.fitness.util;

import java.util.UUID;
import java.util.concurrent.ThreadLocalRandom;

public class RandomGenerator {
    public static int generateRandomInt(int max) {
        return ThreadLocalRandom.current().nextInt(max);
    }

    public static String generateRandomString() {
        return UUID.randomUUID().toString();
    }

    public static double generateRandomDouble() {
        return ThreadLocalRandom.current().nextDouble();
    }
}
