#ifndef SCHOICE_H
#define SCHOICE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#include "DisplayTXT.h"
#include "structChoice.h"
#include "Process.h"
#include "Stdtcreate.h"
#include "Chapter.h"

#define SIZE_LINE 10000
#define MAX_CHOICE 10


static const char part_seperator[] = "###";
struct choice;

typedef struct
{
    char *description;
    char *event;
    struct choice *choices;
    int choice_count;
} chapter;

typedef struct choice
{
    char *text;
    char *nextChapter;
} choice;

#endif
