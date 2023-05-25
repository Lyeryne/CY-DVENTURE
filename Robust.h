#ifndef ROBUST_H
#define ROBUST_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


struct Stdt;
struct Bag;

char toUpper(char c);
char toLower(char c);

int is_char(char* chaine);

int robust(int integer);

void getWord(char* buffer);

long is_txt_null(char *file_name);

#endif
