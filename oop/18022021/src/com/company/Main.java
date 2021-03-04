package com.company;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        double sum = Integer.parseInt(args[0]);
        List<Integer> numbers = new ArrayList();
        List<String> operations = new ArrayList();
        for(int i=0; i < args.length; i++){
            if(i % 2 == 0){
                numbers.add(Double.parseDouble(args[i]));
            }else{
                operations.add(args[i]);
            }
        }

        for(int i = 0; i < operations.size(); i++){
            double sum = 0;
            if(operations.get(i).equals("*")){
                double sum = numbers.get(i) * numbers.get(i + 1);
                changeLists(numbers, operations, i ,sum);
                i -= 1;
            }else if(operations.get(i).equals("/")){
                double sum = numbers.get(i) / numbers.get(i + 1);
                changeLists(numbers, operations, i ,sum);
                i -= 1;
            }

        }

        for(int i = 0; i < operations.size(); i++){
            double sum = 0;
            if(operations.get(i).equals("+")){
                double sum = numbers.get(i) + numbers.get(i + 1);
                changeLists(numbers, operations, i ,sum);
                i -= 1;
            }else if(operations.get(i).equals("-")){
                double sum = numbers.get(i) - numbers.get(i + 1);
                changeLists(numbers, operations, i ,sum);
                i -= 1;
            }

        }

    }
    public static void changeLists(List<Double> numbers, List<String> operations, int i, double sum){
        operations.remove(i);
        numbers.add(i, sum);
        numbers.remove(i + 1);
    }
}
