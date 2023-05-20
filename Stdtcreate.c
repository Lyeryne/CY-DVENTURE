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

void removeItem(Stdt* main_character, const char* item)
{
	int removed = 0;
	//Vérifier si l'élèment est déjà présent dans le sac
	for(int i=0; i < main_character->bag_size; i++)
	{
		//Si l'objet est dans le sac, le supprimer en décalant vers la Gauche
		if(strcmp(main_character->Bag[i], item) == 0)
		{
			for(int j=i; j < main_character->bag_size -1; j++)
			{
				strcpy(main_character->Bag[j], main_character->Bag[j+1]);
			}
			main_character->bag_size--;
			removed = 1;
			break;
		}
	}
	
	//Robust
	if(removed == 1)
	{
		printf("~%s~ a été supprimé du sac.\n", item);
	} 
	else {
		printf("~%s~ n'a pas été trouvé dans le sac.\n", item);
    }
}

void addItem(Stdt* main_character, const char* item)
{
	//Robust
	if(main_character->bag_size >= MAX_BAG_SIZE)
	{
		printf("Votre sac est plein : ~8/8~\n");
		return;
	}
	
	//Verifier si l'element est déjà présent dans le sac
	for(int i=0; i < main_character->bag_size; i++)
	{
		if(strcmp(main_character->Bag[i], item) == 0)
		{
			printf("~%s~ est déjà présent dans votre sac.\n", item);
			return;
		}
	}
	
	strcpy(main_character->Bag[main_character->bag_size], item);
	main_character->bag_size++;
	
	printf("~%s~ a été ajouté dans le sac.\n", item);
	
} 


