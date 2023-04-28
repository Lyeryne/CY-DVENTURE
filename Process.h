#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DisplayTXT.h"
#include "structChoice.h"
#include "Process.h"
#include "Stdtcreate.h"
#include "statPlayer.h"
#include "gameSave.h"
#include "Chapter.h"


void ProcessDescription(chapter *chap, char *value)
{   
    chap->description = fill_text_property(chap->description, value); 
    //remplit une chaîne de caractères tout en s'assurant que la mémoire allouée est suffisante
    //=> assigner une description(avec la valeur de value) à un chapitre
}

void ProcessEvent(chapter *chap, char *value)
{
    chap->event = fill_text_property(chap->event, value) ; 
    // remplit event de la struct chapter avec la %s value en utilisant la fonction fill_text_property. 
    //=> ajouter des événements
}

void ProcessChoice(chapter *chap, char *value)
// =>Ce code est une fonction qui ajoute une option de choix à un chapitre d'une histoire interactive.
{   
    if (chap->choices == NULL) { //gère la mémoire allouée pour stocker les choix dans la structure chapter
        //Si la liste des choix est vide (== NULL)
        chap->choice_count = 0;
        chap->choices = (choice *)malloc(1 * sizeof(choice));// alors un choix est alloué
    }
    else {
        choice *temp = (choice *)realloc(chap->choices, (chap->choice_count + 1) * sizeof(choice));
        //Sinon, un choix supplémentaire est alloué en utilisant realloc pour augmenter la taille de la liste des choix.
        if (temp != NULL) {
            chap->choices = temp;
        }
    }

        
    choice ch = {};
    //analyse la chaîne de caractères value en utilisant le délimiteur '_' et extrait chaque partie de la %s
    char delim[] = "_";
    char *cutteds = strtok(value, delim); //séparer la chaîne value en sous-chaînes en utilisant ces délimiteurs
    chapter *nextChapter = NULL;
    chapter *lastChapter = NULL;
    int i=0;
    while (cutteds != NULL)
    //parcourt toutes les sous-chaînes et pour chaque sous-chaîne, elle fait une action différente en fonction de son index 'i'
    {   
        if (i == 0)//nous remplissons la propriété text de notre choix avec la première sous-chaîne
        {
            ch.text = fill_text_property(ch.text, cutteds);
        }
        else {//nous créons un nouveau chapitre en utilisant la sous-chaîne courante
            cutteds[strlen(cutteds) - 1] = '\0';  
            nextChapter = &create_chapter(cutteds);
            if (lastChapter == NULL) {
                ch.nextChapter = nextChapter;
            }
            else {
                nextChapter->lastChapter = nextChapter;
                //nous configurons la propriété nextChapter du choix actuel 'ch' pour * vers ce nouveau chapter
            }
            lastChapter = nextChapter;//&& la propriété 'lastChapter' du nouveau chapter pour * vers le choix actuel 'ch'
        }
        cutteds = strtok(NULL, delim);
        i++;
    }
    //ajoutons le choix 'ch' à la liste des choix dans le chapter actuel 'chap' en l'ajoutant à l'ind 'chap->choice_count' de la liste
    chap->choices[chap->choice_count] = ch;//incrémenter la valeur de 'chap->choice_count'
    chap->choice_count ++;

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

#endif