#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#define N 4

int forwardElim(double eq[N][N+1]);
void backSub(double eq[N][N+1]);
void gaussianElimination(double eq[N][N+1]){
    int singular_flag = forwardElim(eq);
    if (singular_flag != -1){
        printf("edenichna matritza.\n");
        if (eq[singular_flag][N])
            printf("nevalidna matritza.");
        else
            printf(" bezkraini resheniq");

        return;
    }
    backSub(eq);
}
void swap_row(double eq[N][N+1], int i, int j){
    for (int k=0; k<=N; k++){
        double temp = eq[i][k];
        eq[i][k] = eq[j][k];
        eq[j][k] = temp;
    }
}
void print(double eq[N][N+1]){
    for (int i=0; i<N; i++, printf("\n")){
        for (int j=0; j<=N; j++){
            printf("%lf ", eq[i][j]);
        }
    printf("\n");
    }
}
int forwardElim(double eq[N][N+1]){
    for (int k=0; k<N; k++){
        int i_max = k;
        int v_max = eq[i_max][k];
        for (int i = k+1; i < N; i++){
            if (abs(eq[i][k]) > v_max)
                v_max = eq[i][k], i_max = i;
        }
        if (!eq[k][i_max]){
            return k;
        }
        if (i_max != k){
            swap_row(eq, k, i_max);
        }
        for (int i=k+1; i<N; i++){
            double f = eq[i][k]/eq[k][k];

            for (int j=k+1; j<=N; j++){
                eq[i][j] -= eq[k][j]*f;
            }
            eq[i][k] = 0;
        }
    }
    return -1;
}
void backSub(double eq[N][N+1]){
    double x[N];

    for (int i = N-1; i >= 0; i--){
        x[i] = eq[i][N];

        for (int j=i+1; j<N; j++){
            x[i] -= eq[i][j]*x[j];
        }

        x[i] = x[i]/eq[i][i];
    }

    printf("\notg:\n");
    for (int i=0; i<N; i++){
        printf("%lf\n", x[i]);
    }
}

int main(){
  const double kwh = 0.129;
  const double m3 = 1.461;
  const double mwh = 85.07;
  const double min1 = 0.132;

  ifstream in = ifstream("./data.txt");
  string read_lines;
  cout << "data.txt" <<  endl;
  string temp;
  int j = 0;

  string word;
  double array[5][5];
  while (getline(in, read_lines) && j<=4){
      cout << read_lines <<  endl;
      temp = read_lines;
      cout << "temp: " << temp << endl;
      istringstream ss(temp);
      for(int i = 0; i <= 3, ss >> word; i++){
        //cout << i << endl;
        array[i][j] = stod(word);
        cout << "i: " << i << " j: " << j << " word: " << word << endl;
      }
      j++;
  }
  //gaussianElimination(array);
  cout << array[0][0] << " " << array[1][0] << " " << array[2][0] << " " << array[3][0] << endl;
  cout << array[0][1] << " " << array[1][1] << " " << array[2][1] << " " << array[3][1] << endl;
  cout << array[0][2] << " " << array[1][2] << " " << array[2][2] << " " << array[3][2] << endl;
  cout << array[0][3] << " " << array[1][3] << " " << array[2][3] << " " << array[3][3] << endl;

  double total_tok;
  double total_voda;
  double total_toplo;
  double total_minuti;
  double buffer_array[3][1];
  double result_array[3];

  for(int i = 0; i<=3; i++){
    array[0][i] = array[0][i] * kwh;
    cout << "tok: " << array[0][i] << endl;
    total_tok += array[0][i];

    array[1][i] = array[1][i] * m3;
    cout << "voda: " << array[1][i] << endl;
    total_voda += array[1][i];

    array[2][i] = array[2][i] * mwh;
    cout << "toplo: " << array[2][i] << endl;
    total_toplo += array[2][i];

    array[3][i] = array[3][i] * min1;
    cout << "minuti: " << array[3][i] << endl;
    total_minuti += array[3][i];
  }
  cout << "tzeliq tok: "<< total_tok << endl;
  cout << "tzeliq voda: "<< total_voda << endl;
  cout << "tzeliq toplo: "<< total_toplo << endl;
  cout << "tzeliq minuti: "<< total_minuti << endl;

  buffer_array[0][0] = total_tok;
  buffer_array[1][0] = total_voda;
  buffer_array[2][0] = total_toplo;
  buffer_array[3][0] = total_minuti;

  cout << "buffer_array: " << buffer_array[0][0] << " " << buffer_array[1][0] << " " << buffer_array[2][0] << " " << buffer_array[3][0] << " " << endl;
  //multiply(array);
  result_array[0] = array[0][4] - buffer_array[0][0];
  result_array[1] = array[1][4] - buffer_array[1][0];
  result_array[2] = array[2][4] - buffer_array[2][0];
  result_array[3] = array[3][4] - buffer_array[3][0];

  cout << "result_array: " << result_array[0] << " " << result_array[1] << " " << result_array[2] << " " << result_array[3] << " " << endl;

  gaussianElimination(array);
  return 0;
}
