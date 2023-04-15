#ifndef ROBUST_H
#define ROBUST_H

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>

// CHANGE LETTER
char toUpper(char c){
    return c-32;
}
char toLower(char c){
    return c+32;
}

int is_char(char* chaine) {
    for(int i=0; i < strlen(chaine);i++){
        if(chaine[i] < 65 || (chaine[i]>90 && chaine[i]<97) || chaine[i]>122){
            return 0; //ya un caratère special
        }
    }
    return 1;
}

int is_number(int num){
    if(sizeof(num) == 4){//sizeof == int
        return 1; //c'est un nombre
    }
    return 0; //Ce n'est pas un nombre
}

#endif

