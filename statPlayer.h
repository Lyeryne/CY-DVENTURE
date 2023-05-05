#ifndef STATPLAYER_H
#define STATPLAYER_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Stdtcreate.h"
#include "DisplayTXT.h"
#include "structures.h"

struct Stdt;
struct Bag;


void displayStat(Stdt a){
    char* txt1 = "Stat actuel de votre personnage : \n\n";
    int size1 = strlen(txt1);
    displayTxt(size1, txt1);
    printf("[%s %s]\n", a.sname, a.name);
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
char* enum2string(Bag bag);
    printf("- %s\n", enum2string(myBag[i]));
  }
}

void in_de_creaseStat(Stdt* student, int fame, int health, int power, int intellect, int wellness, int sign){
  student->fame += abs(fame) * sign;
  student->health += abs(health) * sign;
  student->power += abs(power) * sign;
  student->intellect += abs(intellect) * sign;
  student->wellness += abs(wellness) * sign;
}

void fight(Stdt a, Stdt b){
  Stdt tmp;
  int rounds = 0;

  //while ninjas are still alive
  while(a.health>0 && b.health>0){
    rounds = rounds + 1;
    printf("---- ROUND %d ----\n", rounds);
    //a=attacker b=defender
    //get random value between 0.00 and 1.00
    int randomValue = rand()%101;
        //check if b dodges
        if(randomValue>b.dodge){
            //the defender takes damages
            //damages are reduced
            int dmg = a.power - b.defence;
            if(dmg<0){
                dmg = 0;
            } 
            b.health = b.health - dmg;
            printf("%s prend %d dommages de %s\n", b.name, dmg, a.name);
            printf("%s a %d HP restant\n", b.name, b.health);
        } else {
            printf("%s esquive l'attaque de %s\n", b.name, a.name);
        }
    //swap attacker and defender
    tmp = a; 
    a = b;
    b = tmp;
    }
    // Display winner
    if(a.health > 0){
        printf("%s a vaincu %s !\n", a.name, b.name);
        printf("%s a %d HP restant\n", a.name, a.health);
    } else{
        printf("%s a mis KO %s avec %d HP restant!\n", b.name, a.name, b.health);
    }
    printf("\n");
}
void displayBeforeFight(Stdt fighter, Stdt main){
    printf("Personnage Principal :\n");
    printf("[%s %s]\n", main.name, main.sname);
    printf("ATK = %d\n", main.power);
    printf(" DEF = %d\n", main.defence);
    printf(" DODGE = %d\n", main.dodge);
    printf(" LIFE POINT = %d\n", main.health);
    printf("\n\n");
    printf("Adversaire :\n");
    printf("[%s %s]\n", fighter.name, fighter.sname);
    printf("ATK = %d\n", fighter.power);
    printf(" DEF = %d\n", fighter.defence);
    printf(" DODGE = %d\n", fighter.dodge);
    printf(" LIFE POINT = %d\n", fighter.health);
    printf("\n\n\n");
}

#endif
