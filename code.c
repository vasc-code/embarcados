/*
Data de criação: 10-12-2022

Rafael Vasconcelos (vasconcelos_rafael@usp.br) - 11299791
Thiago Alves de Lima (thiagoalvesl@usp.br) - 10300150
Rafael Tommasello Ramos (rafatramos@usp.br) - 11232368
Igor Matheus Bruciere (igorbruciere@usp.br) - 11231990
Filipe dos Santos Stecconi (filipestecconi@usp.br) - 11232312

*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define MAX 100

char path_01[] = "/sys/class/gpio/export";
char path_02[] = "/sys/class/gpio/gpio";
char path_03[] = "/direction";
char path_04[] = "/value";
char buffer[MAX];
bool gameOver = false;
int aux;
char portas[5][3] = {"46","47","48","88","89"};

void acenderLED(int numeroLED, char *valor){
    char gpio[3];

    switch (numeroLED){
    case 1:
        acenderLEDPorta(portas[3],valor);
        break;
    
    case 2:
        acenderLEDPorta(portas[4],valor); 
        break;

    default:
        acenderLEDPorta(portas[3],"0");
        acenderLEDPorta(portas[4],"0");
        break;
    }
}

bool lerBotão(char *porta){
    char rd[3];
    strcat(strcpy(buffer, path_02), porta);
    strcat(strcpy(buffer, buffer), path_04);

    aux = open(buffer, O_RDONLY);
    int info_rd = read(aux, rd, 2);

    close(aux);

    if(rd[0] == 48) return true;
    else return false;
}

void acenderLEDPorta(char *porta, char *valor){
    strcat(strcpy(buffer, path_02), porta);
    strcat(strcpy(buffer, buffer), path_04);

    aux = open(buffer, O_WRONLY);

    write(aux, valor, 1);
    close(aux);
}

void reset(){
    acenderLED(1,"1");
    acenderLED(2,"1");

    gameOver = false;
}

int main(int argc, char *argv[]){
    int i;
    aux = open(path_01, O_WRONLY);

    for(i = 0; i < 5; i++){
        strcat(strcpy(buffer, portas[i]), "\n");
        write(aux, buffer, 3);
    }

    close(aux);

    for(i = 0; i < 3; i++){
        strcat(strcpy(buffer, path_02), portas[i]);
        strcat(strcpy(buffer, buffer), path_03);   

        aux = open(buffer, O_WRONLY);

        if(i<3){
            write(aux, "in", 3);
            close(aux);
        }
        else if(i>=3){
            write(aux, "out", 3);
            close(aux);
        }
    }

    reset();
    
    while(true){
        usleep(1500);

        if(lerBotão(portas[0]) && !gameOver){
            acenderLED(1, "0");
            printf("Jogador 1 ganhou");
            gameOver = true;
        } else if(lerBotão(portas[1]) && !gameOver){
            acenderLED(2, "0");
            printf("Jogador
             2 ganhou");
            gameOver = true;
        }
        
        if(lerBotão(portas[2])){
            reset();
            printf("Game Over! Começando novamente...");
        }
    }
 
    return EXIT_SUCCESS;
}
