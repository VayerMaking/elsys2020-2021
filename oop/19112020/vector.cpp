#include<iostream>

using namespace std;

class Vector{
public:
    int size = 0;
    int *arr = new int [size];
    Vector(){}

    void add(int value){
      int *resized = new int[size + 1];

      for(int i = 0; i < size; i++){
        resized[i] = arr[i];
      }

      size++;
      arr = resized;
      delete[] resized;
      arr[size-1] = value;
    }

    void print(){
      for(int i = 0; i < size; ++i){
        printf("%d\n", arr[i]);
      }
    }

    ~Vector(){
      delete[] arr;
      cout << "deleted" <<endl;
    }
};

int main(){
  Vector vector;
  vector.add(1);
  vector.add(1);
  vector.add(1);
  vector.print();
  return 0;
}
