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

void SaveGame(SaveData data){
    FILE* fp = fopen("txt/save.txt", "w");
    if(fp == NULL){
        printf("Erreur fopen (file Save)\n");
        exit(1);
    }

    //STAT
    fprintf(fp, "%d\n", data.a.fame);
    fprintf(fp, "%d\n", data.a.power);
    fprintf(fp, "%d\n", data.a.intellect);
    fprintf(fp, "%d\n", data.a.wellness);
    fprintf(fp, "%d\n", data.a.health);
    fprintf(fp, "%d\n", data.a.dodge);
    fprintf(fp, "%d\n", data.a.defence);
    //BAG
    Bag myBag[] = {Pencil, Book, Computer, Knife, Knuckles, Sunglasses, Jacket, Girlfriend};
    int numItems = sizeof(myBag) / sizeof(myBag[0]);

    fprintf(fp, "Bag items:\n");
    for(int i = 0; i < numItems; i++) {
        fprintf(fp, "- %s\n", enum2string(data.b[i]));
    }
    //CHOICES
    fprintf(fp, "selected_choice:%d\n", data.selected_choice);

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

    int i = 0; // compteur d'éléments de sac lus
    Bag item;
    while (fgets(line, sizeof(line), fp) != NULL) {
        line[strcspn(line, "\r\n")] = '\0'; // Supprimer le retour chariot
        item = string2enum(line + 2); // Ignorer le préfixe "- "
        if (i >= MAX_BAG_SIZE) {
            printf("Le nombre d'éléments de sac dépasse la taille du tableau\n");
            fclose(fp);
            return 0;
        }
        b[i++]= item;
    }


    char line[1000];
    if (fgets(line, sizeof(line), fp) != NULL &&
        sscanf(line, "selected_choice:%d", &(chap->selected_choice)) == 1) {
        // Le choix de l'utilisateur a été trouvé et chargé
    } else {
        // Aucune information sur le choix de l'utilisateur n'a été trouvée dans le fichier de sauvegarde
    }
    fclose(fp);
    return 1;
}

#endif