#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ProcessDescription(char* string){
    //affiche la description ligne par ligne
    printf("%s\n", string);
}

void ProcessEvent(){
    //gère l'Event

    printf("t'es trop fort bg");
}

int ProcessChoice(char* string){
    //gère le choix
    int next_step, i=0;
    do{
        if(string[i] == '_'){
            next_step = string[i+1] * 10 + string[i+2] * 1;
        }
        i++;
    }while(string[i] != '#');
return next_step - 528;
}