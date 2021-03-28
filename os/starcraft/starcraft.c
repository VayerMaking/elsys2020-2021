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
int current_minerals = 0;
int marine_count = 0;
int scv_count = 5;

struct mining_t{
  int mining_blocks_count;
  int * mining_blocks;
  int scv_id;
};

int find_first_minable_mining_block(int mining_blocks[], int mining_blocks_count){
  for(int i = 0; i < mining_blocks_count; i++){
    if(mining_blocks[i] > 0){
      return i;
    }
  }
  return -1;
}

void make_new_marine(){
  if(current_minerals >= 50){
    marine_count++;
    printf("You wanna piece of me, boy?\n");
    current_minerals = current_minerals - 50;
  }else{
    printf("Not enough minerals.\n");
  }
}

// void make_new_scv(int current_minerals){
//   if(current_minerals >= 50){
//     scv_count++;
//     current_minerals -= 50;
//   }else{
//     printf("Not enough minerals.\n");
//   }
// }

void *reading(void *args){
  char input = getchar();
  if(input == 'm'){
    make_new_marine();
  }else if(input == 's'){
    //make_new_scv(current_minerals);
  }
  pthread_exit(NULL);
}

void *scv(void *args){

  struct mining_t * mining = (struct mining_t *)args;
  while(1){
    if(mining->mining_blocks_count * 500 <= current_minerals){
      break;
    }
    for(int i = 0; i < mining->mining_blocks_count; i++){
      pthread_mutex_lock(&lock);
      if(mining->mining_blocks[i] > 0){
        pthread_mutex_unlock(&lock);
        sleep(3);
        pthread_mutex_lock(&lock);
        printf("SCV %d is mining from mineral block %d\n", mining->scv_id, i + 1);
        if(mining->mining_blocks[i] < 8){
          current_minerals += mining->mining_blocks[i];
          mining->mining_blocks[i] = 0;
        }else{
          current_minerals += 8;
          mining->mining_blocks[i] = mining->mining_blocks[i] - 8;
        }

        printf("SCV %d is transporting minerals\n", mining->scv_id);
        pthread_mutex_unlock(&lock);
        sleep(2);
        pthread_mutex_lock(&lock);
        printf("SCV %d delivered minerals to the Command center\n", mining->scv_id);

      }
      pthread_mutex_unlock(&lock);
    }
  }
  pthread_exit(NULL);
}



int main(int argc, char **argv){
  pthread_mutex_init(&lock, NULL);
  int mining_blocks_count = 0;
  //printf("argc: %d\n",argc);
  if(argc < 2){
    mining_blocks_count = 2;
  }else{
    mining_blocks_count = atoi(argv[1]);
  }
  int mining_blocks[mining_blocks_count];

  for(int i = 0; i < mining_blocks_count; i++){
    mining_blocks[i] = 500;
  }


  pthread_t * SCV_t = malloc(scv_count * sizeof(pthread_t));
  //printf("argv: %s\n",argv[1]);
  int rc;
  int process_id = 0;

  for(int i = 0; i < scv_count; i++){
    process_id = i + 1;
    //printf("process_id: %d\n", process_id);
    struct mining_t * mining = malloc(sizeof(struct mining_t));
    mining->mining_blocks_count = mining_blocks_count;
    mining->mining_blocks = mining_blocks;
    mining->scv_id = process_id;
    rc = pthread_create(&(SCV_t[i]), NULL, &scv, (void *)mining);

    if(rc){
      printf("%d : %s\n", rc, strerror(rc));
      return 1;
    }
  }
  while(marine_count < 20 && scv_count + marine_count <= 200){
    pthread_t * reading_t = malloc(sizeof(pthread_t));
    int a = 0;
    a = pthread_create(&(reading_t), NULL, &reading, NULL);

    if(a){
      printf("%d : %s\n", a, strerror(a));
      return 1;
    }
  }



  for(int i = 0; i < scv_count; i++){
    pthread_join(SCV_t[i], NULL);
  }
  pthread_mutex_destroy(&lock);
  printf("Map minerals %d, player minerals %d, SCVs %d, Marines %d\n", mining_blocks_count * 500, current_minerals, scv_count, marine_count);
  return 0;
}
