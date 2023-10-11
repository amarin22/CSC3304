#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int nums[5];
    char* word = "Hello";
    char vectorinit[4] = {'T','e','s','t'};
    
    
    long pidigits[] = {3,1,4,1,5};
    
    for(int i = 0; i < 5; i++){
        nums[i] = i*3;
    }
    printf("[*]nums is at \t\t%p\n", nums);
    for(int i = 0; i < 5; i++){
        printf("[*]nums[%d] = %d   \t&nums[%d] = %p\n",i,nums[i],i,&nums[i]);
    }
    printf("[*]pidigits is at \t%p\n", pidigits);
    for(int i = 0; i < 5; i++){
        printf("[*]pidigits[%d] = %ld\t&pidigits[%d] = %p\n",i,pidigits[i],i,&pidigits[i]);
    }

    printf("[*]nums + 2 = %p\n", nums + 2);
    printf("[*]*(nums + 2) = %d\n", *(nums + 2));

    printf("[*]Our word is %s %s\n",vectorinit,word);

}