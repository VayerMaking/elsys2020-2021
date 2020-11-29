#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        FILE *fd;
        char len[400];
        int i;

        char *filename = argv[1];
        int ch;
        int count;

        fd = fopen(filename, "r");
        fseek(fd, 0, SEEK_END);
        while (ftell(fd) > 1 ){
                fseek(fd, -2, SEEK_CUR);
                if(ftell(fd) <= 2)
                        break;
                ch =fgetc(fd);
                count = 0;
                while(ch != '\n'){
                        len[count++] = ch;
                        if(ftell(fd) < 2)
                                break;
                        fseek(fd, -2, SEEK_CUR);
                        ch =fgetc(fd);
                }
                for (i =count -1 ; i >= 0 && count > 0  ; i--)
                        printf("%c", len[i]);
                printf("\n");
        }
        fclose(fd);
}
