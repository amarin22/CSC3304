#include <stdio.h>

/*Conds - A program to showcase the different control flow statements
    & how conditionals work within C
*/
int main (){

    int var1 = 10;
    int var2 = 0;
    int var3 = -5;
    //var1 is not 0, so it will be true
    if(var1){
        printf("[*]Var 1 is true\n");
    } else{
        printf("[*]Var 1 is false\n");
    }
    //var2 is 0, so it will be false
    if(var2){
        printf("[*]Var 2 is true\n");
    } else{
        printf("[*]Var 2 is false\n");
    }
    //var3 is not 0, so it will be true
    if(var3){
        printf("[*]Var 3 is true\n");
    } else{
        printf("[*]Var 3 is false\n");
    }
    
    printf("[*]var1 is %d before the loop\n",var1);
    while(var1){
        var1--;
        printf("[*]var1 is now %d\n",var1);
    }


    do{
        printf("[*]Doing something!\n");
    }while(var2);

    printf("[*]Init!\n");
    for(int i = 0; printf("[*]Checking conditional!\n"),i < 3; i++, printf("[*]Increment!\n")){
        printf("[*]Inside the loop!\n");
    }

    return 0;

}