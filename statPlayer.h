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


void displayStat(Stdt a);
void displayBag(Bag b);
void in_de_creaseStat(Stdt* student, int fame, int health, int power, int intellect, int wellness, int sign);
void fight(Stdt a, Stdt b);
void displayBeforeFight(Stdt fighter, Stdt main);

#endif
