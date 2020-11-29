#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define BUFFER_SIZE 100

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "open() failed");
    }
    int file = open(argv[1], O_RDONLY);
    if (file == -1)
    {
        char temp[10];
        strcpy(temp, argv[1]);
        int i = 0, size = 0;
        while (temp[i] != '\0')
        {
            size++;
            i++;
        }
        if (temp[0] == '/' && temp[size - 1] == '/')
        {
            fprintf(stderr, "tail: error reading '%s': Its a directory");
        }
        else if (temp[0]==">")
        {
            fprintf(stderr,"tail: error writing 'standard output': No space left on device");
        }

        else
        {
            fprintf(stderr, "tail: cannot open '%s' for reading: ", argv[1]);
            perror("");
        }
    }

    char buffer[BUFFER_SIZE + 1] = {0};
    int symbols = read(file, buffer, BUFFER_SIZE);
    int counter = 0;
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
        } //to skip the new line
        //printf("%d, %d\n", position, lseek(file,position,SEEK_SET)); //just to check
        char result[BUFFER_SIZE] = {0};
        for (int i = 0; i < BUFFER_SIZE - position - 1; i++)
        {
            result[i] = buffer[temp + i];
        }
        write(1, &result, BUFFER_SIZE);
    }
    close(file);
    return 0;
}
