#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Robust.h"
#include "Stdtcreate.h"
#include "statPlayer.h"

static const char part_seperator[] = "###";
struct Choice;
struct chapter;
struct SaveData;
struct Stdt;
struct Bag;

 int pre_game(){
   int start, lu;
    system("clear");
    /*printf("Webtoon MI5\n");
    sleep(1);
    char* txt = "Produit par\n-> Louaye SAGHIR\n-> Clement PREMOLI\n-> Roman BOULLIER\n\n";
    int size = strlen(txt);
    displayTxt(size, txt);  
    sleep(1);
    system("clear");*/
    //Choix de partie
    printf("========= MENU ========\n");//ASCI ART
    printf(" 1 -> Nouvelle Partie\n");//ASCI ART
    printf(" 2 -> Reprendre Partie\n");//ASCI ART
    printf(" 3 -> Quitter le Jeu\n\n");//ASCI ART
	printf("Choix :");
	lu = scanf("%d", &start);
    while(start < 1 && start > 3 && lu == 0){
        fflush(stdin);
        printf("Entrez votre choix : ");
        scanf("%d", &start);
    }
    sleep(1);
    system("clear");

  return start;
 }
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
    {
        // Si la liste des choix est vide (== NULL)
        chap->choice_count = 0;
	    chap->choices = (Choice*)malloc(sizeof(Choice)); // allocation d'un choix
    }
    else
    {
        Choice *temp = (Choice*)realloc(chap->choices, (chap->choice_count + 1) * sizeof(Choice));
        // allocation d'un choix supplémentaire avec 'realloc' pour augmenter la taille de la liste des choix.
        if (temp != NULL)
        {
            chap->choices = temp;
        }
    }
    Choice ch = {};
    char delim[] = "_";
    char *cutteds = strtok(value, delim);
    int i = 0;
    while (cutteds != NULL)
    {
        if (i == 0)
        {
            ch.text = set_text_property(ch.text, cutteds);
            printf("\n");
        }
        else
        {
            cutteds[strlen(cutteds) - 1] = '\0';
            ch.nextChapter = set_text_property(ch.nextChapter, cutteds);
        }
        cutteds = strtok(NULL, delim);
        i++;
    }

    chap->choices[chap->choice_count] = ch;
    chap->choice_count++;

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
                break;

            case 3:
                ProcessChoice(&chap, line);
                break;
            }
        }
    }
    fclose(file);

    return chap;
}

char* displayChapter(chapter chap)
{
    Bag b;
    int lu;
    int user_choice = 0, count = 0;
    printf("%s", chap.description);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~XTECH DVENTURE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    for (int i = 0; i < chap.choice_count; i++)
    {
        printf("\n%s", chap.choices[i].text);
    }
    //event
    do
    {
        printf("Choix : ");
        lu = scanf("%d", &user_choice);
        fflush(stdin);
        if (choice(user_choice) || (user_choice < 1 || user_choice > chap.choice_count))
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
