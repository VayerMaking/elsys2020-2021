#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(){
  int   file;
  char  buffer[BUFFER_SIZE + 1] = {0};
  int   read_size;
  int count;

  file = open("a.txt", O_RDONLY);
  if (file == -1){
      perror("error");

  }
  while ((read_size = read(file, buffer, BUFFER_SIZE)) > 0){
    int i = 0;
    while(i < read_size){
      if(count >= 10){
        break;
      }else{
        if(buffer[i] == '\n'){
          count++;
        }
      }
        i++;
    }

  }
  write(1, buffer, read_size);

  close(file);
  return (0);
}
