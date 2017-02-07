#include<stdio.h>
#include<cstring>

int main(int argc, char** argv)
{
    char array1[8];
    char array2[8];
    int value = 10;
    
    strcpy(array1, "arrayOne");
    strcpy(array2, "arrayTwo");
    
    printf("array 1 is at %p with value %s \n", array1, array1);
    printf("array 2 is at %p with value %s \n", array2, array2);
    printf("value is at %p with value %i \n", &value, value);
    
    return 0;
}

