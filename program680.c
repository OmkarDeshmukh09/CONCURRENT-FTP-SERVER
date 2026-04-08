#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> 

int main()
{
    printf("PID of the runiing process : %d \n",getpid);

    printf("PID of the runiing process : %d\n",getppid);

    return 0;
}