#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "Process.h"
#include "Stdtcreate.h"
#include "DisplayTXT.h"

#define SIZE 100000

int main()
{
//VALUES
    srand(time(NULL));
    int nbr1, nbr2, nbr3, nbr4;
    int choice1;
    int verif = 1;
    int pourcentage;
    int delay1 = 35;
    Stdt main;
//CREATION DE FICHIER
    FILE* fp1 = fopen("../txt/DebutJeu.txt", "r");
    char intro[SIZE];
    if(fp1 == NULL){
        printf("Erreur on fopen\n");
        exit(1);
    }
//PRE-GAME
    system("clear");
    /*printf("Webtoon MI5\n");
    sleep(1);
    char* txt = "Produit par\n-> Louaye SAGHIR\n-> Clement PRIMOLI\n-> Roman BOULLIER\n\n";
    int size = strlen(txt);
    displayTxt(size, txt);  
    sleep(1);
    system("clear");
    //affichage de %tage en temps réelle
    for(pourcentage = 0; pourcentage <= 100; pourcentage+=20) {
        printf("LANCEMENT DU JEU... %d%%\r", pourcentage); // \r permet de revenir en début de ligne
        fflush(stdout); // force l'affichage immédiat du texte
        usleep(100000); // suspend l'exécution du programme pendant 100000 microsecondes (0,1 seconde)
    }
    printf("Chargement fini !\n");
    sleep(1);
    system("clear");
    while(fgets(intro, SIZE, fp1) != NULL){ 
        int size1 = strlen(intro);
        displayTxt(size1, intro);
    }
    WaitPress();
    fclose(fp1);
    system("clear");
//CREATE STUDENTS
    char* txt1 = "Avant de commencer a jouer, vous allez saisir votre personnage principal\n\n";
    int size2 = strlen(txt1);
    displayTxt(size2, txt1);//Affichage de Txt1   

    Stdt mainCharacter = createStudent();
    system("clear");
    displayStdt(mainCharacter);
    sleep(2);
    system("clear");

    char* txt2 = "Commençons...\n";
    int size3 = strlen(txt2);
    displayTxt(size3, txt2);
    sleep(2);
    system("clear");*/
//VARIABLES 
    int game = 1;
    char* next_chap1;
    char* next_chap2;
    chapter ch1 = create_chapter("Event1");
    chapter ch2 = create_chapter("Event2");

//GAME
    while (game == 1)
    {

        //strcpy(next_chap, displayChapter(ch));
	
        next_chap1= displayChapter(ch1);
        ch1 = create_chapter(next_chap1);

	next_chap2= displayChapter(ch2);
        ch2 = create_chapter(next_chap2);
	


    }
    return 0;
}


