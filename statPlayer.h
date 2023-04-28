#ifndef STATPLAYER_H
#define STATPLAYER_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stdtcreate.h"

void displayStat(Stdt a){
    char* txt1 = "Stat actuel de votre personnage : \n\n";
    int size1 = strlen(txt1);
    printf("Reputation : %d\n", a.fame);
    printf("Intelligence : %d\n", a.intellect);
    printf("Force : %d\n", a.power);
    printf("Mental : %d\n", a.wellness);
}

void displayBag(Bag b){
  switch (b) {
    case Pencil: "Pencil";
    case Book: "Book";
    case Computer: "Computer";
    case Knife: "Knife";
    case Knuckles: "Knuckles";
    case Sunglasses: "Sunglasses";
    case Jacket: "Jacket";
    case Girlfriend: "Girlfriend";
    default: "Unknown";
  }
  char* txt2 = "Stuf dans votre sac : \n\n";
  int size2 = strlen(txt2);
  printf("%s; %s; %s; %s; %s; %s; %s; %s", Pencil, Book, Computer, Knife, Knuckles, Sunglasses, Jacket, Girlfriend);
  //Mettre dans XTECH pour afficher le sac
  // printf("Le contenu de myBag est : %s\n", displayBag(myBag)); 
  
}
#endif