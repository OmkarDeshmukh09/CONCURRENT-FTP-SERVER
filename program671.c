///////////////////////////////////////////////////////////////////////////
//
//                              CLIENT CODE
//
///////////////////////////////////////////////////////////////////////////

#include <stdio.h>                  // printf, scanf
#include <stdlib.h>                 // malloc, free  
#include <string.h>                 // memset, memcmp 

#include <unistd.h>                 // read, write, close                 
#include <fcntl.h>                  // creat, unlink

#include <sys/socket.h>             //scoket, bind, listen, accept, connect
#include <netinet/in.h>             // sockaddr_in, htons

#include <arpa/inet.h>

int main()
{
    int ServerSocketfd = 0 ;
    int iRet = 0 ;
    int Port = 11000;

    struct sockaddr_in ServerAddr;

//  Step 1 : Create TCP socket
    ServerSocketfd = socket(AF_INET, SOCK_STREAM, 0);

    if (ServerSocketfd < 0)
    {
        printf("Unable to Create the Socket \n");
        return -1;
    }

    printf("Socket gets successfully with fd : %d\n",ServerSocketfd);    
 
//  Step 2 : Connect with the Server

    memset(&ServerAddr, 0, sizeof(ServerAddr));

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(Port);

//  127.0.0.1 -> Binary form
    
    inet_pton(AF_INET,"127.0.0.1",&ServerAddr.sin_addr);

    iRet = connect(ServerSocketfd, (struct sockaddr*) &ServerAddr, sizeof(ServerAddr));

    if (iRet == -1)
    {
        printf("Unablr to connect with server\n");
        return -1;
    }

    printf("Client Succesfully connected with Server\n");
    

    return 0 ;
}