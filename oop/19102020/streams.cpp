#include<iostream>
#include<fstream>
using namespace std;

int main(){
  string name;
  cout << "enter:" << endl;
  getline(cin, name);

  int age;
  cout << "enter2:" << endl;
  cin >> age;

  ofstream ostream;
  ostream.open("test.txt");

  ostream << name << endl;
  ostream << age << endl;

  ostream.close();

}
