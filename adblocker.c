/*
This program serves as a network-level adblocker.
*/

// Include statements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Definitions
#define DNS_PORT 53         // dns is on port 53
#define BUFFER_SIZE 512     // for dns packets

int main() {
    // Variable declarations
    int sockfd;                                     // socket file descriptor
    struct sockaddr_in server_addr, client_addr;    // address structure (server, client)
    socklen_t client_len = sizeof(client_addr);     // length of client
    char buffer[BUFFER_SIZE];                       // buffer for dns packets

    /* ----- Create a UDP Socket ----- */
    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    /* ----- Clear out server address structure ----- */
    memset(&server_addr, 0, sizeof(server_addr));

    /* ----- Set up server address ----- */
    server_addr.sin_family = AF_INET;           // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY;   // Listen on all available network interfaces
    server_addr.sin_port = htons(DNS_PORT);     // Set port 53

    /* ----- Connect socket & server address ----- */
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("DNS server listening on port %d...\n", DNS_PORT);

    /* ----- Main Server Loop ----- */
    while (1) {
        /* ----- Receive DNS Query ----- */
        ssize_t len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &client_len);
        
        // If packet received,
        if (len > 0) {
            printf("Received %ld byte DNS query.\n", len);
            
            /*
            TODO:
            - Parse DNS Query
            - Check if domain is in adblockist
            - Send a response
            */
        }
    }

    close(sockfd);
    return 0;
}