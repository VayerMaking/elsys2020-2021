//opashka
#include<iostream>
using namespace std;

class Queue_h{
  Node_h* first;
public:
  Queue_h(){
    first = NULL;
  }
};
class Node_h{
  double var;
  Node_h* next;
public:
  Node_h(double x, Node_h* y){
    var = x;
    next = y;
  }
};
int main(){

  return 0;
}
