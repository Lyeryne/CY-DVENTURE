#ifndef STDTCREATE_H
#define STDTCREATE_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Robust.h"
#define SIZE_NAMES 100

typedef struct{
  char name[SIZE_NAMES];
  char sname[SIZE_NAMES];
  int fame;                    
  int power;
  int intellect;
  int wellness;
} Stdt; // Main character
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

typedef enum{
  //intellect stuff
  Pencil, Book, Computer,
  //power stuff
  Knife, Knuckles, 
  //fame stuff
  Sunglasses, Jacket,
  //wellness stuff
  Girlfriend,
  //empty
  Vide    
}Bag; // Items
char* enum2string(Bag bag)
{
    switch(bag){
        case Pencil:
            return "Stylot";
        case Book:
            return "Cahier";
        case Computer:
            return "PC";
        case Knife:
            return "Opinel";
        case Knuckles:
            return "Knuckles";
        case Sunglasses:
            return "Lunette de soleil";
        case Jacket:
            return "Veste";
        case Girlfriend:
            return "Bae";
        case Vide:
            return "Vide";
    }
}

void displayStdt(Stdt a, Bag b){
    char* txt1 = "Description de votre personnage principal \n\n";
    int size1 = strlen(txt1);
    //displayTxt(size1, txt1);
    printf("[%s %s]\n", a.name, a.sname);
    printf("Reputation : %d\n", a.fame);
    printf("Intelligence : %d\n", a.intellect);
    printf("Force : %d\n", a.power);
}

void removeItem(Bag* bag, Bag item){
    int numItems = sizeof(*bag) / sizeof(bag[0]);
    int itemIndex = -1;

    for(int i = 0; i<numItems; i++){ // Cherche l'index de l'objet dans le sac
        if(bag[i] == item){
            itemIndex = i;
            break; 
        }
    }

    if(itemIndex>=0){// Si l'objet est dans le sac, le supprimer
        for(int i = itemIndex; i<numItems-1; i++){ // Décaler tous les éléments suivants d'un index vers la gauche
            bag[i] = bag[i+1];
        }
        bag[numItems-1] = Vide;// Mettre le dernier élément à 'Vide'
    }
}
#endif