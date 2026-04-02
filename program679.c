//////////////////////////////////////////////////////////////
//
//  Server code
//
//////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h> 

//////////////////////////////////////////////////////////////
//
//  CommandLine Argument Application
//  1'st Argument : Port Number
//  ./Server    9000
//   argv[0]   argv[1]
//
//////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    int ServerSocket = 0;
    int ClientSocket = 0 ;
    int Port = 0;
    int iRet = 0;

    struct sockaddr_in ServerAddr;
    struct sockaddr_in ClientAddr;

    socklen_t AddrLen = sizeof(ClientSocket);

    if ( argc < 2 ||argc > 2 )
    {
        printf("Unable toprocessed as invalid number of arguments\n");
        printf("Please provide the port number \n");
    
        return -1 ;
    }

//  Port  number og the Server
    Port = atoi(argv[1]);

////////////////////////////////////////////////////////////////////////////
//
//      Step 1 : Create TCP socket
//
////////////////////////////////////////////////////////////////////////////

    ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (ServerSocket < 0)
    {
        printf("Uablr to Create server socket \n");
        return -1;
    }

////////////////////////////////////////////////////////////////////////////
//
//      Step 1 : BIlne socket to IP and Port
//
////////////////////////////////////////////////////////////////////////////    

    memset(&ServerAddr, 0, sizeof(ServerAddr));

    // Initlize the structure

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(Port);
    ServerAddr.sin_addr.s_addr = INADDR_ANY;

    iRet = bind(ServerSocket, (struct sockaddr *) &ServerAddr, sizeof(ServerAddr));

    if (iRet == -1)
    {
        printf("Unable to  bind\n");

        close(ServerSocket);
    
        return-1;
    }
    
////////////////////////////////////////////////////////////////////////////
//
//      Step 3 : Listen for client connection
//
//////////////////////////////////////////////////////////////////////////// 


    iRet = listen(ServerSocket, 11);

    if (iRet == -1)
    {
        printf("Server is not able to Recive Request \n");
        close(ServerSocket);
        return -1 ;
    }
    
    printf("Server is Running on port : %d \n",Port);

///////////////////////////////////////////////////////////////////////////
//
//      loop which accepts client request countinusly
//
//////////////////////////////////////////////////////////////////////////// 

// loop to accept multiple client request

    while (1)
    {
        ////////////////////////////////////////////////////////////////////////////
        //
        //      Step 4 : Accept the client Request
        //
        //////////////////////////////////////////////////////////////////////////// 

        memset(&ServerAddr, 0, sizeof(ServerAddr));

        printf("Server is waitin for client request\n");

        ClientSocket =accept(ServerSocket, ( struct sockaddr*) &ClientAddr, &AddrLen);

        if (ClientSocket < 0)
        {
            printf("Unable to accept client  request \n");

            continue;   // Used for while 
        }
        printf("CLient gets connected : %s\n",inet_ntoa(ClientAddr.sin_addr));
    }// end of while

    return 0;

}//end of main