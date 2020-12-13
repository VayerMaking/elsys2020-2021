#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int KWH 0.129
const int M3 1.461
const int MWH 85.07
const int MIN1 0.132

int main(){
  ifstream in = ifstream("./data.txt");
  string read_lines;
  cout << "data.txt" <<  endl;
  string temp;
  int j = 0;

  string word;
  string array[5][5];
  while (getline(in, read_lines)){
      cout << read_lines <<  endl;
      temp = read_lines;
      cout << "temp: " << temp << endl;
      istringstream ss(temp);
      for(int i = 0; i <= 3, ss >> word; i++){
        //cout << i << endl;
        array[i][j] = word;
        cout << "i: " << i << " j: " << j << " word: " << word << endl;
      }
      j++;
  }
  return 0;
}
