#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024

char **parse(char *line)
{
  int bufsize = 64;
  int position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  token = strtok(line, " \n");
  while(token != NULL){
    tokens[position] = token;
    position++;



    if(position >= bufsize){
      bufsize += 64;
      tokens = realloc(tokens, bufsize * sizeof(char*));
    }

    token = strtok(NULL, " \n");
  }
  tokens[position] = NULL;
  //printf("%s\n", tokens[0]);
  //printf("%s\n", tokens[1]);
  return tokens;
}


void execArgs(char** parsed){
    // Forking a child
    pid_t pid = fork();

    if(pid == -1){
        printf("\nFailed forking child..");
        return;
    }else if (pid == 0){
        if (execvp(parsed[0], parsed) < 0) {
            //printf("\nCould not execute command..");
            perror(parsed[0]);
        }
        exit(0);
    }else{
        // waiting for child to terminate
        wait(NULL);
        return;
    }
}


int main(){
  char *buffer;
  size_t bufsize = 32;
  size_t characters;

  while(1){
  buffer = (char *)malloc(bufsize * sizeof(char));
  if( buffer == NULL)
  {
      perror("fork");
      exit(1);
  }


  if(write(1, "$ ", 3) < 0){
    perror("write");
  }
  
  characters = getline(&buffer,&bufsize,stdin);
  if(characters == EOF){
    break;
  }
  printf("%ld\n", characters);

  char** parsed_command = parse(buffer);

  execArgs(parsed_command);
  }


  return 0;
}
