#ifndef DISPLAYTXT_H
#define DISPLAYTXT_H

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

void displayTxt(int size, char* txt){
//afficher .txt lettre par lettre avec un petit délai entre chaque lettre, ~> impression de temps réel
	int delay1 = 35;//simuler l'effet de défilement(en ms) 
	for(int i=0; i<size; i++){
		printf("%c", txt[i]);
		fflush(stdout);//force l'affichage du caractère sur la sortie standard avant de passer à la lettre suivante
		struct timespec attente ={0, delay1*1000000};//attendre le délai spécifié entre chaque lettre
		nanosleep(&attente, NULL);// permet de mettre en pause l'exécution du programme pendant une durée donnée(ici en delay1)
	}
}

char* fill_text_property(char * buf, char * value)
//=>permet de remplir une propriété de type char * (%s) d'une structure de manière dynamique
{
    int length;
    printf("%s", value); //affiche la description ligne par ligne
    if (buf == NULL) // propriété n'est pas initialisée
    { 
        length = strlen(value)+1;
        buf = (char *)malloc(length * sizeof(char));//allocation pour stocker 'value' et copie cette valeur dans 'buf'
        strcpy(buf, value);//copier la %s 'value' dans le tampon 'buf'
    }
    else{ //propriété est déjà initialisée
        length = strlen(buf) + strlen(value)+1;
        char * temp = (char *)realloc(buf, length * sizeof(char));
        //allocation pour stocker la valeur déjà présente dans 'buf' et la valeur à ajouter (value)
        if(temp != NULL){
            buf = temp;//affecte le * 'temp' à 'buf'
        }
        strcat(buf, value); //concatenation de 'value' à la propriété 'buf'
    }    

    return buf;
}

void WaitPress(){
	char e;// stocke la touche pressée par l'utilisateur
	printf("\n\n~~ Appuyez sur entree pour continuer ~~ ");
	while (e != '\n' && e  != '\r') {// tant que la touche pressée n'est pas Entrée  
		e = getchar();//lit un caractère depuis l'entrée standard (clavier)
	}
}

#endif
