//***** CLIENT ***** //
// By: Elad Keyshawn


#include "stdio.h"

#if defined _WIN32
// See at https://msdn.microsoft.com/en-us/library/windows/desktop/ms740506(v=vs.85).aspx
// link with Ws2_32.lib
#pragma comment(lib,"Ws2_32.lib")
#include <winsock2.h>
#include <ws2tcpip.h>

#else //  linux
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <sys/types.h> 
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

#define SERVER_IP_ADDRESS "10.0.0.14"
#define SERVER_PORT 5060

int main()
{
	int s = -1;
	char bufferReply[80] = { '\0' };
	char message[] = "Good morning Server!\n";
	int messageLen = strlen(message) + 1;
    char SERVER_IP6_ADDRESS[128] = {'\0'};
    
	// Create socket (now supporting ipv6)
	if ((s = socket(AF_INET6, SOCK_DGRAM, IPPROTO_UDP)) == -1) // In Windows -1 is SOCKET_ERROR
	{
		printf("Could not create socket : %d");
			return -1;
	}

	// Setup the server address structure.
	// Port and IP should be filled in network byte order (learn bin-endian, little-endian)
	//
	struct sockaddr_in6 serverAddress;
	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin6_family = AF_INET6;
	serverAddress.sin6_port = htons(SERVER_PORT);
    serverAddress.sin6_addr = in6addr_loopback;
    
//	int rval = inet_pton(AF_INET6, (const char*)SERVER_IP_ADDRESS, &serverAddress.sin_addr);
//	if (rval <= 0)
//	{
//		printf("inet_pton() failed");
//		return -1;
//	}

	//send the message
	if (sendto(s, message, messageLen, 0, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1)
	{
		printf("sendto() failed with error code  : %d");
			return -1;
	}

	struct sockaddr_in6 fromAddress;
    socklen_t fromAddressSize = sizeof(fromAddress);
	memset((char *)&fromAddress, 0, sizeof(fromAddress));
    
    //get data
    if (recvfrom(s, bufferReply, sizeof(bufferReply) -1, 0, (struct sockaddr *) &fromAddress, &fromAddressSize) == -1)
	{
		printf("recvfrom() failed with error code  : %d");
		return -1;
	}

	printf("recieved: %s", bufferReply);
    char from_address_readable[128] = {'\0'};
    inet_ntop(AF_INET6, &fromAddress.sin6_addr, &from_address_readable, sizeof(from_address_readable));

    printf("from: %s\n", from_address_readable);
    
    
	close(s);

    return 0;
}

