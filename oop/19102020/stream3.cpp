#include<iostream>
#include<sstream>

using namespace std;

int main(){
  string str = "Hello";
  str += "world!";
  str = str + "assdf" + "qwerty";
  cout << str << endl;

  ostringstream ostream;
  ostream << "Hello";
  ostream << "world" << "bye" << "world" << endl;
  string str2 = ostream.str();
  cout << str2;
}
