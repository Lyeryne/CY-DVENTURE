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
#define SIZE 100000

int main(){
//VALUES
    srand(time(NULL));
    int nbr1, nbr2, nbr3, nbr4;
    int choice1;
    int verif = 1;
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
    
    FILE* fp2 = fopen("txt/WE.txt", "r"); //intro du WE
    char weekend[SIZE];
    if(fp2 == NULL){
        printf("Erreur on fopen\n");
        exit(1);
    }
    
    FILE* fp3 = fopen("txt/we1.txt", "r"); //choix 1 du WE
    char we1[SIZE];
    if(fp3 == NULL){
        printf("Erreur on fopen\n");
        exit(1);
    }
    
    FILE* fp4 = fopen("txt/we2.txt", "r"); //choix 2 du WE
    char we2[SIZE];
    if(fp4 == NULL){
        printf("Erreur on fopen\n");
        exit(1);
    }
    
    FILE* fp5 = fopen("txt/Rentrée.txt", "r"); //intro 
    char rentree[SIZE];
    if(fp5 == NULL){
        printf("Erreur on fopen\n");
        exit(1);
    }

    FILE* fp6 = fopen("txt/Rentrée1.txt", "r");
    char rentree1[SIZE];
    if(fp6 == NULL){
        printf("Erreur on fopen\n");
        exit(1);
    }

    FILE* fp7 = fopen("txt/Rentrée2.txt", "r");
    char rentree2[SIZE];
    if(fp7 == NULL){
        printf("Erreur on fopen\n");
        exit(1);
    }

    FILE* fp8 = fopen("txt/Rentrée3.txt", "r");
    char rentree3[SIZE];
    if(fp8 == NULL){
        printf("Erreur on fopen\n");
        exit(1);
    }
    
//GAME
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
    while(fgets(intro, SIZE, fp1) != NULL){ 
        int size1 = strlen(intro);
        displayTxt(size1, intro);
    }
    WaitPress();
    fclose(fp1);
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
    system("clear");
    
//GAME PART    
    while(fgets(weekend, SIZE, fp2) != NULL){
        int size4 = strlen(weekend);
        displayTxt(size4, weekend);   
    }  
    fclose(fp2);
    printf("Choix : "); 
    scanf("%d", &nbr1);

    //ROBUST
    system("clear");
    switch (nbr1){
    	case 1 :
    		while(fgets(we1, SIZE, fp3) != NULL){
        	    int size5 = strlen(we1);
        	    displayTxt(size5, we1);   
	        }
	        fclose(fp3);
	        sleep(2);
			system("clear");

			while(fgets(rentree, SIZE, fp5) != NULL){
	        	int size7 = strlen(rentree);
	        	displayTxt(size7, rentree);
	        }
	        fclose(fp5);
	        sleep(10);
	        printf("\n\n");


	        printf("Choix : ");
	        scanf("%d", &nbr2);
	        system("clear");
	        //ROBUST
	        while(nbr2 < 1 || nbr2 > 3){
	    	    printf("Mauvaise Saisie !\n\n");
	    	    printf("Choix : ");
	    	    scanf("%d", &nbr2);
	        }
			sleep(2);
	        system("clear");
	        switch (nbr2){
	    	    case 1 :
	                while(fgets(rentree1, SIZE, fp6) != NULL){
	        	        int size8 = strlen(rentree1);
	        	        displayTxt(size8, rentree1);
	                    /*sscanf(rentree3, "%s", main.name);
	                    fseek(fp8, 19, SEEK_CUR);//déplacement de 19 en partant du début
	                    fprintf(fp8, "%s ", main.name);*/
	                }
		            fclose(fp6);
		            sleep(2);
					system("clear");
		            break;
	            case 2 :
                	while(fgets(rentree2, SIZE, fp7) != NULL){
        	    	    int size9 = strlen(rentree2);
        	    	    displayTxt(size9, rentree2);
                	    /*sscanf(rentree3, "%s", main.name);
                	    fseek(fp8, 19, SEEK_CUR);//déplacement de 19 en partant du début
                	    fprintf(fp8, "%s ", main.name);*/
                	}            
            		fclose(fp7);
            	sleep(2);
				system("clear");
       	     	break;
        	    case 3 :
        	        while(fgets(rentree3, SIZE, fp8) != NULL){
        		        int size10 = strlen(rentree3);
        		        displayTxt(size10, rentree3);	
        	            /*sscanf(rentree3, "%s", main.name);
            	        fseek(fp8, 19, SEEK_CUR);//déplacement de 19 en partant du début
                	    fprintf(fp8, "%s ", main.name);*/
                	}
            		fclose(fp8);
            		sleep(2);
					system("clear");
            		break;
        	}
		system("clear");
        break; 

        case 2 :
        	while(fgets(we2, SIZE, fp4) != NULL){
        		int size6 = strlen(we2);
        		displayTxt(size6, we2);
            }
        	fclose(fp4);
        	sleep(2);
			system("clear");
        	break;

        default:
        	printf("Mauvaise saisie\n");
        	printf("Choix : ");
        	scanf("%d", &nbr1);
        	break;
    }

return 0;
}

