#include<ctype.h>
#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

int Event1(int choix1){
    while(fgets(weekend, SIZE, fp2) != NULL){
        int size4 = strlen(weekend);
        displayTxt(size4, weekend);   
    }  
    fclose(fp1);
    printf("Veux-tu y aller ?\n Oui(1) ou Non(2)");
    scanf("%s")
    switch(choix1){
        case 1:
            //Choix d'aller au weekend d'inté accepté
    		while(fgets(we1, SIZE, fp3) != NULL){
        	    int size5 = strlen(we1);
        	    displayTxt(size5, we1);   
	        }
            fclose(fp3);
            WaitPress();
        case 2:
            //Choix d'aller au weekend d'inté refusé
            while(fgets(we2, SIZE, fp4) != NULL){
        		int size6 = strlen(we2);
        		displayTxt(size6, we2);
            }
            fclose(fp4);
            Waitpress();
    // afficher message de fin d'event de weekend d'intégration :
    // -->
}
}