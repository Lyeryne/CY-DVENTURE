#include "DisplayTXT.h"

void displayTxt(int size, char* txt)
{
//afficher .txt lettre par lettre avec un petit délai entre chaque lettre, ~> impression de temps réel
	int delay1 = 0;//simuler l'effet de défilement(en ms) 
	for(int i=0; i<size; i++){
		printf("%c", txt[i]);
		fflush(stdout);//force l'affichage du caractère sur la sortie standard avant de passer à la lettre suivante
		struct timespec attente ={0, delay1*1000000};//attendre le délai spécifié entre chaque lettre
		nanosleep(&attente, NULL);// permet de mettre en pause l'exécution du programme pendant une durée donnée(ici en delay1)
	}
}

void displayLoading()
{
  int pourcentage = 0;
  for(pourcentage = 0; pourcentage <= 100; pourcentage+=20) {
        printf("LANCEMENT DU JEU... %d%%\r", pourcentage); // \r permet de revenir en début de ligne
        fflush(stdout); // force l'affichage immédiat du texte
        usleep(100000); // suspend l'exécution du programme pendant 100000 microsecondes (0,1 seconde)
    }
    printf("Chargement fini !\n");
    sleep(1);
    system("clear");
}

void WaitPress()
{
    printf("Press Enter to continue...\n");
    while (getchar() != '\n');
}


