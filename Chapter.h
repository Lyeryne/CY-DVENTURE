#ifndef CHAPTER_H
#define CHAPTER_H

#include "DisplayTXT.h"
#include "structChoice.h"
#include "Process.h"
#include "Stdtcreate.h"
#include "statPlayer.h"
#include "gameSave.h"

#define SIZE_LINE 10000
#define MAX_CHOICE 10

chapter create_chapter(char *chapter_name)
{
    // VARIABLES
    char line[SIZE_LINE];
    
    int currentPart = 0;
    int next_step;
    int currentChoiceInd = 0;
    char *currentChoice[2];
    char choices[10][2];
    
    int i = 0;
    char * path = (char *)malloc((strlen("txt/") + strlen(chapter_name) + strlen(".txt"))* sizeof(char) + 1);
    //~~> contien le chemin d'accès au fichier txt que nous voulons ouvrir

    strcpy(path, "txt/");//copie la chaîne 'txt' dans chaîne 'path'
    strcat(path, chapter_name); //suivie de 'chapter_name'(concaténation)
    strcat(path, ".txt");//et de '.txt'

    FILE *file = fopen(path, "r");
    //crée un chemin vers le fichier txt à partir du nom du chapitre et stocke dans 'path'

    // FILE *file = fopen("../txt/Event1.txt", "r");
    if (file == NULL)
    {
        printf("\nErreur fopen (file 1)\n");
        exit(1);
    }

    // char buf[10] = "";
    chapter chap = {}; // {malloc(1), malloc(0), malloc(0)};
    char first_line_chars[4];

    // GAME
    while (fgets(line, SIZE_LINE, file) != NULL)
    {
        *first_line_chars = '\0';
        strncat(first_line_chars, line, 3);//extrait les 3 premiers caractères en les stockant dans 'first_line_chars'
        if (strcmp(first_line_chars, part_seperator) == 0)
        //Si ces 3 premiers caractères correspondent à 'part_seperator'
        {
            //Alors currentPart est incrémentée
            currentPart++;
        }
        else //Sinon utilisé pour traiter la ligne en fonction de la valeur de 'currentPart'
        {
            switch (currentPart)
            {
            // on est dans la part 1 : décrit la description du chapitre
            case 0:
                ProcessDescription(&chap, line);
                break;
            case 1:
                ProcessEvent(&chap, line);
                break;

            // on est dans la part 2 : décrit l'événement du chapitre 
            case 2:
                ProcessChoice(&chap, line);
                //~~> affiche l'événement en cours et les choix disponibles.

                // faut mettre processEvent normalement ici
                // ProcessEvent(line);

                // currentChoice le char[2] qui contient la description et le numero de l'etape suivante?
                // choices le tableau 2d contenant tous les choice : la desciption et le numero de l'etape suivante associée
                /*  fillChoice(currentChoice, choices, currentChoiceInd);
                 // next_step le numero de l'etape suivante dans le choice ou on est

                 printf("la prochaine etape c'est : %d\n", next_step);
                 while(choices[i][0] != "\0"){
                     printf("%s", choices[i][0]);
                     i++;
                 } */

                break;

            case 3:

                // ProcessChoice(line);
                break;
            }
        }
    }

    printf("end of file");

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
    return chap;
}

#endif