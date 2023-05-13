#include "Robust.h"
//Renvoie la lettre en majuscule
char toUpper(char c){
    return c-32;
}
//Renvoie la lettre en minuscule
char toLower(char c){
    return c+32;
}

//vérifie si toutes les valeurs de la chaine sont des lettres
int is_char(char* chaine) {
    for(int i=0; i < strlen(chaine);i++){
        if(chaine[i] < 65 || (chaine[i]>90 && chaine[i]<97) || chaine[i]>122){
            return 0; //ya un caratère special
        }
    }
    return 1;
}

int choice(int size){
    /*Cette fonction a pour but de proposer un choix sur size propositions,
    Elle vérifie également que les valeurs retournées par l'utilisateurs 
    sont des valeurs de type int et comprises entre 1 et size*/

int lu,n, count = 0;
//initialise un tableau de taille choice pour vérifier la correspondance avec n
int *tab = NULL;
//tab = malloc(size * sizeof(int));
//remplissage du tableau de valeurs de 1 a choice
for(int i = 0; i < size; i++){
    tab[i] = i+1;
}
do{
    printf("Veuillez entrer votre réponse : ");
    //demande une valeur a l'utilisateur et vide la mémoire tampon
    lu = scanf("%d", &n);
    fflush(stdin);
    //Si la valeur de l'utilisateur n'est pas un int
    if(lu == 0){
        printf("Erreur de saisie !\n");
    }
    else{
        /*La valeur de l'utilisateur est un int, on parcourt le tableau
        pour voir s'il fait partie des choix */
        for(int i = 0;i < size; i++){
            if(tab[i] == n){
                //on trouve une occurence
                count += 1;
        }
        }
        //la valeur n'est pas présente entre 1 et choice(il ne fait pas partie des choix)
        if(count == 0){
            printf("Erreur de saisie !\n");
        }
        else{
            return n;
        }
    }
}while(lu == 0 || count == 0);
}

