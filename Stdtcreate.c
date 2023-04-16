#ifndef STDTCREATE_H
#define STDTCREATE_H

#include<ctype.h> // pour la fonction isdigit()
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include"Robust.c"
#include"DisplayTXT.c"
#define SIZE_NAMES 100

typedef struct{
    char name[SIZE_NAMES];
    char sname[SIZE_NAMES];
    int fame;
    int power;
    int intellect;
}Student;//Main character + fighter character


Student createStudent(){
//VARIABLES
    Student x;
    int num1, num2;
//CREATE STUDENT
    printf("Saisir le nom de l'eleve :");
    scanf("%s", x.name);
    num1 = strlen(x.name);
    while(num1>=SIZE_NAMES || (is_char(x.name)==0)){//ROBUST
        printf("Mauvaise saisie ou saisie trop longue !\n");
        sleep(1);
        system("clear");
        printf("Saisir a nouveau le nom de l'eleve :");
        scanf("%s", x.name);
        num1 = strlen(x.name);
    }
    //DISPLAY BETTER NAME
    if(x.name[0] >= 'a' && x.name[0] <= 'z'){
        x.name[0] = toUpper(x.name[0]);
    }
    int j=1;
    while(x.name[j] != '\0'){
        if(x.name[j] >= 'A' && x.name[j] <= 'Z'){
        x.name[j] = toLower(x.name[j]);
        }
        j++;
    }

    printf("Saisir le nom de famille de l'eleve :");
    scanf("%s", x.sname);
    num2 = strlen(x.sname);
    while(num2>SIZE_NAMES || is_char(x.sname) == 0){//ROBUST
        printf("Mauvaise saisie ou saisie trop longue !\n");
        sleep(1);
        system("clear");
        printf("Saisir à nouveau le nom de famille l'eleve :");
        scanf("%s", x.sname);
        num2 = strlen(x.sname);
    }
    //DISPLAY BETTER SNAME
    if(x.sname[0] >= 'a' && x.sname[0] <= 'z'){
        x.sname[0] = toUpper(x.sname[0]);
    }
    j=1;
    while(x.sname[j] != '\0'){
        if(x.sname[j] >= 'A' && x.sname[j] <= 'Z'){
        x.sname[j] = toLower(x.sname[j]);
        }
        j++;
    }
    
    x.power = 50 + rand()%51;
    x.fame = 50;
    x.intellect = 50 + rand()%51;

return x;
}

void displayStd(Student a){
    char* txt1 = "Description de votre personnage principal \n\n";
    int size1 = strlen(txt1);
    displayTxt(size1, txt1);
    printf("[%s %s]\n", a.name, a.sname);
    printf("Reputation : %d\n", a.fame);
    printf("Intelligence : %d\n", a.intellect);
    printf("Force : %d", a.power);
}
/*void displayStdF(Std b){
    int delay = 20;
    char* txt2 = "Description de votre potentielle concurrent:\n\n";
    int size2 = strlen(txt2);
    for(int i=0; i<size2; i++){
        printf("%c", txt2[i]);
        fflush(stdout);
        struct timespec attente = {0, delay*1000000};
        nanosleep(&attente, NULL);
    }
    printf("[%s %s]\n", b.name, b.sname);
    printf("Reputation : %d\n", b.fame);
    printf("Intelligence : %d\n", b.intellect);
    printf("Force : %d\n", b.power);
}*/

#endif

