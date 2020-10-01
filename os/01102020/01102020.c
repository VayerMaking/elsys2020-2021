#include<stdio.h>
size_t strlen( const char * );
size_t strlen(const char * input){
  int size;
  for(int i = 0;i<sizeof(input);i++){
    size = i;
  }
  return size;
}

int main(){
  printf("%d\n", strlen("asdf"));
  return 0;
}
