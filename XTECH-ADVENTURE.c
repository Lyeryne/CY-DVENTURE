#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h>
#include <string.h>
#include "Process.h"
#define SIZE_LINE 10000
#define MAX_CHOICE 10

int main(){
//VARIABLES
  char line[SIZE_LINE];
  char currentLine[SIZE_LINE] = "";
  //char choice[SIZE_LINE];
  char description[SIZE_LINE];
  int num_choice[MAX_CHOICE];
  int currentPart = 0;
  int next_step;
  int currentChoice=0;
  char choices[10][2];
  char** stringtab[MAX_CHOICE];
  int i = 0;
  //char diese[] = "###";
//CREATION DE FICHIER
    FILE *file = fopen("txt/Event1.txt", "r");
    if (file == NULL) {
        printf("\nErreur fopen (file 1)\n");
        exit(1);
    }
//GAME
while (fgets(line, SIZE_LINE, file) != NULL) {
    if(line[0] == '#'){
        currentPart ++;
    }
    else{
        switch(currentPart){
        // on est dans la part 1 : la description du truc
        case 0: 
            ProcessDescription(line);
            break;
        
        // on est dans la part 2 : l'event 
        case 1: 
            //faut mettre processEvent normalement ici
            //ProcessEvent(line);

            //currentChoice le char[2] qui contient la description et le numero de l'etape suivante? 
            //choices le tableau 2d contenant tous les choice : la desciption et le numero de l'etape suivante associée
            currentChoice = choices[currentChoice][1];
            // next_step le numero de l'etape suivante dans le choice ou on est
            next_step = ProcessChoice(line, choices[currentChoice]);
            printf("la prochaine etape c'est : %d\n", next_step);
            while(stringtab[i] != "\0"){
                printf("%s", stringtab[i]);
                i++;
            }

            break;

        case 2:

            ProcessChoice(line, stringtab);
            break;

        
        case 3:

            //ProcessChoice(line);
            break;

        }
    }

}







/*
    if(strcmp(diese, line) == 0){
        //c'est la partie des choix
        if(line[0] == "*"){
            sscanf(line, "**%d", &num_choice[i]);
            i++;
        }
        while(fgets(line, SIZE_LINE, file) != NULL){
            sscanf(line, "**%d", &num_choice[i]);
            i++;
        }
    }
    else{
        printf("%s\n", line);
        fflush(stdin);
        if(line[0] == '#'){
            printf("oui");
            }
        for(int j = 0; j < i; j ++){
            printf("votre choix : %d\n", num_choice[j]);
        }
    
    if(line[0] == "###"){
        while(fgets(line, SIZE_LINE, file) != NULL)
            sscanf(line, "**%d", &num_choice);
    }
    
    
    
    
    
    if (line[0] != '(') {
        sscanf(line, "(%d)", &num_choice); // Extract the choice number using sscanf
        printf("(%d) ", num_choice);
        fgets(description, SIZE_LINE, file); // Extract the choice description
    } 
      else if (line[0] == '###') {
          printf("%s\n", line + 1);
          char user_choice[SIZE_LINE];
          fgets(user_choice, SIZE_LINE, stdin);
          int choice_num;
          sscanf(user_choice, "%d", &choice_num);   // Extract the user's choice
          if (choice_num == num_choice) {
            printf("%s\n", description); // Print the corresponding description
          }
      }*/
return 0;
}
