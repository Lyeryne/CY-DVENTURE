#ifndef PROCESS_H
#define PROCESS_H

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

int ProcessChoice(char* string, char[2][choice]){
    //gère le choix
    int next_step, i=0;
    char delim[] = "_";
    char* cutteds = strtok(string, delim);
    while(cutteds != NULL){
        choice[i] = cutteds;
        cutteds = strtok(NULL, delim);      
        i++;
    }
    /*
    do{
        if(string[i] == '_'){
            next_step = string[i+1] * 10 + string[i+2] * 1;
        }
        i++;
    }while(string[i] != '\n');  */
    printf("%s", string[string[0]-1]);

return next_step - 528;
}

#endif