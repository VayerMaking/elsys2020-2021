#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 50

int main(){
  int   file;
  char  buffer[BUFFER_SIZE + 1] = {0};
  int   read_size;

  file = open("a.txt", O_RDONLY);
  if (file == -1){
      perror("error");

  }
  while ((read_size = read(file, buffer, BUFFER_SIZE)) > 0){
    write(1, &buffer, read_size);
  }
  //while((read_size = read(file, buffer, BUFFER_SIZE)) > 0){
  //  buffer[];

  //}
  close(file);
  return (0);
}
