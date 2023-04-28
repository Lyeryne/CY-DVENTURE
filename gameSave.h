#ifndef GAMESAVE_H
#define GAMESAVE_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stdtcreate.h"

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
    fprintf(fp, "%d\n", Pencil);
    fprintf(fp, "%d\n", Book);
    fprintf(fp, "%d\n", Computer);
    fprintf(fp, "%d\n", Knife);
    fprintf(fp, "%d\n", Knuckles);
    fprintf(fp, "%d\n", Sunglasses);
    fprintf(fp, "%d\n", Jacket);
    fprintf(fp, "%d\n", Girlfriend);

    fclose(fp);
}

#endif