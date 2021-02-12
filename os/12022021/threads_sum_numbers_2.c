#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void* thread_func(void* p_arg);

struct thr_data{
  int start;
  int end;
};

void* thread_func(void* p_arg){
  struct thr_data* l_data = (struct thr_data*)p_arg;
  //printf("l_data->start: %d, l_data->end: %d", l_data->start, l_data->end);
  long *l_total = malloc(sizeof(long));
  *l_total = 0;
  while(l_data->start <= l_data->end){
    *l_total += l_data->start++;
  }
  free(l_data);
  pthread_exit(l_total);
}

int main(int argc, char **argv){
  int n = atoi(argv[1]);
  int m = atoi(argv[2]);

  int res, l_start, l_end, l_step;
  pthread_t l_thrs[m];

  l_step = n / m;
  l_start = 1;
  l_end = l_step - 1;

  for(int ti = 0; ti < m; ti++){
    struct thr_data* l_thr_data = malloc(sizeof(struct thr_data));
    l_end = l_step;
    l_thr_data -> start = l_start;
    l_thr_data -> end = l_end;
    res = pthread_create(&l_thrs[ti], NULL, &thread_func, (void*)&l_thr_data);
    if(res != 0){
      printf("pthread_create error: %s\n", strerror(res));
      return res;
    }

    l_start = l_end + 1;
    l_end = l_start + l_step - 1;
  }

  long* l_thr_res;
  long l_total = 0;
  for(int ti = 0; ti < m; ti++){
    res = pthread_join(l_thrs[ti], (void**)&l_thr_res);
    if(res != 0){
      printf("pthread_join error: %s\n", strerror(res));
      return res;
    }

    l_total += *l_thr_res;
    free(l_thr_res);
  }

  printf("Total: %ld\n", l_total);

  return 0;
}
