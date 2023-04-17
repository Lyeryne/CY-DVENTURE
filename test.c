#include <stdio.h>
#include <stdlib.h>


int choice(int size){
    /*Cette fonction a pour but de proposer un choix sur size propositions,
    Elle vérifie également que les valeurs retournées par l'utilisateurs 
    sont des valeurs de type int et comprises entre 1 et size*/

int lu,n, count = 0;
int *tab = NULL;
tab = malloc(size * sizeof(int));
for(int i = 0; i < size; i++){
    tab[i] = i+1;
}
do{
    printf("Veuillez entrer votre réponse: ");
    lu = scanf("%d", &n);
    fflush(stdin);
    if(lu == 0){
        printf("Erreur de saisie !\n");
    }
    else{
        for(int i = 0;i < size; i++){
            if(tab[i] == n){
                count += 1;
        }
        }
        if(count == 0){
            printf("Erreur de saisie !\n");
        }
        else{
            return n;
        }
    }
}while(lu == 0 || count == 0);
}
int main(){
    choice(4);
/*    int n;
    int lu = 0;
 
int is_number(int n){
    int lu = 0;
    lu = scanf("%d", &n);
    fflush(stdin);
    if(lu ==0){
        return 0;
    }
    return 1;
}
int rep;
printf("saisissez un nbr: ");
scanf("%d", &rep);
if(is_number(rep)==1){
    printf("%d est un nombre", rep);
}
else{
    printf("%d n'est pas un nombre", rep);
}

   do{
        printf("Veuillez entrer un nombre : ");
        //fflush(stdout);
 
        lu = scanf("%d", &n);
        fflush(stdin);
        if(n != 1 && n !=2){
            lu = 0;
        }
    } while (lu == 0);
 
    printf("Vous avez entré : %d.\n", n);
    */
    return 0;
}

