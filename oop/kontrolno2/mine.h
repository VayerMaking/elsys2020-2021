#ifndef MINE_H
#define MINE_H

#include<iostream>
#include<string>
#include<list>
#include"worker.h"

using namespace std;

class Worker;

class Mine{
public:
    int materials;
    int id;
    list<Worker> workers;

    Mine();
    Mine(int materials, int id, list<Worker> workers);
};

#endif
