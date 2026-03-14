#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Number of command line arguments are :%d\n",argc);

    if (argc != 5)
    {
        printf("Unable to procide as invaild number of arguments \n");

        printf("Please Provide : \n");
        printf("Ip Address \n  Port Number\n Targated file name\n New file Name\n");
    }
    

    printf(" Executable name : %s\n",argv[0]);
    printf(" IP Address : %s\n",argv[1]);
    printf(" Port Number :%s\n",argv[2]);
    printf(" Targated file name : %s\n",argv[3]);
    printf(" New file Name : %s\n",argv[4]);
    

    return 0;
}