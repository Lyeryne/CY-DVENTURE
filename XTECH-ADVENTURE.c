#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#include "DisplayTXT.h"
#include "structChoice.h"
#include "Process.h"
#include "Stdtcreate.h"
#include "statPlayer.h"
#include "gameSave.h"
#include "Chapter.h"

#define SIZE_LINE 10000
#define MAX_CHOICE 10


int main()
{
    //VALUES
    srand(time(NULL));
    int nbr1, nbr2, nbr3, nbr4;
    int choice1;
    int verif = 1;
    int pourcentage;
    int delay1 = 35; // temps de délai en millisecondes
    system("clear");
    printf("Webtoon MI5\n");
    sleep(2);
    char* txt = "Produit par\n-> Louaye SAGHIR\n-> Clement PRIMOLI\n-> Roman BOULLIER\n\n";
    int size = strlen(txt);
    displayTxt(size, txt);  
    sleep(1);
    system("clear");
    //affichage de %tage en temps réelle
    for(pourcentage = 0; pourcentage <= 100; pourcentage+=4) {
        printf("LANCEMENT DU JEU... %d%%\r", pourcentage); // \r permet de revenir en début de ligne
        fflush(stdout); // force l'affichage immédiat du texte
        usleep(100000); // suspend l'exécution du programme pendant 100000 microsecondes (0,1 seconde)
    }
    printf("Chargement fini !\n");
    sleep(1);
    system("clear");

    //GAME
    create_chapter("Introduction");

    return 0;
}
