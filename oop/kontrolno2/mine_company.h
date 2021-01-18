#ifndef MINE_COMPANY_H
#define MINE_COMPANY_H

#include<iostream>
#include<string>
#include<list>
#include<vector>
#include"worker.h"

using namespace std;

class MineCompany{
public:
    string name;
    int current_material;
    list<Worker> workers;
    vector<Mine> mines;

    MineCompany();
    MineCompany(string name, int current_material, list<Worker> workers, vector<Mine> mines);

    void setlist(list<Mine> mines);
};

#endif
