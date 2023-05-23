#ifndef SAVE_H
#define SAVE_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>


#include "DisplayTXT.h"
#include "Game.h"
#include "Stdtcreate.h"
#include "statPlayer.h"
#include "structures.h"

struct Stdt;
struct Bag;
struct Choice;
struct chapter;
struct SaveData;


void SaveGame(SaveData* data);
SaveData loadGame();

#endif
