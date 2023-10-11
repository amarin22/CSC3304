#include <stdio.h>
#include <stdlib.h>

/*StructMem - showcases how different struct layouts can affect their size*/
struct s1{
    int i1;
    int i2;
    long l1;
    long l2;
    char c1;
    char c2;
    char ca[10];
};

struct s2{
    int i1;
    long l1;
    int i2;
    long l2;
    char c1;
    char ca[10];
    char c2;
};

struct s3{
    int i1;
    char ca[10];
    long l1;
    char c1; 
    long l2;   
    char c2;
    int i2;
};

struct s4{
    char ca[10];
    char c1;
    char c2;
    int i1;    
    int i2;
    long l1;
    long l2;
};

int main(){
    printf("[*]The sizes of datatypes are as follows:\n[*]int is %ld bytes\tlong is %ld bytes\tchar is %ld bytes\n", sizeof(int),sizeof(long),sizeof(char) );
    size_t sExpected = (sizeof(int) * 2) + (sizeof(long)*2) + (sizeof(char) * 12);
    printf("[*]With 2 ints, 2 longs, 2 chars, and a char array of 10, we expect the struct to be of size %ld bytes\n", sExpected);
    printf("[*]But the sizes of the structs are actually:\nstruct 1 %ld bytes\tstruct 2 %ld bytes\tstruct 3 %ld bytes\tstruct 4 %ld bytes\n",sizeof(struct s1), sizeof(struct s2), sizeof(struct s3), sizeof(struct s4));

    struct s1* better = (struct s1*) malloc(sizeof(struct s1));
    struct s2* worse = (struct s2*) malloc(sizeof(struct s2));
    struct s3* worser = (struct s3*) malloc(sizeof(struct s3));
    printf("[*]S1 starts at %p\ni1: %p\ni2: %p\nl1: %p\nl2: %p\nc1: %p\nc2: %p\nca: %p\n",better, &better->i1, &better->i2, &better->l1, &better->l2, &better->c1,&better->c2,&better->ca);
    printf("[*]S2 starts at %p\ni1: %p\nl1: %p\ni2: %p\nl2: %p\nc1: %p\nca: %p\nc2: %p\n",worse, &worse->i1, &worse->l1, &worse->i2, &worse->l2, &worse->c1,&worse->ca,&worse->c2);
    printf("[*]S3 starts at %p\ni1: %p\nca: %p\nl1: %p\nc1: %p\nl2: %p\nc2: %p\ni2: %p\n",worser, &worser->i1, &worser->ca, &worser->l1, &worser->c1, &worser->l2,&worser->c2,&worser->i2);
}