#ifndef SCHOICE_H
#define SCHOICE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


static const char part_seperator[] = "###";//Separateur entre description/choix
struct choice;  // déclaration de la structure choice
struct chapter; // déclaration de la structure chapter

typedef struct
{
    char *description;
    char *event;
    choice* choices;
    int choice_count;//représente le nombre de choix dans ce chapitre
} chapter;

typedef struct choice
{
    char *text;
    chapter* nextChapter;
} choice;

char *fillChoice(char s[], char s2[500][2], int currentChoiceInd)
{
    for (int i = 0; i < 2; i++)
    {
        s[i] = s2[currentChoiceInd][i];
    }

    return s;
}

#endif