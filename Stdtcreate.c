#include "Stdtcreate.h"
Stdt createMainCharacter()
{
//VARIABLES
    Stdt x;
    int num1, num2;
//CREATE STUDENT
    printf("Saisir le nom de l'eleve :");
    scanf("%s", x.name);
    num1 = strlen(x.name);
    //vérifie que la nom saisi est assez court et est une string
    while(num1>=SIZE_NAMES || (is_char(x.name)==0)){
        printf("\nMauvaise saisie ou saisie trop longue !\n");
	system("clear");
        printf("Saisir a nouveau le nom de l'eleve :");
        scanf("%s", x.name);
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

    printf("Saisir le nom de famille de l'eleve :");
    scanf("%s", x.sname);
    num2 = strlen(x.sname);
    while(num2>SIZE_NAMES || is_char(x.sname) == 0){//ROBUST
        printf("\nMauvaise saisie ou saisie trop longue !\n");
	system("clear");
        printf("Saisir à nouveau le nom de famille l'eleve :");
        scanf("%s", x.sname);
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
    x.power = 50 + rand()%51;
    x.fame = 50;
    x.intellect = 50 + rand()%51;
    x.wellness = 50;
    x.health = 300;
    x.dodge = rand()%16;
    x.defence = 10 + rand()%51;

return x;

}

Stdt createFighter(char name[SIZE_NAMES], char sname[SIZE_NAMES]){
    Stdt fighter;

    strncpy(fighter.name, name, SIZE_NAMES);
    strncpy(fighter.sname, sname, SIZE_NAMES);
    fighter.power = 50 + rand()%51;
    fighter.fame = 50;
    fighter.intellect = 50 + rand()%51;
    fighter.wellness = 50;
    fighter.health = 300;
    fighter.dodge = rand()%16;
    fighter.defence = 10 + rand()%51;

    return fighter;
}

Stdt createBag(Stdt main_character)
{
    const char *TabBag[MAX_BAG_SIZE] = {"Stylo", "Cahier", "Poing américain", "Ordinateur", "Veste", "Opinel", "Manuel", "Antisèche"};

    for (int i = 0; i < MAX_BAG_SIZE; i++)
    {
        strncpy(main_character.Bag[i], TabBag[i], SIZE_NAMES - 1);
        main_character.Bag[i][SIZE_NAMES - 1] = '\0'; // Assurez-vous de terminer la chaîne avec un caractère nul
    }

    main_character.bag_size = MAX_BAG_SIZE;

    return main_character;
}

void removeItem(Stdt* main_character, const int item)
{
	int removed = 0;
	//Vérifier si l'élèment est déjà présent dans le sac
	for(int i=0; i < main_character->bag_size; i++)
	{
		//Si l'objet est dans le sac, le supprimer en décalant vers la Gauche	
		if(main_character->Bag[i] == main_character->ref_bag[item])
		{
			for(int j = i; j < main_character->bag_size -1 ; j++)
			{
				main_character->Bag[j] = main_character->Bag[i+1];		
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
	int add = 0;
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
			if(main_character->Bag[i] == main_character->ref_bag[item])
			{
				printf("~%s~ est déjà dans le sac.\n", main_character->ref_bag[item]);  
				return; 				
			} 
		}
		


	main_character->Bag[main_character->bag_size] = main_character->ref_bag[item];
	printf("~%s~ a bien été ajouté dans le sac.\n", main_character->ref_bag[item]);							
	}		
} 


