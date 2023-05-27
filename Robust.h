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
char *Remove_carriage_return(char *value);
int robust(int integer);

void getWord(char* buffer);

long is_save_txt_null();

#endif
