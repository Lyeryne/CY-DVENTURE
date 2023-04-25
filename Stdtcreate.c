#ifndef STDTCREATE_H
#define STDTCREATE_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_NAMES 100

typedef struct{
  char name[SIZE_NAMES];
  char sname[SIZE_NAMES];
  int fame;                    
  int power;
  int intellect;
  int wellness;
} Stdt; // Main character

typedef enum{
  //intellect stuff
  Pencil, Book, Computer,
  //power stuff
  Knife, Knuckles, 
  //fame stuff
  Sunglasses, Jacket,
  //wellness stuff
  Girlfriend    
}Bag; // Items

Stdt createStudent(){
//VARIABLES
    Stdt x;
    int num1, num2;
//CREATE STUDENT
    printf("Saisir le nom de l'eleve :");
    scanf("%s", x.name);
    num1 = strlen(x.name);
    //vérifie que la nom saisi est assez court et est une string
    while(num1>=SIZE_NAMES || (is_char(x.name)==0)){
        printf("\nMauvaise saisie ou saisie trop longue !\n");
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
        printf("\nMauvaise saisie ou saisie trop longue !\n");
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
    x.wellness = 100;
return x;
}
void displayStdt(Stdt a){
    char* txt1 = "Description de votre personnage principal \n\n";
    int size1 = strlen(txt1);
    printf("[%s %s]\n", a.name, a.sname);
    printf("Reputation : %d\n", a.fame);
    printf("Intelligence : %d\n", a.intellect);
    printf("Force : %d\n", a.power);
}
#endif