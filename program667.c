///////////////////////////////////////////////////////////////////////////
//
//                              SERVER CODE
//
/////////////////////////////////////////////////////////////////////////// 

#include <stdio.h>                  // printf, scanf
#include <stdlib.h>                 // malloc, free  
#include <string.h>                 // memset, memcmp 

#include <unistd.h>                 // read, write, close                 
#include <fcntl.h>                  // creat, unlink

#include <sys/socket.h>             //scoket, bind, listen, accept, connect
#include <netinet/in.h>             // sockaddr_in, htons

/*

struct sockaddr
{
    sa_family_t sa_ family;
    char sa_data[14];
};
return value : on success 0 return
return value : on failuare -1 return

*/

int main()
{
    int ServerScoket = 0 ;              // FD : 

    int iRet = 0 ;                      //Bind chy return value sathi
    int Port = 11000;

    struct sockaddr_in ServerAddr;

    //Step 1 : Create TCP Socket
    ServerScoket = socket(AF_INET,SOCK_STREAM,0);

    if (ServerScoket < 0)
    {
        printf("Unable to create socket.\n");

        return -1;
    }

    printf("Socket get's Created Succesfully with FD : %d\n",ServerScoket);
    

    //Step 2 : Attached the Socket to IP Addressand Port number

    memset(&ServerAddr, 0, sizeof(ServerAddr));

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.s_addr = INADDR_ANY;                    // Address to accept the new incoming msg
    ServerAddr.sin_port = htons(Port);

    iRet = bind(ServerScoket,(struct sockaddr*) &ServerAddr, sizeof(ServerAddr));          // bind - is used to bind a name to a socket

    if (iRet == -1)
    {
        printf("Bind system call fail \n");
        close(ServerScoket);
        return -1;
    }
    
    printf("Bind operation with socket is Succesfull. \n");

    return 0 ;
}
