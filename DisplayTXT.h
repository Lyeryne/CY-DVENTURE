#ifndef DISPLAYTXT_H
#define DISPLAYTXT_H

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<stdbool.h>

#include "Process.h"
#include "Stdtcreate.h"

#define SIZE_LINE 10000
#define MAX_CHOICE 10


void displayTxt(int size, char* txt){
//afficher .txt lettre par lettre avec un petit délai entre chaque lettre, ~> impression de temps réel
	int delay1 = 0;//simuler l'effet de défilement(en ms) 
	for(int i=0; i<size; i++){
		printf("%c", txt[i]);
		fflush(stdout);//force l'affichage du caractère sur la sortie standard avant de passer à la lettre suivante
		struct timespec attente ={0, delay1*1000000};//attendre le délai spécifié entre chaque lettre
		nanosleep(&attente, NULL);// permet de mettre en pause l'exécution du programme pendant une durée donnée(ici en delay1)
	}
}

void WaitPress(){
	char e;// stocke la touche pressée par l'utilisateur
	printf("\n\n~~ Appuyez sur entree pour continuer ~~ ");
	while (e != '\n' && e  != '\r') {// tant que la touche pressée n'est pas Entrée  
		e = getchar();//lit un caractère depuis l'entrée standard (clavier)
	}
}


#endif
