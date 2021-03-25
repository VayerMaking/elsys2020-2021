//--------------------------------------------
// NAME: Martin Vayer
// CLASS: XI b
// NUMBER: 19
// PROBLEM: #1
//---------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>

pthread_mutex_t lock;
int minerals = 2;
int mining_blocks = [];

void *scv(void *args){

  int scv_count;
  scv_count = *((int*)args);
  pthread_mutex_lock(&lock);
  printf("SCV %d is mining from mineral block 1\n", scv_count);
  //“SCV N is mining from mineral block M
  pthread_mutex_unlock(&lock);
  pthread_exit(NULL);
}

int main(int argc, char **argv){
  int number_of_threads = 0;
  //printf("argc: %d\n",argc);
  if(argc < 2){
    number_of_threads = 5;
  }else{
    number_of_threads = atoi(argv[1]);
  }
  pthread_t * SCV_t = malloc(number_of_threads * sizeof(pthread_t));
  //printf("argv: %s\n",argv[1]);
  int rc;
  int soldier_count = 0;


  for(int i = 0; i < number_of_threads; i++){
    int *process_id = malloc(sizeof(int));
    *process_id = i + 1;
    //printf("process_id: %d\n", *process_id);
    rc = pthread_create(&SCV_t[i], NULL, &scv, (void *)process_id);

    if(rc){
      printf("%d : %s\n", rc, strerror(rc));
      return 1;
    }
  }

  for(int i = 0; i < number_of_threads; i++){
    pthread_join(SCV_t[i], NULL);
  }

  soldier_count++;
  return 0;
}
