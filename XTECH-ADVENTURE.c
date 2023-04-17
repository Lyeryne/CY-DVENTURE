#include<ctype.h>
#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include"Stdtcreate.c" //appelle une partie d'un programme qui creer l'étudiant
#include"Robust.c" // appelle fonctions robust
#include"DisplayTXT.c" // fonction affichant caractère par caractère
#include"Event1WE.c"
#include"Event2Rentree.c"
#define SIZE 1000000

int main(){
//VALUES
    srand(time(NULL));
    int pourcentage;
    int delay1 = 35; // temps de délai en millisecondes
    Student main;
//CREATION DE FICHIER
    FILE* fp1 = fopen("txt/Intro.txt", "r");
    char intro[SIZE];
    if(fp1 == NULL){
        printf("Erreur on fopen\n");
        exit(1);
    }

//GAME
    system("clear");
    printf("Webtoon MI5\n");
    sleep(2);
    char* txt = "Produit par\n-> Louaye SAGHIR\n-> Clement PREMOLI\n-> Roman BOULLIER\n\n";
    int size = strlen(txt);
    //affiche le texte lettre par lettre avec la fonction displayTXT
    displayTxt(size, txt);  
    sleep(1);
    system("clear");
    //affichage de pourcentage en temps réelle
    for(pourcentage = 0; pourcentage <= 100; pourcentage+=4) {
        printf("LANCEMENT DU JEU... %d%%\r", pourcentage); // \r permet de revenir en début de ligne
        fflush(stdout); // force l'affichage immédiat du texte
        usleep(100000); // suspend l'exécution du programme pendant 100000 microsecondes (0,1 seconde)
    }
    printf("Chargement fini !\n");
    sleep(1);
    system("clear");
    //affiche le message d'introduction/explication du jeu
    while(fgets(intro, SIZE, fp1) != NULL){ 
        int size1 = strlen(intro);
        displayTxt(size1, intro);
    }
    //libère la mémoire tampon en fermant le fichier
    fclose(fp1);
    //attend que l'utilisateur continue
    WaitPress();


//CREATE STUDENTS
    char* txt1 = "Avant de commencer a jouer, vous allez saisir votre personnage principal\n\n";
    int size2 = strlen(txt1);
    displayTxt(size2, txt1);//Affichage de Txt1
    Student mainCharacter = createStudent();
    displayStd(mainCharacter);
    sleep(2);

    char* txt2 = "Commençons...\n";
    sleep(1);
    int size3 = strlen(txt2);
    displayTxt(size3, txt2);
    sleep(2);
    system("clear");  

    Event1();
return 0;
}

