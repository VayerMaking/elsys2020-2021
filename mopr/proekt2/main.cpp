#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

int check_power(float shot_power){
    if(shot_power < 5 && shot_power > 2){
      return 1;
    }
    return 0;
}

int check_vector_lenght(int array[], int pos_x, int pos_y, int min_vector, int max_vector){
    int a = abs(array[9] - pos_x);
    int b = abs(array[10] - pos_y);
    int lenght = sqrt(abs(a*a + b*b));

    if(lenght > min_vector && lenght < max_vector){
        return 1;
    }
    return 0;
}

void find_next_point(int pos_x, int pos_y, int array[], float shot_power){
    int next_x = (pos_x - array[9]) * shot_power + array[9];
    int next_y = (pos_y - array[10]) * shot_power + array[10];

    cout << next_x << endl;
    cout << next_y << endl;
}

int main(){
  ifstream in = ifstream("./data.txt");
  if(!in){ return -1;}
  string read_lines;
  string temp;
  string word;
  int pos_x = 0;
  int pos_y = 0;
  int array[10];
  while (getline(in, read_lines)){
      cout << read_lines <<  endl;
      temp = read_lines;
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
  float shot_power = 2.0; // should be between 2 and 5
  cout << "min_vector " << min_vector << endl;
  cout << "max_vector " << max_vector << endl;
  cout << endl;

  while(true){
    cin >> shot_power;
    cin >> pos_x;
    cin >> pos_y;

    cout << endl;

    if(check_vector_lenght(array, pos_x, pos_y, min_vector, max_vector)){
      find_next_point(pos_x, pos_y, array, shot_power);
    }

    cout << endl;
  }
  return 0;
}
