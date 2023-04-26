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
	int delay1 = 35; 
	for(int i=0; i<size; i++){
		printf("%c", txt[i]);
		fflush(stdout);
		struct timespec attente ={0, delay1*1000000};
		nanosleep(&attente, NULL);
	}
}

void WaitPress(){
	char e;
	printf("\n\n~~ Appuyez sur entree pour continuer ~~ ");
	while (e != '\n' && e  != '\r') {  
		e = getchar();
	}
	system("clear");
}

#endif
