#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){

	char stringIP[INET6_ADDRSTRLEN];
	int i;
	
	for(int l=1; l<argc; l++){

		struct addrinfo hints;
		struct addrinfo *ai0;
	
		memset(&hints, 0, sizeof(hints));
		// Unspecified protocol (IPv4 or IPv6 okay)
		hints.ai_family = PF_UNSPEC;
		// Want a TCP socket 						
		hints.ai_socktype = SOCK_STREAM; 				

		if ((i = getaddrinfo(argv[l], NULL, &hints, &ai0)) != 0) {
			printf("Error: unable to lookup IP address: %s\n", gai_strerror(i));
		}

		struct addrinfo *ai;
		//The IP address
		void *IPaddress;
		//The IP version                                    
		char *IPversion;
		//Loop over the linked list of addresses
		for (ai = ai0; ai != NULL; ai = ai->ai_next) {
			//If it is an IPv4 address
			if(ai->ai_family == AF_INET){
				IPversion = "IPv4";
				struct sockaddr_in *v4;
				v4 = (struct sockaddr_in *)ai->ai_addr;
				IPaddress = &(v4->sin_addr);
			} else {
				//IPv6 address
				IPversion = "IPv6";
				struct sockaddr_in6 *v6;
				v6 = (struct sockaddr_in6 *)ai->ai_addr;
				IPaddress = &(v6->sin6_addr);
			}

			inet_ntop(ai->ai_family, IPaddress, stringIP, sizeof(stringIP));
			printf("%s %s %s\n", argv[l], IPversion, stringIP);

		}

		freeaddrinfo(ai0);

	}
	
	return 0;
}