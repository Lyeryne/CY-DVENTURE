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

void getWord(char* buffer){
    int ret = 0;

    if(buffer == NULL){
        printf("getWord buffer is NULL \n");
        exit(10);
    }

    do{
        ret = scanf("%s", buffer);
        while(getchar() != '\n');
    } while (ret != 1);

}

int robust(int integer)
{
	int choice;
	
	do {
        printf("\nChoix : ");
		if (scanf("%d", &choice) != 1 || choice < 1 || choice > integer) {
			printf("Saisie incorrecte ! Saisir à nouveau :\n");
			scanf("%*[^\n]"); // Vider le flux d'entrée
			scanf("%*c");
			choice = -1;
		}
	} while (choice == -1);

	return choice;
}


