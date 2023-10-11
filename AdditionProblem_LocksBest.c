#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void * addFunction();
pthread_mutex_t addLock;
long val; //Global variable we will update in each thread

int main(){
    val = 0; //Initialize

    if (pthread_mutex_init(&addLock,NULL))
    {
        printf("[!]Error initializing lock!\n");
        return -1;
    }
    
    printf("[*]The value starts at %ld\n", val);
    pthread_t t1, t2, t3;

    clock_t start = clock();

    printf("[*]Creating first thread...\n");
    //Here we call pthread_create to create and RUN a new thread
    //1st param - pthread_t (maps to some int type), which will be the thread id of the the newly created thread
    //2nd param - pthread_attr_t - Attributes to create the new thread with. We use NULL here for the defaults
    //3rd param - void* fun, the function we want our thread to start running, must be of type void*
    //4th param - void* args, if we wanted to pass in an arguments to the thread function, we'd convert it to a void pointer and supply it here
    pthread_create(&t1, NULL, addFunction, NULL);
    printf("[*]Created thread %ld!\n", t1);

    printf("[*]Creating second thread...\n"); 
    pthread_create(&t2, NULL, addFunction, NULL);
    printf("[*]Created thread %ld!\n", t1);

    printf("[*]Creating third thread...\n"); 
    pthread_create(&t3, NULL, addFunction, NULL); 
    printf("[*]Created thread %ld!\n", t1);
    printf("[*]Joining now...\n");
    //Joining a thread means we want to pause execution until the supplied thread is finished.
    //If the main function finishes first, the the process will be deleted and the threads may not complete their work
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    clock_t end = clock();

    printf("[*]All threads of finished, the final value is %ld\n",val);
    double timetaken = (double)(end-start) / CLOCKS_PER_SEC;
    printf("[*]Time taken: %.3f seconds\n", timetaken);
    //See the addFunction for a description of why
}


void * addFunction(){

    pthread_t pid = pthread_self() % 10000; //We shrink our thread id for printing purposes
    printf("[^]Thread %ld started!\n",pid); 
    long local_counter = 0; //We also increment a local counter
    
    for(int i = 0; i < 100000; i++){
        

        local_counter++;
        if(!(local_counter % 10)){
            printf("[*]Thread %ld has counter %ld and the value is %ld\n",pid,local_counter,val);
        }
    }
    pthread_mutex_lock(&addLock);
    val = val + local_counter;
    pthread_mutex_unlock(&addLock);
    pthread_exit(NULL);
}
