#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Robust.h"
#include "Stdtcreate.h"
#include "statPlayer.h"

static const char part_seperator[] = "###";
struct Choice;
struct chapter;
struct SaveData;
struct Stdt;
struct Bag;

int pre_game();
char *set_text_property(char *buf, char *value);
void ProcessDescription(chapter *chap, char *value);
void ProcessEvent(chapter *chap, char *value);
void ProcessChoice(chapter *chap, char *value);
chapter create_chapter(char *chapter_name);
char *displayChapter(chapter chap);



#endif
