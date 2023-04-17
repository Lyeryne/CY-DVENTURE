#include<ctype.h>
#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include"DisplayTXT.c" // fonction affichant caractère par caractère











// affichage du choix de groupe a selectionner
while(fgets(rentree, SIZE, fp5) != NULL){
	        	int size7 = strlen(rentree);
	        	displayTxt(size7, rentree);
	        }