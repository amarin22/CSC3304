#include <stdio.h>
/*Basic Vars - Program to showcase some of the different C data types, their size, and some behaviors*/
int main(){
    char c = 'A';
    
    int radius = 4;
    long bigNum = -3214213;
    long long evenBigger = 42132133213;
    unsigned long uBig = bigNum; //Unsigned numbers are NOT 2's compliment, and thus can only be positive (0 <-> (2^bits) - 1)
    
    float farea = 4.0 * 3.14;
    double darea = 4.0 * 3.14;
    

    printf("[*]Values:\tradius %d\tbigNum%ld\tevenBigger %lld\tuBig %lu\n",radius,bigNum,evenBigger,uBig);
    printf("[*]More values:\tfarea %f\tdarea %f\n",farea,darea);

    printf("[*]The Character is %c or %d\n\n",c,c);
    //We use the sizeof keyword to get the # of bytes a datatype is
    //Note that different architectures (ARM, x86, 32-bit,64-bit) may result in having different sizes!
    printf("[*]Sizes:\tType\tnumBytes\n");
    printf("[1]:\t\tchar\t%ld\n",sizeof(char));
    printf("[2]:\t\tshort\t%ld\n",sizeof(short));
    printf("[3]:\t\tint\t%ld\n",sizeof(int));
    printf("[4]:\t\tlong\t%ld\n",sizeof(long));
    printf("[5]:\t\t2xlong\t%ld\n",sizeof(long long));
    printf("[6]:\t\tfloat\t%ld\n",sizeof(float));
    printf("[7]:\t\tdouble\t%ld\n",sizeof(double));
    
    return 0;

}