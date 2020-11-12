#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

typedef struct{
  char data;
  unsigned char nextElementAdress;
} block;



int main(int argc, const char *argv[]){
  block block;
  int current = 0;
  int fd = open(argv[1], O_RDONLY);
  char buff[BUFFER_SIZE];
  block.data = lseek(fd, current, SEEK_CUR);;
  block.nextElementAdress = lseek(fd, current+1, SEEK_SET);

  read(fd, buff, BUFFER_SIZE);

}
