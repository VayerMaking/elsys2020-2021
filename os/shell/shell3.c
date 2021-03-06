#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024
char **parse_cmdline(const char *cmdline){
  int bufsize = 64;
  char *cmdline_copy = malloc(bufsize * sizeof(char*));;
  strcpy(cmdline_copy, cmdline);
  int position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  token = strtok(cmdline_copy, " \n");
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
  //free(tokens);
  //free(cmdline_copy);
  return tokens;
}

void execArgs(char** parsed){
    // Forking a child
    pid_t pid = fork();

    if(pid == -1){
        printf("\nFailed forking child..");
        perror("fork");
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
        //free(parsed);
        return;
    }
}

int main(){
  char *buffer;
  size_t bufsize = 32;
  size_t characters;

  while(1){
  buffer = (char *)malloc(bufsize * sizeof(char));
  if(buffer == NULL){
      perror("fork");
      exit(1);
  }
  /*if(write(1, "$ ", 3) < 0){
    perror("write");
  }*/
  printf("%s", "$ ");

  characters = getline(&buffer,&bufsize,stdin);
  if(characters == EOF){
    break;
  }
  //printf("%ld\n", characters);

  char** parsed_command = parse_cmdline(buffer);

  execArgs(parsed_command);

  free(parsed_command);
  }

  free(buffer);

  return 0;
}
