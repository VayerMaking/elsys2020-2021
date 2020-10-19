#include<iostream>
#include<sstream>

using namespace std;

int main(){
  string data = "3.1415 end";

  istringstream istream(data);

  double pi;
  istream >> pi;
  if(istream.good()){
    cout << "pi:" << pi << endl;
  }else{
    cerr << "something went wrong" << endl;
  }
}
