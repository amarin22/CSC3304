#include <stdio.h>
//Example showing going from an int, getting a pointer to the int with the & operator
//and finally deferencing the pointer to the int.
//Prints the result of each operation at the end
int main(char* args){
    int someVal = 34; //just some data we're tracking
    //int* -> variable of type integer pointer
    //&someVal -> the & unary operator gets the address of the argument supplied
    int* point = &someVal; 
    //* as a unary operator dereferences a pointer
    //dereferencing takes an address and gives the value that is there
    int defref = *point;
    //someVal is a variable containing the value 34. It exists somewhere in memory
    //&someVal is asking "Where is someVal located in memory" (for examples sake we'll pretend its 0x7000100)
    //point stores the ADDRESS obtained from the & operator
    //so in the example, point = 0x7000100
    //*point deferences it, so its saying "What is stored at address 0x7000100" (This would be 34)

    printf("[*]Number: %d \n[*]Pointer Address: %p \n[*]Deferencing the Pointer gives: %d \n",someVal,point,defref);

}