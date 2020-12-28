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

  token = strtok(line, " ");
  while(token != NULL){
    tokens[position] = token;
    position++;

    if(position >= bufsize){
      bufsize += 64;
      tokens = realloc(tokens, bufsize * sizeof(char*));
    }

    token = strtok(NULL, " ");
  }
  tokens[position] = NULL;
  return tokens;
}

int execute(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    char** new_args;
    for(int i = 1; i < sizeof(*args); i++){
      new_args[i] = args[i];
      printf("%s\n", new_args[i]);
      printf("asdf");
    }
    if (execvp(args[0], new_args) == -1) {
      perror("lsh");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    perror("lsh");
  } else {
    // Parent process
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}
int main(){
  char *buffer;
  size_t bufsize = 32;
  size_t characters;

  while(1){
  buffer = (char *)malloc(bufsize * sizeof(char));
  if( buffer == NULL)
  {
      perror("Unable to allocate buffer");
      exit(1);
  }

  characters = getline(&buffer,&bufsize,stdin);
  printf("%ld\n", characters);

  char** parsed_command = parse(buffer);

  execute(parsed_command);
}


  return 0;
}
