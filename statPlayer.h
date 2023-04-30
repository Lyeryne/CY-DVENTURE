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
  Bag myBag[] = {Pencil, Book, Computer, Knife, Knuckles, Sunglasses, Jacket, Girlfriend};
  int numItems = sizeof(myBag) / sizeof(myBag[0]);

  printf("Bag items:\n");
  for(int i = 0; i < numItems; i++) {
    printf("- %s\n", enum2string(myBag[i]));
  }
}
#endif