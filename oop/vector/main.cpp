#include<iostream>

using namespace std;

class Vector{
public:
  int n;
  int *arr;
  Vector(int n, int *arr){
    this->n = n;
    this->arr = new int[n];
    for (int i = 0; i < n; ++i){
        this->arr[i] = arr[i];
    }
  }
  int getN() const {
      return n;
    }
  int operator[] (int index) {
      return this->arr[index];
  }
  ~Vector(){
    delete(&arr);
  }
private:

};

class Matrix{
public:
  int M; //rows
  int N; // colomns

  Vector** array = new Vector*[N];
  static Matrix from_array(int N, int M, int arr){
    //this->N = N;
    //this->arr = arr;
    //this->M = M;
    //return *this;
  }
  static Matrix from_matrix(Matrix other){

  }
  Matrix operator+(const int value){
    for(int i = 0; i<=N; i++){
      this->array[i] += value;
    }
    return *this;
  }
  Matrix operator+(const Matrix matrix){
    for(int i = 0; i<=N; i++){
      //this->array[i] += matrix.array[i];
    }
    return *this;
  }
private:
  Matrix(){}

};

int main(){

  return 0;
}
