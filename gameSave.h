#ifndef GAMESAVE_H
#define GAMESAVE_H

#include <time.h>
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

void SaveGame(Stdt a, Bag b){
    FILE* fp = fopen("txt/save.txt", "w");
    if(fp == NULL){
        printf("Erreur fopen (file Save)\n");
        exit(1);
    }

    //STAT
    fprintf(fp, "%d\n", a.fame);
    fprintf(fp, "%d\n", a.power);
    fprintf(fp, "%d\n", a.intellect);
    fprintf(fp, "%d\n", a.wellness);
    fprintf(fp, "%d\n", a.health);
    fprintf(fp, "%d\n", a.dodge);
    fprintf(fp, "%d\n", a.defence);
    //BAG
    Bag myBag[] = {Pencil, Book, Computer, Knife, Knuckles, Sunglasses, Jacket, Girlfriend};
    int numItems = sizeof(myBag) / sizeof(myBag[0]);

    fprintf(fp, "Bag items:\n");
    for(int i = 0; i < numItems; i++) {
        fprintf(fp, "- %s\n", enum2string(myBag[i]));
    }
    //CHOICES
    //fprintf(fp, "%s\n", fillChoice()); //'currentChoiceInd', variable de suivi pour le choix actuel


    fclose(fp);
}

int loadGame(Stdt* main, Bag* b) {
    FILE* fp = fopen("txt/save.txt", "r");
    if (fp == NULL) {
        printf("Erreur fopen (file LoadSave)\n");
        exit(1);
    }

    //STAT
    if (fscanf(fp, "%d", &(main->fame)) != 1 ||
        fscanf(fp, "%d", &(main->power)) != 1 ||
        fscanf(fp, "%d", &(main->intellect)) != 1 ||
        fscanf(fp, "%d", &(main->wellness)) != 1 || 
        fscanf(fp, "%d", &(main->health)) != 1 ||
        fscanf(fp, "%d", &(main->dodge)) != 1 ||
        fscanf(fp, "%d", &(main->defence)) != 1) {
        printf("Erreur de lecture des données de stat\n");
        fclose(fp);
        return 0;
    }

    //BAG
    char line[128];
    if (fgets(line, sizeof(line), fp) == NULL ||
        strcmp(line, "Bag items:\n") != 0) {
        printf("Erreur de lecture de l'en-tête de la liste de sac\n");
        fclose(fp);
        return 0;
    }

    Bag item;
    while (fgets(line, sizeof(line), fp) != NULL) {
        line[strcspn(line, "\r\n")] = '\0'; // Supprimer le retour chariot
        item = string2enum(line + 2); // Ignorer le préfixe "- "
        if (item == Error) {
            printf("Erreur de lecture d'un élément de sac\n");
            fclose(fp);
            return 0;
        }
        *b |= item;
    }

    fclose(fp);
    return 1;
}

#endif