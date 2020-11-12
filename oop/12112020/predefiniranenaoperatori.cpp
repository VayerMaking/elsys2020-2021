#include<iostream>
//#include<string>
#include<list>
#include<fstream>
using namespace std;

class List{
public:
  list <int> my_list;
  List(){}

  List operator+(const int value){
    list <int> new_list;
    new_list = my_list;
    new_list.push_back(value);
    return *this;
  }

  List operator-(int){
    list <int> new_list;
    new_list = my_list;
    new_list.pop_front();
    return *this;
  }

  List operator+=(const int value){
    my_list.push_back(value);
    return *this;
  }

  List operator--(){
    my_list.pop_front();
    return *this;
  }

  List operator<<(const int value){
    // chetene of istream i dobavqne
    return *this;
  }

  List operator>>(int){
    // printwane s ostream
    return *this;
  }

  List operator*(int){
    my_list.begin();
    return *this;
  }

  List operator[](const int value){
    list <int> new_list;
    if (new_list.size() > value){
      list <int> ::iterator it = new_list.begin();
      advance(it, value);
    }
    return *this;
  }

};

int main(){

  return 0;
}
