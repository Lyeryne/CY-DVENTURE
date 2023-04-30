#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "DisplayTXT.h"

#define SIZE_LINE 10000
#define MAX_CHOICE 10

static const char part_seperator[] = "###";
struct choice;

typedef struct
{
    char *description;
    char *event;
    struct choice *choices;
    int choice_count;
} chapter;

typedef struct choice
{
    char *text;
    char *nextChapter;
} choice;

char *set_text_property(char *buf, char *value)
//=>permet de remplir une propriété de type char * (%s) d'une structure de manière dynamique
{
    int length;
    if (buf == NULL) // propriété n'est pas initialisée
    {
        length = strlen(value) + 1;
        buf = (char *)malloc(length * sizeof(char)); // allocation pour stocker 'value' et copie cette valeur dans 'buf'
        strcpy(buf, value);                          // copier la %s 'value' dans le tampon 'buf'
    }
    else
    { // propriété est déjà initialisée
        length = strlen(buf) + strlen(value) + 1;
        char *temp = (char *)realloc(buf, length * sizeof(char));
        // allocation pour stocker la valeur déjà présente dans 'buf' et la valeur à ajouter (value)
        if (temp != NULL)
        {
            buf = temp; // affecte le * 'temp' à 'buf'
        }
        strcat(buf, value); // concatenation de 'value' à la propriété 'buf'
    }

    return buf;
}


void ProcessDescription(chapter *chap, char *value)
{
    chap->description = set_text_property(chap->description, value);
    // remplit une chaîne de caractères tout en s'assurant que la mémoire allouée est suffisante
    //=> assigner une description(avec la valeur de 'value') à un chapitre
}

void ProcessEvent(chapter *chap, char *value)
{
    chap->event = set_text_property(chap->event, value);
    // remplit event de la struct chapter avec la %s 'value' en utilisant 'fill_text_property'
    //=> ajouter des événements
}

void ProcessChoice(chapter *chap, char *value)
// =>Ce code est une fonction qui ajoute une option de choix à un chapitre d'une histoire interactive
{
    if (chap->choices == NULL)
    { // gère la mémoire allouée pour stocker les choix dans la structure chapter
        // Si la liste des choix est vide (== NULL)
        chap->choice_count = 0;
        chap->choices = (choice *)malloc(1 * sizeof(choice)); // alors un choix est alloué
    }
    else
    {
        choice *temp = (choice *)realloc(chap->choices, (chap->choice_count + 1) * sizeof(choice));
        // Sinon, un choix supplémentaire est alloué avec 'realloc' pour augmenter la taille de la liste des choix.
        if (temp != NULL)
        {
            chap->choices = temp;
        }
    }
    choice ch = {};
    // analyse la chaîne de caractères value en utilisant le délimiteur '_' et extrait chaque partie de la %s
    char delim[] = "_";
    char *cutteds = strtok(value, delim); // séparer la chaîne value en sous-chaînes en utilisant ces délimiteurs
    int i = 0;
    while (cutteds != NULL)
    // parcourt toutes les sous-chaînes et pour chaque sous-chaîne, elle fait une action différente en fonction de son index 'i'
    {
        if (i == 0) // nous remplissons la propriété text de notre choix avec la première sous-chaîne
        {
            ch.text = set_text_property(ch.text, cutteds);
            printf("\n");
        }
        else
        { // nous créons un nouveau chapitre en utilisant la sous-chaîne courante
            cutteds[strlen(cutteds) - 1] = '\0';
            ch.nextChapter = set_text_property(ch.nextChapter, cutteds);
            //ch.nextChapter = create_chapter(cutteds);
        }
        cutteds = strtok(NULL, delim);
        i++;
    }

    // ajoutons le choix 'ch' à la liste des choix dans le chapter actuel 'chap' en l'ajoutant à l'ind 'chap->choice_count' de la liste
    chap->choices[chap->choice_count] = ch; // incrémenter la valeur de 'chap->choice_count'
    chap->choice_count++;

    // gère le choix
    /*  int next_step, i = 0;

     char *cutteds = strtok(string, delim);
     while (cutteds != NULL)
     {
         choice1[i] = cutteds;
         cutteds = strtok(NULL, delim);
         i++;
     }

     printf("%s", choice1[string[0] - 1]); */
}

chapter create_chapter(char *chapter_name)
{
    // VARIABLES
    char line[SIZE_LINE];

    int currentPart = 0;
    char *path = (char *)malloc((strlen("txt/") + strlen(chapter_name) + strlen(".txt")) * sizeof(char) + 1);
    //~~> contien le chemin d'accès au fichier txt que nous voulons ouvrir

    strcpy(path, "txt/");       // copie la chaîne 'txt' dans chaîne 'path'
    strcat(path, chapter_name); // suivie de 'chapter_name'(concaténation)
    strcat(path, ".txt");       // et de '.txt'

    FILE *file = fopen(path, "r");
    // crée un chemin vers le fichier txt à partir du nom du chapitre et stocke dans 'path'

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
        strncat(first_line_chars, line, 3); // extrait les 3 premiers caractères en les stockant dans 'first_line_chars'
        if (strcmp(first_line_chars, part_seperator) == 0)
        // Si ces 3 premiers caractères correspondent à 'part_seperator'
        {
            // Alors currentPart est incrémentée
            currentPart++;
        }
        else // Sinon utilisé pour traiter la ligne en fonction de la valeur de 'currentPart'
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
    fclose(file);

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


char* displayChapter(chapter chap)
{
    int lu;
    int user_choice = 0, count = 0;
    printf("%s", chap.description);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~XTECH DVENTURE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    for (int i = 0; i < chap.choice_count; i++)
    {
        printf("\n%s", chap.choices[i].text);
    }
    do
    {
        printf("\nChoix : ");
        lu = scanf("%d", &user_choice);
        fflush(stdin);
        if (user_choice < 1 || user_choice > chap.choice_count)
        {
            printf("Veuillez saisir une reponse valide : ");
        }
        else
        {
            count = 1;
        }
    }while(lu == 0 || count == 0);
return chap.choices[user_choice - 1].nextChapter;
}

#endif
