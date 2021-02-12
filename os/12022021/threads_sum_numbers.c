#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>

void *sum(void *thread_id){
    //int tid;
    //tid = *((int*)thread_id);
    //printf("Hello World! It's me, thread #%d!\n", tid);
    //free((int*)thread_id);
    

    return NULL;
}

int main(int argc, char **argv){
  int n = atoi(argv[1]);
  int m = atoi(argv[2]);

  printf("%d", n);

  pthread_t threads[m];

  int* pt;

  for(int t=0; t<m; t++){
    pt = malloc(sizeof(int));
    *pt = t;
	   printf("In main(): creating thread %d\n", t);
	   int rc = pthread_create(&threads[t], NULL, &sum, (void *)pt);
	   if(rc){
       perror("sdfds");
       printf("ERROR; pthread_create() return %d - %s \n", rc, strerror(rc));
	     exit(-1);
	   }
	}

  for(int t=0; t<m; t++){
    pthread_join(threads[t], NULL);
  }

	printf("MAIN going to exit...\n");
	pthread_exit(NULL);

  return 0;
}
