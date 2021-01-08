#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

int main(){
  ifstream in = ifstream("./data.txt");
  string read_lines;
  //cout << "data.txt" <<  endl;
  string temp;
  string word;
  int array[10];
  while (getline(in, read_lines)){
      cout << read_lines <<  endl;
      temp = read_lines;
      //cout << "temp: " << temp << endl;
      istringstream ss(temp);
      for(int i = 0; i <= 1, ss >> word; i++){
        //cout << i << endl;
        array[i] = stoi(word);
        //cout << "i: " << i  << " word: " << word << endl;
      }
      cout << "x1 " <<array[0] << endl;
      cout << "y1 " <<array[1] << endl;
      cout << "x2 " <<array[2] << endl;
      cout << "y2 " <<array[3] << endl;
      cout << "x3 " <<array[4] << endl;
      cout << "y3 " <<array[5] << endl;
      cout << "x4 " <<array[6] << endl;
      cout << "y4 " <<array[7] << endl;
      cout << "dimeter " <<array[8] << endl;
      cout << "start x " <<array[9] << endl;
      cout << "start y " <<array[10] << endl;
  }
  const int min_vector = (array[2] - array[0])/10;
  const int max_vector = (array[2] - array[0])*3/10;
  cout << "min_vector " << min_vector << endl;
  cout << "max_vector " << max_vector << endl;

  return 0;
}
