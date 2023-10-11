#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * WorkerFunc();
void * SleeperFunc();


int main(){

    printf("[*]Starting...\n");

    pthread_t worker,sleeper;

    printf("[*]Making Sleeper...\n");
    pthread_create(&sleeper,NULL,SleeperFunc,NULL);
    printf("[*]Making Worker...\n");
    pthread_create(&worker,NULL,WorkerFunc,NULL);
    printf("[*]Joining...\n");
    pthread_join(sleeper,NULL);
    pthread_join(worker,NULL);
    printf("[*]All threads done!\n");
}


void* SleeperFunc(){
    for(int i = 0; i < 500; i++){
        printf("[#]Sleeper: i is %d\n", i);
        usleep(100);
    }

    pthread_exit(NULL);
}

void* WorkerFunc(){

    for(int i =0; i < 100000; i++){
        printf("[$]Worker: i is %d\n", i);
    }

    pthread_exit(NULL);
}