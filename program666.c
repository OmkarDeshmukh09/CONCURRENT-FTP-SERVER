///////////////////////////////////////////////////////////////////////////
//
//                              SERVER CODE
//
///////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <sys/socket.h>

int main()
{
    int ServerScoket = 0 ;              // FD : 

    ServerScoket = socket(AF_INET,SOCK_STREAM,0);

    if (ServerScoket < 0)
    {
        printf("Unable to create socket\n");

        return -1;
    }

    printf("Socket get's Created Succesfully with FD : %d\n",ServerScoket);
    

    return 0 ;
}