#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void execArgs(char** parsed){
  // Forking a child
  pid_t pid = fork();

  if (pid == -1){
      printf("\nFailed forking child..");
      return;
  }else if (pid == 0){
      if(execvp(parsed[0], parsed) < 0) {
          printf("\nCould not execute command..");
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

  buffer = (char *)malloc(bufsize * sizeof(char));
  if( buffer == NULL)
  {
      perror("Unable to allocate buffer");
      exit(1);
  }

  characters = getline(&buffer,&bufsize,stdin);
  printf("%zu characters were read.\n",characters);
  printf("You typed: '%s'\n",buffer);
  buffer[strlen(buffer)-1] = '\0';
  printf("You typed: '%s'\n",buffer);
/*
  printf("You typed: '%d'\n",buffer[characters-5]);
  printf("You typed: '%d'\n",buffer[characters-4]);
  printf("You typed: '%d'\n",buffer[characters-3]);
  printf("You typed: '%d'\n",buffer[characters-2]);
  printf("You typed: '%d'\n",buffer[characters-1]);*/
  char** ptr;
  int n = 0;
  ptr = malloc(n * sizeof(char*));

  for (int i = 0; i < n; ++i) {
    ptr[i] = malloc(n * sizeof(char*));
      //ptr[i] = 0;
  }

  // Print the elements of the array
   printf("The elements of the array are: ");
  for (int i = 0; i < n; ++i) {
      printf("%s, ", ptr[i]);
  }
  char* token = strtok(buffer, " ");

  while (token != NULL) {

    printf("%s\n", token);
    ptr = realloc(ptr, n * sizeof(char*));
    ///ptr[n] = token;
    strcpy(token, ptr[n]);
    token = strtok(NULL, " ");
    n++;
  }
  //execv(agrs[0], args);

return(0);
}
