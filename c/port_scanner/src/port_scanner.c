#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Biblíoteca necessária para funções como o srtcat.
#define MAX_PORTS  100 // Definindo um limite de portas para o programa.

int main(void){

    int port[MAX_PORTS];
    int total_ports = 0;
    char ip[100];
    float ver = 1.1;
    char command[500] = "";
    char porta_text[20];

    printf("Port Scanner - By thpaes.cybersec\n");
    printf("Scan version: %.1f \n",ver);
    printf("Type the host: ");
    scanf("%99s",ip);
    snprintf(command, sizeof(command),"nc -zv %s", ip); // snprinf sendo usado para montar uma parte do comando contendo o ip e gravando na variável command.
    printf("Now enter the ports do you wanna scan (Type 0 to finish) \n");

    while(total_ports < MAX_PORTS){ // Repete a função até o limite máximo de portas ser atingido ou parado pelo usuário.
        printf("port number %d: ", total_ports + 1);
        scanf("%d",&port[total_ports]);

        if (port[total_ports] == 0){ // Se a porta digitada for ZERO, o while é interrompido e saímos da função.
            break;
        }

        snprintf(porta_text, sizeof(porta_text), " %d", port[total_ports]); // Aqui eu estou gravando os valores das portas com um espaço intencional.

        strcat(command,porta_text); // strcat unindo os pedaços do comando final gravado na variável command.

        total_ports++; // Aqui a funçao while retorna ao começo para o armazenamento de mais portas.
    }

    if (total_ports == 0){ // Verifica o valor escrito na variável total_p orts e se for zero, fecha o programa.
        printf("No ports to scan, exiting.");
        return 0;
    }

    printf("\nScanning Host %s...\n",ip);
    printf("Executing command: %s\n\n", command);

    system(command); // Executa o comando final montado

    return 0;
}
