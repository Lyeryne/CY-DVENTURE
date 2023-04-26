#ifndef GAMESAVE_H
#define GAMESAVE_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stdtcreate.h"

void SaveGame(Stdt *user){
    char *ext=".txt",*debut=user->nom,*fichierdesauvegarde=0;
    FILE* fichier=NULL;
    fichierdesauvegarde=strcat(debut,ext);
    fichier=fopen(fichierdesauvegarde,"r");
    if(fichier!=NULL)
    {
        fclose(fichier);
        remove(fichierdesauvegarde);
    }
    fopen(fichierdesauvegarde,"a");
    if(fichier==NULL)
    {
        ecrire("Il y a une erreur dans la création du fichier de sauvegarde !");
        system("PAUSE");
        exit(0);
    }
    else
    {
        fprintf(fichier,"%s\n%d\n%d\n",user->nom,user->nombrepotions,user->disttot);
        fprintf(fichier,"%d\n%d\n%d\n",user->ptsdemouvementtot,user->ptsdemouvement,user->niveau);
        fprintf(fichier,"%d\n%d\n%d\n%d\n",user->exp,user->butin,user->viemax,user->vie);
        fprintf(fichier,"%d\n%d\n%d\n%d\n%d\n",user->DIST,user->CAC,user->defense,user->magie,user->vitesse);
    }
}

#endif