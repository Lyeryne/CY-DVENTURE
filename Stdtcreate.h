#ifndef STDTCREATE_H
#define STDTCREATE_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DisplayTXT.h"
#include "statPlayer.h"
#include "Game.h"
#include "Save.h"
#include "Robust.h"
#include "structures.h"

struct Stdt;
struct Bag;


Stdt createMainCharacter()
{
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
    
    //Pre-stat Student
    x.power = 50 + rand()%51;
    x.fame = 50;
    x.intellect = 50 + rand()%51;
    x.wellness = 100;
    x.health = 1000;
    x.dodge = 50 + rand()%51;
    x.defence = 50 + rand()%51;

return x;

}

Stdt createFighter(char name[SIZE_NAMES], char sname[SIZE_NAMES]){
    Stdt fighter;

    strncpy(fighter.name, name, SIZE_NAMES);
    strncpy(fighter.sname, sname, SIZE_NAMES);
    fighter.power = 50 + rand()%51;
    fighter.fame = 50;
    fighter.intellect = 50 + rand()%51;
    fighter.wellness = 100;
    fighter.health = 1000;
    fighter.dodge = 50 + rand()%51;
    fighter.defence = 50 + rand()%51;

    return fighter;
}

Bag string2enum(const char* str) 
{
    if (strcmp(str, "Stylot") == 0) {
        return Pencil;
    } else if (strcmp(str, "Cahier") == 0) {
        return Book;
    } else if (strcmp(str, "PC") == 0) {
        return Computer;
    } else if (strcmp(str, "Opinel") == 0) {
        return Knife;
    } else if (strcmp(str, "Knuckles") == 0) {
        return Knuckles;
    } else if (strcmp(str, "Lunette de soleil") == 0) {
        return Sunglasses;
    } else if (strcmp(str, "Veste") == 0) {
        return Jacket;
    } else if (strcmp(str, "Petite amie") == 0) {
        return Girlfriend;
    } else if (strcmp(str, "Vide") == 0) {
        return Vide;
    } 
}

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
            return "Petite amie";
        case Vide:
            return "Vide";
    }
}

void removeItem(Bag* bag, Bag item)
{
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
void addItem(Bag* bag, Bag item)
{
    int numItems = sizeof(*bag) / sizeof(bag[0]);

    //vérifie si le sac est plein
    if(numItems >= MAX_BAG_SIZE){
        printf("le sac est déjà plein -8/8- \n");
        return;
    }

    //ajoute l'objet à la fin du Sac
    bag[numItems] = item;
}

#endif
