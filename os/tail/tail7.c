//------------------------------------------------------------------------
// NAME: Martin Vayer
// CLASS: XIb
// NUMBER: 19
// PROBLEM: #1
// FILE NAME: tail7.c (unix file name)
// FILE PURPOSE:
// unix tail command
//------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>

#define BUFFER_SIZE 100

//------------------------------------------------------------------------
// FUNCTION: tail (име на функцията)
// unix tail command
// PARAMETERS:
// char *filename
// the name of the file... duhh
//------------------------------------------------------------------------
void tail(char *filename){
    int file = open(filename, O_RDONLY);

    if (file < 0){
      char error_message[] = "tail: cannot open for reading '";
      strcat(error_message, filename);
      strcat(error_message, "' for reading");
      perror(error_message);
      return;
    }

    char buffer[BUFFER_SIZE + 1] = {0};
    int read_but_in_past_tense = read(file, buffer, BUFFER_SIZE);
    int counter = 0;

    if (read_but_in_past_tense > 0){
        int pos = read_but_in_past_tense;
        while (pos > 0){
            if (buffer[pos] == '\n'){
                counter++;
            }
            if (counter == 10){
                break;
            }
            pos--;
        }

        int tmp = 0;
        if (pos != 0){
            tmp = pos + 1;
        }
        char result[BUFFER_SIZE] = {0};
        for (int i = 0; i < BUFFER_SIZE - pos - 1; i++){
            result[i] = buffer[tmp + i];
        }
        if(write(1, &result, BUFFER_SIZE) < 0){
          perror("tail: error writing 'standard output'");
          return;
        }
    }else{
      char error_message[] = "tail: error reading '";
      strcat(error_message, filename);
      strcat(error_message, "'");
      errno = 21;
      perror(error_message);
    }
    if (close(file) < 0){
      char error_message[] = "tail: error reading '";
      strcat(error_message, filename);
      strcat(error_message, "'");
      errno = 5;
      perror(error_message);
    }
    write(1,"\n",1);
}
//------------------------------------------------------------------------
// FUNCTION: pretty_print (име на функцията)
// print the ==> filename <== parts in the tail command
// PARAMETERS:
// char *filename
// the name of the file... duhh
//------------------------------------------------------------------------
void pretty_print(char *filename){
    write(1, "==> ", 5);
    write(1, filename, strlen(filename));
    write(1, " <==\n", 6);
}
int main(int argc, char *argv[]){
    if (argc < 2){
      perror("usage ./tail filename ");
    }else if (argc > 2){
      int i = 1;
      while (i<argc){
        if(i!=1){
          write(1,"\n",1);
        }
        pretty_print(argv[i]);
        tail(argv[i]);
        i++;
      }
    }else{
      tail(argv[1]);
    }
    return 0;
}
