//My first program in C
#include <stdio.h>
#include <stdlib.h>

int main(void){

    int port;
    char ip[100];
    float ver = 1.1;
    char command[150];

    printf("Port Scanning\n");
    printf("Scan version: %.1f \n",ver);
    printf("Type the host: ");
    scanf("%99s",ip);
    printf("Now type the port do you wanna scan: ");
    scanf("%i",&port);
    printf("Scanning host %s in %i port...\n",ip,port);
    sprintf(command,"nc -zc %s %i", ip, port);
    system(command);
}
