#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 50

int main(int argc, char **argv)
{
  int   file;
  char  buffer[BUFFER_SIZE + 1] = {0};
  int   read_size;

  if (argc < 2)
    {
      perror("Error: usage: ./tail filename\n");
      return (-1);
    }
  file = open(argv[1], O_RDONLY);
  if (file == -1)
    {
      perror("Error: %s: file not found\n");
      return (-1);
    }
  while ((read_size = read(file, buffer, BUFFER_SIZE)) > 0)
    write(1, &buffer, read_size);

  //while((read_size = read(file, buffer, BUFFER_SIZE)) > 0){
  //  buffer[];

  //}
  close(file);
  return (0);
}
