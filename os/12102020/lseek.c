//------------------------------------------------------------------------
// NAME: Matin Vayer
// CLASS: XIb
// NUMBER: 19
// PROBLEM: #1
// FILE NAME: lseek.c (unix file name)
// FILE PURPOSE:
// Целта на задачата е да се реализира parser за абстрактна блокова система, който да извежда информацията на стандартния изход. Системата се състои от множество структури (блокове) съдържащи в себе си информация и адрес (отместване от началото на файла) на слеващия блокове. Размерът на цялата система е 128 блока, а края се разпознова по това, че в полето за адрес на последния блок е записано 0. Програмата приема един аргумент - името на файла, на който е записана блоковата система. В началото на файла е записан първият блок.
//------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

typedef struct{
  char data;
  unsigned char nextElementAdress;
} block;

int main(int argc, const char *argv[]){
  block blocks[128];
  char buffer[128];
  int fd = 0;

  fd = open(argv[1], O_RDONLY);

  while(read(fd, blocks, 2) > 0){
    if(blocks->nextElementAdress != 0){
      write(*buffer, &(blocks->data), 1);
      write(1, buffer, 1);
      lseek(fd, blocks->nextElementAdress, SEEK_SET);
    }else if(blocks->nextElementAdress == 0){
      break;
    }
  }
  write(1, "\n", 1);
  close(fd);
}
