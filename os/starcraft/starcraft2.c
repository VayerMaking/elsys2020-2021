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
int c = 0;

struct mining_t{
  int mining_blocks_count;
  int * mining_blocks;
  int scv_id;
  int block_id;
};

void *scv(void *args){
  c++;
  struct mining_t * mining = (struct mining_t *)args;
  for(int i = 0; i < mining->mining_blocks_count; i++){

  if(mining->mining_blocks[i] > 0){
    while(1){
    pthread_mutex_lock(&lock);

    //sleep(3);
    printf("SCV %d is mining from mineral block %d\n", c, mining->block_id + 1);
    mining->mining_blocks[mining->block_id] -= 8;
    printf("SCV %d is transporting minerals\n", c);
    //sleep(2);
    printf("current_minerals before: %d\n", current_minerals);
    current_minerals += 8;
    printf("current_minerals after: %d\n", current_minerals);


    pthread_mutex_unlock(&lock);
    printf("SCV %d delivered minerals to the Command center\n", c);
    if(mining->mining_blocks[i] <= 0){
        break;
    }
  }
  }

  }
  pthread_exit(NULL);
}

int find_first_minable_mining_block(int mining_blocks[], int mining_blocks_count){
  for(int i = 0; i < mining_blocks_count; i++){
    if(mining_blocks[i] > 0){
      return i;
    }
  }
  return -1;
}

void make_new_marine(int current_minerals){
  if(current_minerals >= 50){
    marine_count++;
    printf("You wanna piece of me, boy?\n");
    current_minerals -= 50;
  }else{
    printf("Not enough minerals.\n");
  }
}

void make_new_scv(int current_minerals){
  if(current_minerals >= 50){
    scv_count++;
    current_minerals -= 50;
  }else{
    printf("Not enough minerals.\n");
  }
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
  //fill every mining block with minerals
  int mining_blocks[mining_blocks_count];

  for(int i = 0; i < mining_blocks_count; i++){
    mining_blocks[i] = 500;
    printf("mining block %d: \n", mining_blocks[i]);
  }

  // int first = 0;
  // first = find_first_minable_mining_block(mining_blocks, mining_blocks_count);
  // printf("da 1st minable block: %d\n", first);

  pthread_t * SCV_t = malloc(scv_count * sizeof(pthread_t));
  //printf("argv: %s\n",argv[1]);
  int rc;

  for(int i = 0; i < scv_count; i++){
      //int *process_id = malloc(sizeof(int));
      int process_id = i + 1;
      //printf("process_id: %d\n", process_id);
      int block_id = find_first_minable_mining_block(mining_blocks, mining_blocks_count);
      struct mining_t mining = {mining_blocks_count, mining_blocks, process_id, block_id};
      rc = pthread_create(&(SCV_t[i]), NULL, &scv, (void *)&mining);

      if(rc){
        printf("%d : %s\n", rc, strerror(rc));
        return 1;
      }
    }



  while(marine_count < 20){
    char input = getchar();
    if(input == 'm'){
      make_new_marine(current_minerals);
    }else if(input == 's'){
      make_new_scv(current_minerals);
    }

    //if(scv_count + marine_count >= 200){
      //break;
    //}



  }
    for(int i = 0; i < scv_count; i++){
      pthread_join(SCV_t[i], NULL);
    }
  pthread_mutex_destroy(&lock);
  pthread_exit(NULL);
  printf("Map minerals %d, player minerals %d, SCVs %d, Marines %d\n", mining_blocks_count * 500, current_minerals, scv_count, marine_count);
  return 0;
}
