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
  if(argc >= 2){
    while((read_file = read(file, buffer, BUFFER_SIZE)) > 0){
      write(1, buffer, 1);
      write(1, buffer, 1);
    }
  }/*else if(argc > 2){
    fprintf(stdout, sizeof(argv));
    //buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) * sizeof(argv));
    pid_t pid = fork();

    if(pid == -1){
      perror("fork");
      return;
    }else if(pid == 0){
      //exec child
    }else{
      wait(NULL);
      return;
    }
  }
  */
  close(file);
  return 0;
}
