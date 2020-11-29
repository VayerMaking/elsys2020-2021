#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>

#define BUFFER_SIZE 100

void read_file(char *filename)
{
    int file = open(filename, O_RDWR);
    //printf("%d\n", errno);
    char buffer[BUFFER_SIZE + 1] = {0};
    //errors(file);

    int symbols = read(file, buffer, BUFFER_SIZE);
    int counter = 0;
    if (symbols == -1){
        char err[100] = "tail: error reading '";
        strcat(err, filename);
        strcat(err, "'");
        perror(err);
        return -1;
    }
    if (symbols > 0)
    {
        int position = symbols;
        while (position > 0)
        {
            if (buffer[position] == '\n')
            {
                counter++;
            }
            if (counter == 10)
            {
                break;
            }
            position--;
        }

        int temp = 0;
        if (position != 0)
        {
            temp = position + 1;
        }
        //printf("%d, %d, %d\n", position, lseek(file,position,SEEK_SET),symbols); //just to check
        char result[BUFFER_SIZE] = {0};
        for (int i = 0; i < BUFFER_SIZE - position - 1; i++)
        {
            result[i] = buffer[temp + i];
        }
        write(1, &result, BUFFER_SIZE);
    }
    write(1, "\n", 1);
    close(file);
}

void write_func(char *filename)
{
    write(1, "==>", 4);
    write(1, filename, strlen(filename));
    write(1, "<==\n", 5);
}

int main(int argc, char *argv[])
{
  int file = open(argv[1], O_RDWR);
  //printf("%d\n", errno);
  char buffer[BUFFER_SIZE + 1] = {0};
  if (read(file, buffer, BUFFER_SIZE) == -1){
      char err[100] = "tail: error reading '";
      strcat(err, argv[1]);
      strcat(err, "'");
      perror(err);
      return -1;
  }
    if (argc < 2)
    {
        fprintf(stderr, "open() failed");
    }

    else if (argc > 2)
    {
        int i = 1;
        while (i < argc)
        {
            if (i != 1)
            {
                write(1, "\n", 1);
            }
            write_func(argv[i]);
            read_file(argv[i]);
            i++;
        }
    }
    else
    {
        read_file(argv[1]);
    }

    return 0;
}
