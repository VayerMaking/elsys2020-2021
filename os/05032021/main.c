#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS	2
#define BUFFER_SIZE 64

char  buffer[BUFFER_SIZE + 1] = {0};

void *read_and_write_to_buffer(char buffer){

  while((read(0, buffer, BUFFER_SIZE)) != 0){
    //printf("n: %d:",n);
    read(0, buffer, BUFFER_SIZE);
  }


    return NULL;
}

void *write_to_console(char buffer){
  while((read(0, buffer, BUFFER_SIZE)) != 0){
    //printf("n: %d:",n);
    write(1, buffer, 1);
  }

    return NULL;
}

int main(){
  int rc;
  pthread_t thr1, thr2;

  rc = pthread_create(&thr1, NULL, &read_and_write_to_buffer, buffer);
	if(rc){
    printf("ERROR: thread 1 pthread_create() return %d - %s \n", rc, strerror(rc));
	  return 1;
	}
  rc = pthread_create(&thr2, NULL, &write_to_console, buffer);

	if(rc){
    printf("ERROR: thread 2 pthread_create() return %d - %s \n", rc, strerror(rc));
	  return 1;
	 }

   pthread_join(thr1, NULL);
   pthread_join(thr2, NULL);
}
