#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 50

int main(int argc, char *argv[]){
    FILE *fd;
    char *filename = argv[1];
    fd = open(filename, "r");
    char  buffer[BUFFER_SIZE + 1] = {0};
    int   read_size;
    int count = 0;
    lseek(fd, 0, SEEK_END);

    if (argc < 2){
        perror("Error: usage: ./tail filename\n");
        return (-1);
    }
    file = open(argv[1], O_RDONLY);
    if (file == -1){
        perror("Error: %s: file not found\n");
        return (-1);
    }
    /*
    while ((read_size = read(fd, buffer, BUFFER_SIZE)) > 0){
      while(count<10){
        lseek(fd, -1, SEEK_END);
        count++;
      }
      while(count > 0){
        lseek(fd, 1, SEEK_CUR)
        read(fd);
        count--;
      }
    }*/
    lseek(in, 0, SEEK_END);
    pos = ftell(in);
    while (pos){
        // Move 'pos' away from end of file.
        if (!lseek(in, --pos, SEEK_SET)){
            if (fgetc(in) == '\n')
                if (count++ == n)
                    break;
        }
    while (fgets(str, sizeof(str), in))
        printf("%s", str);
    close(fd);
    return 0;
}
