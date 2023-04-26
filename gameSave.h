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
    fprintf(fp, "%d\n", b.fame);
    fprintf(fp, "%d\n", b.power);
    fprintf(fp, "%d\n", b.intellect);
    fprintf(fp, "%d\n", b.wellness);

    fclose(fp);
}

#endif