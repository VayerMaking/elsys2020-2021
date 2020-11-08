#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define BUFFER_SIZE 1000

int main(int argc, const char *argv[])
{
    int file = open(argv[1], O_RDONLY);
    char buff[BUFFER_SIZE];
    int count = 0;
    int read_size = BUFFER_SIZE;
    while((read_size = read(file, buff, BUFFER_SIZE)) > 0){
        int i = 0;
        while(i<read_size){
            if(buff[i] == '\n'){
                count++;
            }
            if(count == 10){
                i += 1;
                break;
            }
            i++;
        }
        write(1, &buff, i);
    }
    close(file);
    return 0;
}
