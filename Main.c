#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_NAMES 100
#define MAX_BAG_SIZE 7
#define SIZE_LINE 10000
#define MAX_CHOICE 10
#define SIZE 100000

typedef struct
{
	char name[SIZE_NAMES];
	char sname[SIZE_NAMES];
	int fame;
	int health;                    
	int power;
	int intellect;
	int wellness;
	int dodge;
	int defence;
	char *Bag[MAX_BAG_SIZE];
	int bag_size;
	char *ref_bag[MAX_BAG_SIZE];
	int token;
	
} Stdt; // Main character

typedef struct
{
	char *text;
	char *nextChapter;
} Choice;

typedef struct
{
    int type_event;
    int n_fighter;
    int type_stat;
    int n_stat;
    int id_object;
	int add_or_remove_bag;
    int positive_or_negative;
	int add_token;
}Event;

typedef struct
{
    char *description;
    Event *event;
    Choice *choices;
    int choice_count;
	char *after_description;
} chapter;

typedef struct 
{
    Stdt main_character;
    char *nxt_chap;
	int load;
} SaveData;


//vérifie si toutes les valeurs de la chaine sont des lettres
int is_char(char* chaine) {
    for(int i=0; i < strlen(chaine);i++){
        if(chaine[i] < 65 || (chaine[i]>90 && chaine[i]<97) || chaine[i]>122){
            return 0; //ya un caratère special
        }
    }
    return 1;
}
char toUpper(char c){
    return c-32;
}
//Renvoie la lettre en minuscule
char toLower(char c){
    return c+32;
}

char *Remove_carriage_return(char *value) {
	if (value == NULL) {
		printf("quelque chose ne vas pas avec value(Remove_carriage_return/Robust.c)\n");
		exit(345);
	}
	for (int i = 0; i <strlen(value) ; i++) {
		char bonjour = value[i]; // Correction : retirer l'opérateur * ici
		if (bonjour == '\n' || bonjour == '\r') { // Correction : utiliser des simples quotes pour les caractères
			value[i] = '\0';
			break;
		}
	}
	return value;
	
}
void WaitPress()
{
    printf("Press ENTER pour continuer...\n");
    while (getchar() != '\n');
}
void getWord(char* buffer){
    int ret = 0;

    if(buffer == NULL){
        printf("getWord buffer is NULL \n");
        exit(10);
    }

    do{
        ret = scanf("%s", buffer);
        scanf("%*[^\n]"); // Vider le flux d'entrée
		scanf("%*c");
    } while (ret != 1);

}
char *set_text_tab(char *buf, char *value){
	int len = strlen(value) + 1;
	buf = (char *)malloc(len * sizeof(char));
	if(buf == NULL){
		printf("Quelque chose ne vas pas avec buf(text_tab)");
		exit(34647);
	}
	strcpy(buf, value);
	return buf;
}
long is_save_txt_null()
{
    char *path = (char *)malloc((strlen("Save/save") + strlen(".txt")) * sizeof(char) + 1);
	//~~> contien le chemin d'accès au fichier txt que nous voulons ouvrir

	strcpy(path, "Save/save"); // suivie de 'chapter_name'(concaténation)
	strcat(path, ".txt");		// et de '.txt'

    FILE *fp = fopen(path, "r");
    if(fp == NULL)
    {
        printf("erreur fopen (file2)\n");
        exit(125);
    }

    fseek(fp, 0, SEEK_END);

    long result = ftell(fp);

    fclose(fp);

return result;
}


void removeItem(Stdt* main_character, const int item)
{
    //ROBUST
    if(main_character == NULL)
	{
		printf("Quelque chose ne vas pas avec main_character(removeItem)\n");
		exit(18);
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
		exit(19);
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
Stdt createMainCharacter(Stdt x)
{
//VARIABLES
    int num1, num2;
//CREATE STUDENT
    printf("Saisir le nom de l'eleve :");
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
		exit(17);
	}
    //ROBUST
    if(main_character == NULL)
	{
		printf("Quelque chose ne vas pas avec main_character(createBag)\n");	
        exit(4);
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

void displayTxt(int size, char *txt)
{
//afficher .txt lettre par lettre avec un petit délai entre chaque lettre, ~> impression de temps réel
	int delay1 = 0;//simuler l'effet de défilement(en ms) 
	for(int i=0; i<size; i++){
		printf("%c", txt[i]);
		fflush(stdout);//force l'affichage du caractère sur la sortie standard avant de passer à la lettre suivante
		struct timespec attente ={0, delay1*1000000};//attendre le délai spécifié entre chaque lettre
		nanosleep(&attente, NULL);// permet de mettre en pause l'exécution du programme pendant une durée donnée(ici en delay1)
	}
}

void displayStat(Stdt a){
  char* txt1 = "Stat actuel de votre personnage : \n\n";
  int size1 = strlen(txt1);
  displayTxt(size1, txt1);
  printf("[%s %s]\n", a.sname, a.name);
  printf("Reputation : %d\n", a.fame);
  printf("Intelligence : %d\n", a.intellect);
  printf("Force : %d\n", a.power);
  printf("Mental : %d\n", a.wellness);
}

void displayBag(Stdt* main_character){
  //ROBUST
	if(main_character == NULL)
	{
		printf("Quelque chose ne vas pas avec main_character(displayBag)\n");
		exit(13);
	}

  printf("\nContenu de votre sac :\n");
  if(main_character->bag_size == 0)
  {
  	printf("Votre sac est vide ~0/8~\n");
  	return;
  }
  
  for(int i=0; i < main_character->bag_size; i++)
  {
  	printf("%s\n", main_character->Bag[i]);
  }
}

void fight(Stdt a, Stdt b)
{
  Stdt tmp;
  int rounds = 0;
  //while ninjas are still alive
  while(a.health>0 && b.health>0){
    rounds = rounds + 1;
    printf("---- ROUND %d ----\n", rounds);
    //a=attacker b=defender
    int randomValue = rand()%101;
        //check if b dodges
        if(randomValue > b.dodge){
            //the defender takes damages
            //damages are reduced
            int dmg = a.power - b.defence;
            if(dmg < 0){
                dmg = 0;
            } 
            b.health = b.health - dmg;
			if(b.health < 0){
				b.health = 0;
			}
            printf("%s prend %d dommages de %s\n", b.name, dmg, a.name);
            printf("%s a %d HP restant\n", b.name, b.health);
        } else {
            printf("%s esquive l'attaque de %s\n", b.name, a.name);
        }
    //swap attacker and defender
    tmp = a; 
    a = b;
    b = tmp;
    WaitPress();
  }
  // Display winner
  if(a.health > 0){
    printf("%s a vaincu %s !\n", a.name, b.name);
    printf("%s a %d HP restant\n", a.name, a.health);
  } else {
    a.health = 0;
	printf("\n");
    printf("~~> %s a mis KO %s avec %d HP restant!\n", b.name, a.name, b.health);
    WaitPress();
  }
  printf("\n");
}

void displayBeforeFight(Stdt fighter, Stdt main){
    printf("Personnage Principal :\n");
    printf("[%s %s]\n", main.name, main.sname);
    printf("Attaque = %d\n", main.power);
    printf("Defense = %d\n", main.defence);
    printf("Esquive = %d\n", main.dodge);
    printf("\n");
    printf("VS\n\n");
    printf("Adversaire :\n");
    printf("[%s %s]\n", fighter.name, fighter.sname);
    printf("Attaque = %d\n", fighter.power);
    printf("Defense = %d\n", fighter.defence);
    printf("Esquive = %d\n", fighter.dodge);
    printf("\n\n\n");
    WaitPress();
}

void SaveGame(SaveData* data){
    if(data == NULL){
        printf("y'a pas de sauvegarde mon sauce");
        exit(22);
    }
    FILE* fp = fopen("Save/save.txt", "w");
    if(fp == NULL){
        printf("Erreur fopen (file Save)\n");
        exit(11);
    }
    

    //STAT
    int ret1 = fprintf(fp, "%d\n", data->main_character.fame);
    if(ret1 < 0)   
    {
        printf("quelque chose ne vas pas avec fprintf de data->main_character.fame(SaveGame)\n");
        exit(112);
    }
    int ret2 = fprintf(fp, "%d\n", data->main_character.power);
    if(ret2 < 0)
    {
        printf("quelque chose ne vas pas avec fprintf de data->main_character.power(SaveGame)\n");
        exit(113);
    }
    int ret3 = fprintf(fp, "%d\n", data->main_character.intellect);
    if(ret3 < 0)
    {
        printf("quelque chose ne vas pas avec fprintf de data->main_character.intellect(SaveGame)\n");
        exit(114);
    } 
    int ret4 = fprintf(fp, "%d\n", data->main_character.wellness);
    if(ret4 < 0)
    {
        printf("quelque chose ne vas pas avec fprintf de data->main_character.wellness(SaveGame)\n");
        exit(115);
    }
    int ret5 = fprintf(fp, "%d\n", data->main_character.health);
    if(ret5 < 0)
    {
        printf("quelque chose ne vas pas avec fprintf de data->main_character.health(SaveGame)\n");
        exit(116);
    }
    int ret6 = fprintf(fp, "%d\n", data->main_character.dodge);
    if(ret6 < 0)
    {
        printf("quelque chose ne vas pas avec fprintf de data->main_character.dodge(SaveGame)\n");
        exit(117);
    }
    int ret7 = fprintf(fp, "%d\n", data->main_character.defence);
    if(ret7 < 0)
    {
        printf("quelque chose ne vas pas avec fprintf de data->main_character.defence(SaveGame)\n");
        exit(118);
    }
    int ret8 = fprintf(fp, "%d\n", data->main_character.token);
    if(ret8 < 0)
    {
        printf("quelque chose ne vas pas avec fprintf de data->main_character.token(SaveGame)\n");
        exit(120);
    }

    
    //BAG
    int ret9 = fprintf(fp, "%d\n", data->main_character.bag_size);
    if(ret9 < 0)
    {
        printf("quelque chose ne vas pas avec fprintf de data->main_character.bag_size(SaveGame)\n");
        exit(121);
    }
    for (int i = 0; i < data->main_character.bag_size; i++)
    {				 

    	fprintf(fp, "%s\n", data->main_character.Bag[i]);
    } 

    for(int i = 0; i < MAX_BAG_SIZE; i++){
        fprintf(fp, "%s\n", data->main_character.ref_bag[i]);
    }

    //CHOICES
    if(data->nxt_chap == NULL){
        printf("pas de nxt_chap");
        exit(54);
    }
    else{
        int ret10 = fprintf(fp, "%s\n", data->nxt_chap);
        if(ret10 < 0)
        {
            printf("quelque chose ne vas pas avec fprintf de data->nxt_chap(SaveGame)\n");
            exit(122);
        }
    }

    fclose(fp);
}

SaveData loadGame() {
    SaveData data = {0};
    char buffer[256];
    char buffer2[340];
    data.load = 0;
    FILE* fp = fopen("Save/save.txt", "r");
    if (fp == NULL) {
        printf("Erreur fopen (file LoadGame)\n");
        exit(111);
    }

    //STAT STDT
    int ret1 = fscanf(fp, "%d\n", &(data.main_character.fame));
    if(ret1 < 0 )
    {
        printf("quelque chose ne vas pas avec fscanf de data.main_character.fame(loadGame)\n");
        exit(112);
    }
    int ret2 = fscanf(fp, "%d\n", &(data.main_character.power));
    if(ret2 < 0)
    {
        printf("quelque chose ne vas pas avec fscanf de data.main_character.power(loadGame)\n");
        exit(113);
    }
    int ret3 = fscanf(fp, "%d\n", &(data.main_character.intellect));
    if(ret3  < 0)
    {
        printf("quelque chose ne vas pas avec fscanf de data.main_character.intellect(loadGame)\n");
        exit(114);
    } 
    int ret4 = fscanf(fp, "%d\n", &(data.main_character.wellness));
    if(ret4  < 0)
    {
        printf("quelque chose ne vas pas avec fscanf de data.main_character.wellness(loadGame)\n");
        exit(115);
    }
    int ret5 = fscanf(fp, "%d\n", &(data.main_character.health));
    if(ret5  < 0)
    {
        printf("quelque chose ne vas pas avec fscanf de data.main_character.health(loadGame)\n");
        exit(116);
    }
    int ret6 = fscanf(fp, "%d\n", &(data.main_character.dodge));
    if(ret6  < 0)
    {
        printf("quelque chose ne vas pas avec fscanf de data.main_character.dodge(loadGame)\n");
        exit(117);
    }
    int ret7 = fscanf(fp, "%d\n", &(data.main_character.defence));
    if(ret7  < 0)
    {
        printf("quelque chose ne vas pas avec fscanf de data.main_character.defence(loadGame)\n");
        exit(118);
    }
    int ret8 = fscanf(fp, "%d\n", &(data.main_character.token));
    if(data.main_character.token < 0 || data.main_character.token > 3){
        data.main_character.token = 0;
    }
    if(ret8  < 0)
    {
        printf("quelque chose ne vas pas avec fscanf de data.main_character.token(loadGame)\n");
        exit(120);
    }

    //BAG
    int ret9 = fscanf(fp, "%d\n", &(data.main_character.bag_size));
    if(ret9  < 0)
    {
        printf("quelque chose ne vas pas avec fscanf de data.main_character.bag_size(loadGame)\n");
        exit(119);
    }
    for (int i = 0; i < data.main_character.bag_size; i++)
    {				
        fscanf(fp, "%s\n", buffer);
        data.main_character.Bag[i] = malloc(strlen(buffer)+1);
        if(data.main_character.Bag[i] == NULL){
            printf("Allocation data.main_character.Bag a pas marché(loadGame)\n");
            exit(121);
        }
    	strcpy(data.main_character.Bag[i], buffer);
    } 

    for(int i = 0; i < MAX_BAG_SIZE; i++){
        fscanf(fp, "%s\n", buffer);
        data.main_character.ref_bag[i] = (char *)malloc((strlen(buffer)+1) * sizeof(char));
        if(data.main_character.ref_bag[i] == NULL){
            printf("Allocation data.main_character.ref_bag a pas marché(loadGame)\n");
            exit(122);
        }
        strcpy(data.main_character.ref_bag[i], buffer);
    }
    //CHOICES
    if(data.nxt_chap != NULL){
        printf("quelque chose ne vas pas avec data.nxt_chap(loadGame)\n");
        exit(123);
    }
    else{
        fscanf(fp, "%s\n", buffer);
        data.nxt_chap = (char *)malloc((strlen(buffer))* sizeof(char));
        if(data.nxt_chap == NULL){
            printf("allocation échouée pour data.nxt_chap(loadGame)\n");
            exit(124);
        }
        strcpy(data.nxt_chap , buffer);
    }
    
    fclose(fp);

    return data;
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

void displayLoading()
{
  int pourcentage = 0;
  for(pourcentage = 0; pourcentage <= 100; pourcentage+=20) {
        printf("LANCEMENT DU JEU... %d%%\r", pourcentage); // \r permet de revenir en début de ligne
        fflush(stdout); // force l'affichage immédiat du texte
        usleep(100000); // suspend l'exécution du programme pendant 100000 microsecondes (0,1 seconde)
    }
    printf("Chargement fini !\n");
    sleep(1);
    system("clear");
}

int pre_game()
{
	int start, lu, count;
	system("clear");
	printf("X TECH - ADVENTURE\n");
	char *txt = "Produit par\n-> Louaye SAGHIR\n-> Clement PREMOLI\n-> Roman BOULLIER\n\n";
	int size = strlen(txt);
	displayTxt(size, txt);
	sleep(1);
	system("clear");
	// Choix de partie
	printf("========= MENU ========\n"); // ASCI ART
	printf(" 1 -> Nouvelle Partie\n");	 // ASCI ART
	printf(" 2 -> Reprendre Partie\n");	 // ASCI ART
	printf(" 3 -> Quitter le Jeu\n\n");	 // ASCI ART

	start = robust(3);

	return start;
}

int no_game()
{
	int start, lu;
	system("clear");
	printf("========= MENU ==========\n"); // ASCI ART
	printf("1 -> Nouvelle Partie\n");	   // ASCI ART
	printf("~~ ACCES NON-AUTORISER ~~\n"); // ASCI ART
	printf("2 -> Quitter le Jeu\n\n");	   // ASCI ART
	
	start = robust(2);

	return start;
}

char *set_text_property(char *buf, char *value)
//=>permet de remplir une propriété de type char * (%s) d'une structure de manière dynamique
{
	int length;

	if(value == NULL){
		printf("Value is NULL !!\n");
		exit(9);
	}

	if (buf == NULL) // propriété n'est pas initialisée
	{
		length = strlen(value) + 1;
		buf = (char *)malloc(length * sizeof(char)); // allocation pour stocker 'value' et copie cette valeur dans 'buf'
		if (buf == NULL)
		{
			exit(1);
		}
		strcpy(buf, value); // copier la %s 'value' dans le tampon 'buf'
	}
	else
	{ // propriété est déjà initialisée
		length = strlen(buf) + strlen(value) + 1;
		char *temp = (char *)realloc(buf, length * sizeof(char));
		// allocation pour stocker la valeur déjà présente dans 'buf' et la valeur à ajouter (value)
		if (temp != NULL)
		{
			buf = temp; // affecte le * 'temp' à 'buf'
		}
		strcat(buf, value); // concatenation de 'value' à la propriété 'buf'
	}

	return buf;
}

void ProcessDescription(chapter *chap, char *value)
{
	// ROBUST
	if (chap == NULL)
	{
		printf("Quelque chose ne vas pas avec chap(ProcessDescription)\n");
		exit(6);
	}
	// ROBUST
	if (value == NULL)
	{
		printf("Quelque chose ne vas pas avec value(ProcessDescription)\n");
		exit(7);
	}
	chap->description = set_text_property(chap->description, value);
	// remplit une chaîne de caractères tout en s'assurant que la mémoire allouée est suffisante
	//=> assigner une description(avec la valeur de 'value') à un chapitre
}

void ProcessAfterDescription(chapter *chap, char *value)
{
	// ROBUST
	if (chap == NULL)
	{
		printf("Quelque chose ne vas pas avec chap(ProcessAfterDescription)\n");
		exit(8);
	}
	// ROBUST
	if (value == NULL)
	{
		printf("Quelque chose ne vas pas avec value(ProcessAfterDescription)\n");
		exit(9);
	}
	chap->after_description = set_text_property(chap->after_description, value);
}
void ProcessEvent(chapter *chap, char *value, int counter)
{
	// ROBUST
	if (chap == NULL)
	{
		printf("Quelque chose ne vas pas avec chap(ProcessEvent)\n");
		exit(10);
	}
	// ROBUST
	if (value == NULL)
	{
		printf("Quelque chose ne vas pas avec value(ProcessEvent)\n");
		exit(11);
	}
	int a;
	if (counter == 1)
	{
		chap->event = malloc(2 * sizeof(Event));
	}
	// utiiser la fonction de louaye qui transforme un char en int et faire le switch avec
	switch (counter)
	{
	case 1:
		a = atoi(value);
		chap->event->type_event = a;
		break;
	case 2:
		a = atoi(value);
		chap->event->id_object = a;
		break;
	case 3:
		a = atoi(value);
		chap->event->n_fighter = a;
		break;
	case 4:
		a = atoi(value);
		chap->event->type_stat = a;
		break;
	case 5:
		a = atoi(value);
		chap->event->n_stat = a;
		break;
	case 6:
		a = atoi(value);
		chap->event->add_or_remove_bag = a;
		break;
	case 7:
		a = atoi(value);
		chap->event->positive_or_negative = a;
	case 8:
		a = atoi(value);
		chap->event->add_token = a;
	}
	// remplit event de la struct chapter avec la %s 'value' en utilisant 'fill_text_property'
	//=> ajouter des événements
}

void ProcessChoice(chapter *chap, char *value)
// =>Ce code est une fonction qui ajoute une option de choix à un chapitre d'une histoire interactive
{
	// ROBUST
	if (chap == NULL)
	{
		printf("Quelque chose ne vas pas avec chap(ProcessChoice)\n");
		exit(12);
	}
	// ROBUST
	if (value == NULL)
	{
		printf("Quelque chose ne vas pas avec value(ProcessChoice)\n");
		exit(13);
	}
	// ROBUST
	if (chap->choices == NULL)
	{ // gère la mémoire allouée pour stocker les choix dans la structure chapter
		// Si la liste des choix est vide (== NULL)
		chap->choices = (Choice *)malloc(1 * sizeof(Choice)); // alors un choix est alloué
		if (chap->choices == NULL)
		{
			printf("pb la ca va pas");
			exit(456);
		}
		chap->choice_count = 0;
	}
	else
	{
		Choice *temp = (Choice *)realloc(chap->choices, (chap->choice_count + 1) * sizeof(Choice));
		// ROBUST
		if (temp == NULL)
		{
			printf("Quelque chose ne vas pas avec temp(ProcessChoice)\n");
			exit(346);
		}
		// Sinon, un choix supplémentaire est alloué avec 'realloc' pour augmenter la taille de la liste des choix.
		if (temp != NULL)
		{
			chap->choices = temp;
		}
	}
	Choice ch = {0};
	if (ch.nextChapter != NULL)
	{
		printf("Y'a un truc qi va pas dans create_chapter");
		exit(45);
	}
	if (ch.text != NULL)
	{
		printf("Y'a un truc qui va pas encore dans create_chapter");
		exit(67);
	}
	// analyse la chaîne de caractères value en utilisant le délimiteur '_' et extrait chaque partie de la %s
	char delim[] = "_";
	char *cutteds = strtok(value, delim); // séparer la chaîne value en sous-chaînes en utilisant ces délimiteurs
	int i = 0;
	while (cutteds != NULL)
	// parcourt toutes les sous-chaînes et pour chaque sous-chaîne, elle fait une action différente en fonction de son index 'i'
	{
		if (i == 0) // nous remplissons la propriété text de notre choix avec la première sous-chaîne
		{
			ch.text = set_text_property(ch.text, cutteds);
			printf("\n");
		}
		else
		{ // nous créons un nouveau chapitre en utilisant la sous-chaîne courante
			cutteds = Remove_carriage_return(cutteds);
			ch.nextChapter = set_text_property(ch.nextChapter, cutteds);
			//printf("next chapter ptr = %s", ch.nextChapter);
			// ch.nextChapter = create_chapter(cutteds);
		}
		cutteds = strtok(NULL, delim);
		i++;
	}

	// ajoutons le choix 'ch' à la liste des choix dans le chapter actuel 'chap' en l'ajoutant à l'ind 'chap->choice_count' de la liste
	chap->choices[chap->choice_count] = ch; // incrémenter la valeur de 'chap->choice_count'
	chap->choice_count++;
}

chapter create_chapter(char *chapter_name)
{
	//ROBUST
	if(chapter_name == NULL)
	{
		printf("Quelque chose ne vas pas avec chapter_name(create_chapter)\n");
		exit(14);
	}
	// VARIABLES
	char line[SIZE_LINE];
	int current_line_event = 1;
	int currentPart = 0;

	char *path = NULL;
	//ROBUST
	if(path != NULL)
	{
		printf("Quelque chose ne vas pas avec path(create_chapter)\n");
		exit(15);
	}	
	//strlen("txt/") + 
	path = (char *)malloc((strlen("txt/") + strlen(chapter_name) + strlen(".txt")) * sizeof(char) + 1);
	//~~> contien le chemin d'accès au fichier txt que nous voulons ouvrir

	strcpy(path, "txt/");
	strcat(path, chapter_name); // suivie de 'chapter_name'(concaténation)
	strcat(path, ".txt");		// et de '.txt'

	FILE *file = fopen(path, "r");
	// crée un chemin vers le fichier txt à partir du nom du chapitre et stocke dans 'path'
	if (file == NULL)
	{
		printf("\nErreur fopen (file 1)\n");
		exit(1111);
	}

	// char buf[10] = "";
	chapter chap = {0}; // {malloc(1), malloc(0), malloc(0)};
	char first_line_chars[4];

	// GAME
	while (fgets(line, SIZE_LINE, file) != NULL)
	{
		*first_line_chars = '\0';
		strncat(first_line_chars, line, 3); // extrait les 3 premiers caractères en les stockant dans 'first_line_chars'
		if (strcmp(first_line_chars, "###") == 0)
		// Si ces 3 premiers caractères correspondent à 'part_seperator'
		{
			// Alors currentPart est incrémentée
			currentPart++;
		}
		else // Sinon utilisé pour traiter la ligne en fonction de la valeur de 'currentPart'
		{
			switch (currentPart)
			{
			// on est dans la part 1 : décrit la description du chapitre
			case 0:
				ProcessDescription(&chap, line);
				break;
			case 1:
				ProcessEvent(&chap, line, current_line_event);
				current_line_event++;
				break;

			// on est dans la part 2 : décrit l'événement du chapitre
			case 2:
				ProcessChoice(&chap, line);
				//~~> affiche l'événement en cours et les choix disponibles.
				break;

			case 3:
				ProcessAfterDescription(&chap, line);
				break;
			}
		}
	}
	fclose(file);

	return chap;
}

char *displayChapter(chapter chap, Stdt *main_character, char *next_chapter)
{
	if(next_chapter == NULL){
		printf("next_chapter est nul(game.c)");
		exit(4);
	}
	if(main_character == NULL){
		printf("main_character est nul (game.c)");
		exit(1);
	}
	// fighter1
	char name1[SIZE_NAMES] = "Adama";
	char sname1[SIZE_NAMES] = "Younga";
	Stdt fighter1 = createFighter(name1, sname1);
	// fighter2
	char name2[SIZE_NAMES] = "Eva";
	char sname2[SIZE_NAMES] = "Ansermin";
	Stdt fighter2 = createFighter(name2, sname2);
	
	Stdt tab_fighter[2] = {fighter1, fighter2};

	int lu;
	int user_choice = 0, count = 0;
	// printf("%s", chap.description);
	system("clear");
	displayTxt(strlen(chap.description), chap.description);
	printf("\n\n");
	scanf("%*[^\n]"); // Vider le flux d'entrée
	scanf("%*c");
	displayStat(*(main_character));
	WaitPress();
	// EVENT DU JEU
	switch (chap.event->type_event)
	{
	case 0:
		break;
	case 1:
		// combat contre un fighter
		displayBeforeFight(tab_fighter[chap.event->n_fighter], *(main_character));
		fight(*(main_character), tab_fighter[chap.event->n_fighter]);
		if(main_character->health == 0){
			return chap.choices[0].nextChapter;
		}
		return chap.choices[1].nextChapter;
		break;

	case 2:
		// modification de stat
		switch (chap.event->type_stat)
		{
		case 1:
			// fame
			if (chap.event->positive_or_negative == 1)
			{
				// c'est un malus de stat
				main_character->fame -= chap.event->n_stat;
				// Si une Stat inf à 0 alors remit à 0
				if (main_character->fame < 0)
				{
					main_character->fame = 0;
				}
				printf("Vous avez perdu %d de fame !\n", chap.event->n_stat);
			}
			else
			{
				// c'est un bonus de stat
				main_character->fame += chap.event->n_stat;
				// Si une Stat sup à 20 alors remit à 20
				if (main_character->fame > 20)
				{
					main_character->fame = 20;
				}
				printf("Vous avez gagné %d de fame !\n", chap.event->n_stat);
			}
			break;

		case 2:
			// intellect
			if (chap.event->positive_or_negative == 1)
			{
				// c'est un malus de stat
				main_character->intellect -= chap.event->n_stat * (main_character->fame / 10);
				// Si une Stat inf à 0 alors remit à 0
				if (main_character->intellect < 0)
				{
					main_character->intellect = 0;
				}
				printf("Vous avez perdu %d d'intelligence !\n", chap.event->n_stat);
			}
			else
			{
				// c'est un bonus de stat
				main_character->intellect += chap.event->n_stat * (main_character->fame / 10);
				// Si une Stat sup à 20 alors remit à 20
				if (main_character->intellect > 20)
				{
					main_character->intellect = 20;
				}
				printf("Vous avez gagné %d d'intelligence !\n", chap.event->n_stat);
			}
			break;
		case 3:
			// power
			if (chap.event->positive_or_negative == 1)
			{
				// c'est un malus de stat
				main_character->power -= chap.event->n_stat * (main_character->fame / 10);
				// Si une Stat inf à 0 alors remit à 0
				if (main_character->power < 0)
				{
					main_character->power = 0;
				}
				printf("Vous avez perdu %d de force !\n", chap.event->n_stat);
			}
			else
			{
				// c'est un bonus de stat
				main_character->power += chap.event->n_stat * (main_character->fame / 10);
				// Si une Stat sup à 20 alors remit à 20
				if (main_character->power > 20)
				{
					main_character->power = 20;
				}
				printf("Vous avez gagné %d de force !\n", chap.event->n_stat);
			}
			break;
		case 4:
			if (chap.event->positive_or_negative == 1)
			{
				// c'est un malus de stat
				main_character->wellness -= chap.event->n_stat * (main_character->fame / 10);
				// Si une Stat inf à 0 alors remit à 0
				if (main_character->wellness < 0)
				{
					main_character->wellness = 0;
				}
				printf("Vous avez perdu %d de mental !\n", chap.event->n_stat);
			}
			else
			{
				// c'est un bonus de stat
				main_character->wellness += chap.event->n_stat * (main_character->fame / 10);
				// Si une Stat sup à 20 alors remit à 20
				if (main_character->wellness > 20)
				{
					main_character->wellness = 20;
				}
				printf("Vous avez gagné %d de mental !\n", chap.event->n_stat);
			}
			break;
		}
	case 3:

		// modification inventaire
		if (chap.event->add_or_remove_bag == 1)
		{
			// c'est un malus de stat
			removeItem(main_character, chap.event->id_object);
			displayBag(main_character);
		}
		else
		{
			// c'est un ajout d'objet dans l'inventaire
			addItem(main_character, chap.event->id_object);
			displayBag(main_character);
		}
		break;
	
	case 4:
		displayStat(*(main_character));
		break;
	}
	
	if(chap.event->add_token == 1){
		main_character->token ++;
	}

	if(strcmp("15", next_chapter) == 0|| strcmp("23B", next_chapter) == 0|| strcmp("31B", next_chapter)== 0 ){
		if(main_character->fame < 15){
			return chap.choices[1].nextChapter;
		}
		return chap.choices[0].nextChapter;
	}

	if (chap.choice_count > 1)
	{
		for (int i = 0; i < chap.choice_count; i++)
		{
			printf("\n%s", chap.choices[i].text);
		}
		// CHOIX DU JEU
		user_choice = robust(chap.choice_count);
		system("clear");
		if(chap.after_description != NULL){
			displayTxt(strlen(chap.after_description), chap.after_description);
		}
		//printf("indx = %d\n", user_choice-1);
		
		return chap.choices[user_choice - 1].nextChapter;
	}
	else
	{
		if(chap.choice_count != 1){
			WaitPress();
		}
		if((strcmp(chap.choices[0].nextChapter, "33") == 0) && main_character->health == 0){
			char *rep;
			rep = (char *)malloc(3 * sizeof(char));
			if(rep == NULL){
				printf("l'allocation du chapitre pour le combat final a pas marchée (game.c)\n");
				exit(45);
			}
			strcpy(rep, "F2");
			
			return rep;
		}
		else if((strcmp(chap.choices[0].nextChapter, "33") == 0) && main_character->health > 0){
			char *rep;
			rep = (char *)malloc(3 * sizeof(char));
			if(rep == NULL){
				printf("l'allocation du chapitre pour le combat final a pas marchée (game.c)\n");
				exit(45);
			}
			strcpy(rep, "34");
			return rep;
		}
		
	}
		return chap.choices[0].nextChapter;
	}

int main()
{
//VALUES
    srand(time(NULL));
    int choice1;
    int verif = 1;
    int pourcentage;
    Stdt mainCharacter; 
	SaveData save;//créée le fichier de sauvegarde
    mainCharacter.bag_size = 0;
    createBag(&mainCharacter);//création du sac d'items 
    int start1, start2;
	int game = 1;
	char* next_chap = NULL;
//CREATION DE FICHIER
	start1 = pre_game();
	
	chapter ch = create_chapter("01");
	next_chap = set_text_property(next_chap, "01"); 
	//Choix d'une "Nouvelle Partie"
	if(start1 == 1)
	{
			displayLoading();
			//affichage de %tage en temps réelle
			system("clear");
			//CREATE STUDENTS
			char* txt1 = "Avant de commencer a jouer, vous allez saisir votre personnage principal\n\n";
			int size2 = strlen(txt1);
			displayTxt(size2, txt1);//Affichage de Txt1   

			mainCharacter = createMainCharacter(mainCharacter);//créée le personnage principal
			system("clear");
			displayStat(mainCharacter);//affiche les stats du personnage principal
			WaitPress(); //attends une action de l'utilisateur (ENTREE) pour afficher la suite
			system("clear");

			//VARIABLES 

		}		//ferme boucle de start == 1
		else if(start1 == 2){ //"Reprendre partie"
			//affichage de %tage en temps réelle
			displayLoading();
				
			if(is_save_txt_null() != 0){
				printf("Sauvegarde chargée avec succès !\n");
				sleep(1);
				system("clear"); 

				SaveData loadedData = loadGame();
				next_chap = Remove_carriage_return(loadedData.nxt_chap);
				ch = create_chapter(next_chap);

			} 
			else 
			{
				printf("Impossible de charger la sauvegarde!\n\n");
				start2 = no_game();
				if(start2 == 1){ //"Nouvelle Partie"
					displayLoading();
					//affichage de %tage en temps réelle
					system("clear");
					//CREATE STUDENTS
					char* txt1 = "Avant de commencer a jouer, vous allez saisir votre personnage principal\n\n";
					int size2 = strlen(txt1);
					displayTxt(size2, txt1);//Affichage de Txt1   

					mainCharacter = createMainCharacter(mainCharacter);//créée le personnage principal
					mainCharacter.token = 0;
					system("clear");
					displayStat(mainCharacter);//affiche les stats du personnage principal
					WaitPress(); //attends une action de l'utilisateur (ENTREE) pour afficher la suite
					system("clear");
					}
					else{
						//quitter le jeu
						system("clear");
						return 0;
					}
			}
		}
		else {
			system("clear");
			return 0;
		}
		while (game == 1){
			next_chap = displayChapter(ch, &mainCharacter, next_chap);
			free(ch.description);
			free(ch.after_description);
			save.main_character = mainCharacter;//actualisation du fichier de sauvegarde
			if(save.nxt_chap == NULL){
				save.nxt_chap = (char *)malloc(strlen(next_chap) * sizeof(char));
				if(save.nxt_chap == NULL){
					printf("allocation de save.nxt_chap échouée'main.c)");
					exit(5);
				}
			}
			save.nxt_chap = next_chap;
			ch = create_chapter(next_chap);
			SaveGame(&save);
			free(save.nxt_chap);

			if(next_chap == "F1" || next_chap == "F2" || next_chap == "F3" || next_chap == "F4"){
				game = 0;
			}
		}


		return 0;
}
