#include<iostream>
#include<list>
using namespace std;

class Field{
public:
  string type = "";
  int quantity = 0;
  int workers_needed = 0;

  Field(){}

  Field(string type, int quantity, int workers_needed){
    this->type = type;
    this->quantity = quantity;
    this->workers_needed = workers_needed;
  }
};

class Farm{
public:
  list<Field> fields;
  int workers = 0;
  string farm_name = "";
  void cout_farm(){
    for(list<Field>::iterator it = fields.begin(); it != fields.end(); it++) {
       Field field = *it;
       cout << field.type << field.quantity << field.workers_needed;
     }
  }
  void add_field(Field field) {
    fields.push_back(field);
  }
  int get_production(string type){
    int result;
    for(list<Field>::iterator it = fields.begin(); it != fields.end(); it++) {
       if((*it).type == type){
         result += (*it).quantity;
       }
     }
    return result;
  }
};

int main(){

  Farm farm;
  string type;

  cout << "enter type tosearch" << endl;
  cin >> type;

  while(!cin.eof()) {
    Field new_field;
    cin >> new_field.type >> new_field.quantity >> new_field.workers_needed;
    if(!cin.eof() && cin.good()) {
      farm.add_field(new_field);
    }
  }
  farm.cout_farm();
  cout << farm.get_production(type);
  
  return 0;
}
