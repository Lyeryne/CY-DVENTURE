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


Stdt createMainCharacter();

Stdt createFighter(char name[SIZE_NAMES], char sname[SIZE_NAMES]);

Bag string2enum(const char* str); 

char* enum2string(Bag bag);

void removeItem(Bag* bag, Bag item);

void addItem(Bag* bag, Bag item);

#endif
