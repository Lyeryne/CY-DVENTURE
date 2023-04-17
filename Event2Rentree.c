#ifndef EVENT2RENTREE_H
#define EVENT2RENTREE_H


#include<ctype.h>
#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include"DisplayTXT.c" // fonction affichant caractère par caractère
#define SIZE 100000

void Event2(){
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
    // affichage du choix de groupe a selectionner
    while(fgets(rentree, SIZE, fp5) != NULL){
	    int size7 = strlen(rentree);
	    displayTxt(size7, rentree);
	}
    fclose(fp5);
    system("clear");
    int c = choice(3);
    switch(c){
        case 1:
            while(fgets(rentree1, SIZE, fp6) != NULL){
	        	int size8 = strlen(rentree1);
	        	displayTxt(size8, rentree1);
	                    /*sscanf(rentree3, "%s", main.name);
	                    fseek(fp8, 19, SEEK_CUR);//déplacement de 19 en partant du début
	                    fprintf(fp8, "%s ", main.name);*/
            }
        fclose(fp6);
        break;
        case 2: 
            while(fgets(rentree2, SIZE, fp7) != NULL){
        	    int size9 = strlen(rentree2);
        	    displayTxt(size9, rentree2);
                /*sscanf(rentree3, "%s", main.name);
                fseek(fp8, 19, SEEK_CUR);//déplacement de 19 en partant du début
                fprintf(fp8, "%s ", main.name);*/
            }            
            fclose(fp7);
            break;
        case 3:
            while(fgets(rentree3, SIZE, fp8) != NULL){
        		int size10 = strlen(rentree3);
        		displayTxt(size10, rentree3);	
        	    /*sscanf(rentree3, "%s", main.name);
            	fseek(fp8, 19, SEEK_CUR);//déplacement de 19 en partant du début
                fprintf(fp8, "%s ", main.name);*/
            }
            fclose(fp8);
            break;
    }
}


#endif