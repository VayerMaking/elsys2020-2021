package com.company;

import java.util.LinkedList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
	Ruler myRuler = new Ruler("jin hin", 69);

	System.out.println(myRuler.canTravel());

	List<ICommunist> voters = new LinkedList();
	voters.add(myRuler);
	voters.add(new Citizen("Ivan", 56));
	voters.add(new Citizen("Pesho", 89));

	for(ICommunist voter:voters){
		voter.vote();
	}


    }
}

