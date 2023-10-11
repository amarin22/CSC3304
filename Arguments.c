#include <stdio.h>

int main (int argc, char** argv){

    printf("[*]argc = %d, which means there were %d arguments supplied\n",argc,argc -1);
    for(int i = 0; i < argc; i++){
        printf("[*]argv[%d] has \"%s\"\n",i,argv[i]);
    }
}