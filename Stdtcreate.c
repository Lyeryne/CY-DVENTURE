#include "Stdtcreate.h"
Stdt createMainCharacter(Stdt x)
{
//VARIABLES
    int num1, num2;
//CREATE STUDENT
    printf("Saisir le prénom de l'eleve :");
    getWord(x.name);
    num1 = strlen(x.name);
    //vérifie que la nom saisi est assez court et est une string
    while(num1>=SIZE_NAMES || (is_char(x.name)==0)){
        printf("\nMauvaise saisie ou saisie trop longue !\n");
	    system("clear");
        printf("Saisir a nouveau le nom de l'eleve :");
        getWord(x.name);
        num1 = strlen(x.name);
    }
    //DISPLAY BETTER NAME
    if(x.name[0] >= 'a' && x.name[0] <= 'z'){
        x.name[0] = toUpper(x.name[0]);
    }
    int j=1;
    while(x.name[j] != '\0'){
        if(x.name[j] >= 'A' && x.name[j] <= 'Z'){
        x.name[j] = toLower(x.name[j]);
        }
        j++;
    }

    printf("\n\nSaisir le nom de famille de l'eleve :");
    getWord(x.sname);
    num2 = strlen(x.sname);
    while(num2>SIZE_NAMES || is_char(x.sname) == 0){//ROBUST
        printf("\nMauvaise saisie ou saisie trop longue !\n");
	    system("clear");
        printf("Saisir à nouveau le nom de famille l'eleve :");
        getWord(x.sname);
        num2 = strlen(x.sname);
    }
    //DISPLAY BETTER SNAME
    if(x.sname[0] >= 'a' && x.sname[0] <= 'z'){
        x.sname[0] = toUpper(x.sname[0]);
    }
    j=1;
    while(x.sname[j] != '\0'){
        if(x.sname[j] >= 'A' && x.sname[j] <= 'Z'){
        x.sname[j] = toLower(x.sname[j]);
        }
        j++;
    }
    
    //Pre-stat Student
    x.power = 10;
    x.fame = 1.0;
    x.intellect = 10;
    x.wellness = 10;
    x.health = 20;
    x.dodge = 10;
    x.defence = 5;

return x;

}

Stdt createFighter(char name[SIZE_NAMES], char sname[SIZE_NAMES]){
    Stdt fighter;

    strncpy(fighter.name, name, SIZE_NAMES);
    strncpy(fighter.sname, sname, SIZE_NAMES);
    fighter.power = 15;
    fighter.fame = 1;
    fighter.intellect = 50 + rand()%51;
    fighter.wellness = 50;
    fighter.health = 30;
    fighter.dodge = 10;
    fighter.defence = 7;

    return fighter;
}

void createBag(Stdt *main_character)
{
    char *TabBag[MAX_BAG_SIZE] = {"Stylo", "Cahier", "Poing américain", "Ordinateur", "Veste", "Girlfriend", "Antisèche"};
    //ROBUST
    if(TabBag == NULL)
	{
		printf("Quelque chose ne vas pas avec TabBag(createBag)\n");
		exit(1);
	}
    //ROBUST
    if(main_character == NULL)
	{
		printf("Quelque chose ne vas pas avec main_character(createBag)\n");	
        exit(2);
    }
    
    else
    {
        for (int i = 0; i < MAX_BAG_SIZE; i++)
        {
            main_character->ref_bag[i] = set_text_tab(main_character->ref_bag[i], TabBag[i]);
        }
        main_character->bag_size=0;
        addItem(main_character, 0);
        addItem(main_character, 1);
    }
}

void removeItem(Stdt* main_character, const int item)
{
    //ROBUST
    if(main_character == NULL)
	{
		printf("Quelque chose ne vas pas avec main_character(removeItem)\n");
		exit(3);
	}
    //Vérifier si l'élèment est déjà présent dans le sac
    for(int i=0; i < main_character->bag_size; i++)
    {
        //Si l'objet est dans le sac, le supprimer en décalant vers la Gauche
        if(strcmp(main_character->Bag[i] ,main_character->ref_bag[item]) == 0)
        {
            for(int j = i; j < main_character->bag_size -1 ; j++)
            {
				main_character->Bag[j] = set_text_tab(main_character->Bag[j], main_character->Bag[j+1]);
            }
            main_character->bag_size--;
            printf("\n~%s~ a été supprimé du sac.\n", main_character->ref_bag[item]);
            return;
        }
    }
    //Robust
    printf("\n~%s~ n'a pas été trouvé dans le sac.\n", main_character->ref_bag[item]);
}

void addItem(Stdt* main_character, const int item)
{
    //ROBUST
    if(main_character == NULL)
	{
		printf("Quelque chose ne vas pas avec main_character(addItem)\n");
		exit(4);
	}

    //Robust
    if(main_character->bag_size >= MAX_BAG_SIZE)
    {
        printf("Votre sac est plein : ~8/8~\n");
        return;
    } 

    else
    {
        for(int i=0; i < main_character->bag_size; i++)
        {
            if(strcmp(main_character->Bag[i], main_character->ref_bag[item])==0)
            {
                printf("~%s~ est déjà dans le sac.\n", main_character->ref_bag[item]);
                return;
            } 
        }

	main_character->Bag[main_character->bag_size] = set_text_tab(main_character->Bag[main_character->bag_size], main_character->ref_bag[item]);
    printf("~%s~ a bien été ajouté dans le sac.\n", main_character->ref_bag[item]);
	main_character->bag_size ++;
    }
} 


