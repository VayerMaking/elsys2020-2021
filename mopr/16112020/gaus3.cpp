#include<iostream>
using namespace std;

#define M 4

void gaus(double A[][M], int n){
  double X[M] = {}

  for(int i=0; i<n-1; ++i){
    for(int j = i+1; j<n;++j){
      double diagonal = -(A[j][i]/A[i][j]);
      for(int k = i;k<n+1; ++k){
        A[j][k] += diagonal*A[i][k];
      }
    }
  }
  for(int i = n-1; i>=0; --i){
    X[i]= A[i][n] / A[i][i];
    for(int j = n-1; i<j; --j){
      X[i] -= (X[j] * A[i][j] / A[i][i]);
    }
  }

}
void print(double X, int n){
  for(int i=0; i<n; ++i){
    cout << X[i]<<" ";
  }
}
int main(){

  return 0;
}
