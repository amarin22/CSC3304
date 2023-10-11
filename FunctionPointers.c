#include <stdio.h>


int sortNums(int*,int, int (*cmp)(int,int));
int HighLow(int,int);
int LowHigh(int,int);
void PrintArray(int*,int);

/* Function Pointers - Program to showcase the syntax and sample use case of function pointers*/

int main (int argc, char ** argv){
    int nums[] = {3,101,6,2,-1,8,17,123,12,42,65,11,33,254,23,165,21,74,49,62};
    int size = 20;

    PrintArray(nums,size);
    printf("[*]Now Sorting High to Low\n");
    //Notice how we just supply the name of the function. We do not need the addressof (&) operator
    sortNums(nums,size,HighLow);
    PrintArray(nums,size);
    printf("[*]Now Sorting Low to High\n");
    sortNums(nums,size,LowHigh);
    PrintArray(nums,size);

}

//Selection sort cuz its simple
//cmp should return - number if 1st param comes AFTER second param
int sortNums(int* arr, int num_elements,int (*cmp)(int,int)){

    for(int i =0; i < num_elements; i++){
        for(int j = i; j < num_elements; j++){
            //We can call the function just like a regular one!
            int val = cmp(arr[i],arr[j]);
            if (val < 0)
            {
                //Swap
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }           
        }
    }
}

void PrintArray (int* arr, int num_elements){

    printf("[*]Array: [");
    for(int i = 0; i < num_elements-1; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d]\n",arr[num_elements-1]);

}

int HighLow(int n1, int n2){
    return n1 - n2;
}

int LowHigh(int n1, int n2){
    return n2 - n1;
}