//My first program in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PORTS  100

int main(void){

    int port[MAX_PORTS];
    int total_ports = 0;
    char ip[100];
    float ver = 1.1;
    char command[500] = "";
    char porta_texto[20];

    printf("Port Scanning - By thpaes.cybersec\n");
    printf("Scan version: %.1f \n",ver);
    printf("Type the host: ");
    scanf("%99s",ip);
    snprintf(command, sizeof(command),"nc -zv %s", ip);
    printf("Now enter the ports do you wanna scan (Type 0 to finish) \n");

    while(total_ports < MAX_PORTS){
        printf("port number %d: ", total_ports + 1);
        scanf("%d",&port[total_ports]);

        if (port[total_ports] == 0){
            break;
        }

        snprintf(porta_texto, sizeof(porta_texto), " %d", port[total_ports]);

        strcat(command,porta_texto);

        total_ports++;
    }

    if (total_ports == 0){
        printf("No ports to scan, exiting.");
        return 0;
    }

    printf("\nScanning Host %s...\n",ip);
    printf("Executing command: %s\n\n", command);

    system(command);

    return 0;
}
