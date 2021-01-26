//--------------------------------------------
// NAME: Martin Vayer
// CLASS: XI b
// NUMBER: 19
// PROBLEM: #1
//---------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1

int main(int argc, char **argv){
  int file;
  char buffer[BUFFER_SIZE];
  int read_file;

  if(argc < 2){
    perror("you should write a file as the second parameter");
  }

  file = open(argv[1], O_RDONLY);

  if(file == -1){
    perror("no file found");
  }

  while((read_file = read(file, buffer, BUFFER_SIZE)) > 0){
    //doblirane
    /*int i = 1;
    while(i < sizeof(buffer)){
      fprintf(stdout, buffer[i]);
      i++;
    }*/
    write(1, buffer, 1);
    //write(1, "\n", 1);
    write(1, buffer, 1);
    //write(1, "\n", 1);
  }

  close(file);
  return 0;
}
