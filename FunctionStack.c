#include <stdio.h>

static inline void printBar();
void f1(short[],char*,double,int);
void f2(int,double);

/*Function stack - Program to help give an idea of how variables & parameters are laid out in memory*/
//When looking at the output, compare items at the same "depth"
//Their addresses will not exactly match up, but will be very close in value.

static int count = 0;
static int depth = 0;
int main(int argc, char** argv){

    
    printf("| Value   \t|\tAddress  \t|\n");
    depth++;
    printf("| ----------\tMAIN\t----------\t|\n");
    printBar();
    for(int i =0; i < argc; i++){
        printf("| argv[%d] \t|\t%p\t|\n",i,&argv[i]);
    }
    int x = 1;
    double y = 1.0;
    char* str = "Hello!";
    short nums[] = {1,2,3,4};

    printf("| x \t\t|\t%p\t|\n",&x);
    printf("| y \t\t|\t%p\t|\n",&y);
    printf("| str \t\t|\t%p\t|\n",&str);
    printf("| Hello\t\t|\t%p\t|\n", str);
    printf("| nums[0] \t|\t%p\t|\n",&nums);
    printf("| nums[3] \t|\t%p\t|\n",&nums[3]);

    depth++;
    f1(nums,str,y,x);
    
    f2(x,y);
    depth--;
}


static inline void printBar(){
    printf("| ----------\t(%d)\t----------\t|\n",depth);
}

void f1(short nums[], char* str, double y, int x){
    
    printf("| ----------\tF1\t----------\t|\n");
    printBar();
    printf("| nums \t\t|\t%p\t|\n",&nums);
    printf("| str \t\t|\t%p\t|\n",&str);
    printf("| Hello\t\t|\t%p\t|\n", str);
    printf("| y \t\t|\t%p\t|\n",&y);
    printf("| x \t\t|\t%p\t|\n",&x);
    
    int fx = 2;
    double fy = 2.0;

    count++;
    if(count <=1){
        depth++;
        f1(nums,str,y,x);
        depth--;
    }
    depth++;
    f2(x,y);
    depth--;
    
}

void f2(int x, double y){
    if(count % 2 != 0){
        return;
    }
    int fx = 2;
    double fy = 2.0;
    printf("| ----------\tF2\t----------\t|\n");
    printBar();
    printf("| x \t\t|\t%p\t|\n",&x);
    printf("| y \t\t|\t%p\t|\n",&y);
    printf("| fx \t\t|\t%p\t|\n",&fx);
    printf("| fy \t\t|\t%p\t|\n",&fy);
    
    

}