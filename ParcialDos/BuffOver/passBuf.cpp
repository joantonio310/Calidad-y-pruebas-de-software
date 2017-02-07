#include<stdio.h>
#include<stdlib.h>
#include<cstring>

int authenticate(char* pass)
{
    int auth = 0;
    char password[16];
    strcpy(password, pass);
    if(strcmp(password, "1234567890") == 0)
    {
        auth = 1;
    }
    return auth;
}

int main(int argc, char** argv)
{
    authenticate(argv[1])?printf("access granted \n"):printf("access denied \n");
}