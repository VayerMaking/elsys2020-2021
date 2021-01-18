#include"mine_company.h"
#include<iostream>
#include<string>

using namespace std;

MineCompany::MineCompany(){}
MineCompany::MineCompany(string name, int current_material, list<Worker> workers, vector<Mine> mines) : name(name), current_material(current_material), workers(workers), mines(mines){}

void setlist(list<Mine> mines){
  if(mines.empty()){
    throw "List empty";
  }
}
