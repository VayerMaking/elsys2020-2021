#include<iostream>
#include"mine.h"
#include<list>
#include"worker.h"

using namespace std;

Mine::Mine(){}
Mine::Mine(int materials, int id, list<Worker> workers) : materials(materials), id(id), workers(workers) {}
