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

#endif