#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define BUFFER_SIZE 100
void tail(char *filename){
    int file = open(filename, O_RDONLY);
    char buffer[BUFFER_SIZE + 1] = {0};
    int symbols = read(file, buffer, BUFFER_SIZE);
    int counter = 0;
    if (symbols > 0){
        int position = symbols;
        while (position > 0){
            if (buffer[position] == '\n'){
                counter++;
            }
            if (counter == 10){
                break;
            }
            position--;
        }

        int temp = 0;
        if (position != 0){
            temp = position + 1;
        }
        //printf("%d, %d, %d\n", position, lseek(file,position,SEEK_SET),symbols); //just to check
        char result[BUFFER_SIZE] = {0};
        for (int i = 0; i < BUFFER_SIZE - position - 1; i++){
            result[i] = buffer[temp + i];
        }
        write(1, &result, BUFFER_SIZE);
    }
    write(1,"\n",1);
    close(file);
}
void pretty_print(char *filename){
    write(1, "==> ", 5);
    write(1, filename, strlen(filename));
    write(1, " <==\n", 6);
}
int main(int argc, char *argv[]){
    if (argc < 2){
        char err[100];
        strcat(err, "error opening");
        strcat(err, argv[1]);
        printf("%s\n", err);
        perror(err);
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
        //pretty_print(argv[1]);
        tail(argv[1]);
    }

    return 0;
}
