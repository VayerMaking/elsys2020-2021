package com.company;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) {
	int cropCount = 4;
	Vegetable o1 = new Vegetable("Cucumber");
	Vegetable o2 = new Vegetable("Rqpa");
	Cactus o3 = new Cactus("Cactus");
	Fruit o4 = new Fruit("Apple");

	ArrayList<String> workerTools = new ArrayList<String>();
	workerTools.add("Gloves");
	workerTools.add("Ladder");

	Worker w1 = new Worker("Stamat", workerTools);
	ArrayList<Crop> crops = new ArrayList<Crop>();
	crops.add(o1);
	crops.add(o2);
	crops.add(o3);
	crops.add(o4);

//	List<Crop> onlyVegetables = crops
//			.stream()
//			.filter(Crop::isAVegetable)
//			.collect(Collectors.toList());
//
//	List<Crop> onlyCactuses = crops
//			.stream()
//			.filter(Crop::isACactus)
//			.collect(Collectors.toList());
//
//	List<Crop> onlyFruit = crops
//			.stream()
//			.filter(Crop::isAFruit)
//			.collect(Collectors.toList());
//    }
//	System.out.println(onlyVegetables[0]);
//    for (Fruit f : onlyFruit)
//			System.out.println(elem);
	for (Crop c : crops)
		if (c instanceof Vegetable){
			// check when it hs beeen watered and if its less than the time for vegetables
			// check and change flags
			if (c.isCollected()){
				// remove
			}else{
				//collect and set flag
				c.setCollected(true);
			}
		}else if (c instanceof Fruit){
			// check when it hs beeen watered and if its less than the time for fruit
			// check and change flags
		}else if (c instanceof Cactus){
			// check when it hs beeen watered and if its less than the time for cactus
			// check and change flags
		}
	}

}
