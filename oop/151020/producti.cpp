#include<iostream>
#include<string>
#include<queue>
using namespace std;



class Product{
public:
  string name;
  int quantity;
  Product(string x, int y){
    name = x;
    quantity = y;
  }
};
class Order{
public:
  Product product;
  bool is_done;
  Order(Product x, bool y){
    product = x;
    is_done = y;
  }
};
/*class Factory{
public:
  Product* products[100];
  Factory(Product x[]){
    products = x;
  }
};*/
int main(){
  //Product products[];
  Product sirene("sirene", 5);
  //Factory factory(products[]);
  queue<string> my_queue;
  string a;
  cin>>a;
  my_queue.push(a);
  while (!my_queue.empty()) {
    cout << ' ' << my_queue.front();
    my_queue.pop();
  }

  return 0;
}
