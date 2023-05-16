#include "Game.h"

int pre_game()
{
    int start, lu;
    system("clear");
    printf("Webtoon MI5\n");
    sleep(1);
    char *txt = "Produit par\n-> Louaye SAGHIR\n-> Clement PREMOLI\n-> Roman BOULLIER\n\n";
    int size = strlen(txt);
    displayTxt(size, txt);
    sleep(1);
    system("clear");
    // Choix de partie
    printf("========= MENU ========\n"); // ASCI ART
    printf(" 1 -> Nouvelle Partie\n");   // ASCI ART
    printf(" 2 -> Reprendre Partie\n");  // ASCI ART
    printf(" 3 -> Quitter le Jeu\n\n");  // ASCI ART
    printf("Choix :");
    lu = scanf("%d", &start);
    while (start < 1 && start > 3 && lu == 0)
    {
        fflush(stdin);
        printf("Entrez votre choix : ");
        scanf("%d", &start);
    }
    sleep(1);
    system("clear");

    return start;
}

int no_game()
{
    int start, lu;
    system("clear");
    printf("========= MENU ==========\n"); // ASCI ART
    printf("1 -> Nouvelle Partie\n");      // ASCI ART
    printf("~~ ACCES NON-AUTORISER ~~\n"); // ASCI ART
    printf("2 -> Quitter le Jeu\n\n");     // ASCI ART
    printf("Choix :");
    lu = scanf("%d", &start);
    while (start < 1 && start > 2 && lu == 0)
    {
        fflush(stdin);
        printf("Entrez votre choix : ");
        scanf("%d", &start);
    }
    sleep(1);
    system("clear");

    return start;
}
char *set_text_property(char *buf, char *value)
//=>permet de remplir une propriété de type char * (%s) d'une structure de manière dynamique
{
    int length;
    if (buf == NULL) // propriété n'est pas initialisée
    {
        length = strlen(value) + 1;
        buf = (char *)malloc(length * sizeof(char)); // allocation pour stocker 'value' et copie cette valeur dans 'buf'
        strcpy(buf, value);                          // copier la %s 'value' dans le tampon 'buf'
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
    chap->description = set_text_property(chap->description, value);
    // remplit une chaîne de caractères tout en s'assurant que la mémoire allouée est suffisante
    //=> assigner une description(avec la valeur de 'value') à un chapitre
}

void ProcessAfterDescription(chapter *chap, char *value)
{
    chap->after_description = set_text_property(chap->after_description, value);
}

void ProcessEvent(chapter *chap, char *value, int counter)
{
    int a,b,c,d;
    // utiiser la fonction de louaye qui transforme un char en int et faire le switch avec
	if(counter == 1)
{
	chap->event = malloc(1 * sizeof(Event));
}
    switch (counter)
    {
    case 1:
        a = atoi(value);
        chap->event->type_event = a;
        break;
    case 2:
        chap->event->id_object = (char *)malloc(1 * sizeof(char));
        chap->event->id_object = set_text_property(chap->event->id_object, value);
        break;
    case 3:
        b = atoi(value);
        chap->event->n_monster = b;
        break;
    case 4:
        c = atoi(value);
        chap->event->type_stat = c;
        break;
    case 5:
        d = atoi(value);
        chap->event->n_stat = d;
        break;
    case 6:
        chap->event->add_or_remove_bag = (char *)malloc(1 * sizeof(char));
        chap->event->add_or_remove_bag = set_text_property(chap->event->add_or_remove_bag, value);
        break;
    }
    // remplit event de la struct chapter avec la %s 'value' en utilisant 'fill_text_property'
    //=> ajouter des événements
}

void ProcessChoice(chapter *chap, char *value)
// =>Ce code est une fonction qui ajoute une option de choix à un chapitre d'une histoire interactive
{
    if (chap->choices == NULL)
    { // gère la mémoire allouée pour stocker les choix dans la structure chapter
        // Si la liste des choix est vide (== NULL)
        chap->choice_count = 0;
        chap->choices = (Choice *)malloc(1 * sizeof(choice)); // alors un choix est alloué
    }
    else
    {
        Choice *temp = (Choice *)realloc(chap->choices, (chap->choice_count + 1) * sizeof(choice));
        // Sinon, un choix supplémentaire est alloué avec 'realloc' pour augmenter la taille de la liste des choix.
        if (temp != NULL)
        {
            chap->choices = temp;
        }
    }
    Choice ch = {};
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
            cutteds[strlen(cutteds) - 1] = '\0';
            ch.nextChapter = set_text_property(ch.nextChapter, cutteds);
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
    // VARIABLES
    char line[SIZE_LINE];
    int current_line_event = 0;
    int currentPart = 0;
    char *path = (char *)malloc((strlen("txt/") + strlen(chapter_name) + strlen(".txt")) * sizeof(char) + 1);
    //~~> contien le chemin d'accès au fichier txt que nous voulons ouvrir

    strcpy(path, "txt/");       // copie la chaîne 'txt' dans chaîne 'path'
    strcat(path, chapter_name); // suivie de 'chapter_name'(concaténation)
    strcat(path, ".txt");       // et de '.txt'

    FILE *file = fopen(path, "r");
    // crée un chemin vers le fichier txt à partir du nom du chapitre et stocke dans 'path'

    // FILE *file = fopen("../txt/Event1.txt", "r");
    if (file == NULL)
    {
        printf("\nErreur fopen (file 1)\n");
        exit(1);
    }

    // char buf[10] = "";
    chapter chap = {}; // {malloc(1), malloc(0), malloc(0)};
    char first_line_chars[4];

    // GAME
    while (fgets(line, SIZE_LINE, file) != NULL)
    {
        *first_line_chars = '\0';
        strncat(first_line_chars, line, 3); // extrait les 3 premiers caractères en les stockant dans 'first_line_chars'
        if (strcmp(first_line_chars, part_seperator) == 0)
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

                ProcessDescription(&chap, line);
                break;
            }
        }
    }
    fclose(file);

    return chap;
}

char *displayChapter(chapter chap, Stdt main_character, Bag *MyBag)
{
	 MyBag[MAX_BAG_SIZE] = Pencil, Book, Computer, Knife, Knuckles, Sunglasses, Jacket, Girlfriend;
	// fighter1
	char name1[SIZE_NAMES] = "Boris";
	char sname1[SIZE_NAMES] = "Jackson";
	Stdt fighter1 = createFighter(name1, sname1);
	// fighter2
	char name2[SIZE_NAMES] = "Adama";
	char sname2[SIZE_NAMES] = "Younga";
	Stdt fighter2 = createFighter(name2, sname2);
	// fighter3
	char name3[SIZE_NAMES] = "Etienne";
	char sname3[SIZE_NAMES] = "Wojdilot";
	Stdt fighter3 = createFighter(name3, sname3);
	// fighter4
	char name4[SIZE_NAMES] = "Lucas";
	char sname4[SIZE_NAMES] = "Traoré";
	Stdt fighter4 = createFighter(name4, sname4);
	Stdt tab_fighter[4] = {fighter1, fighter2, fighter3, fighter4};
	int lu;
	int user_choice = 0, count = 0;
	// printf("%s", chap.description);
	displayTxt(strlen(chap.description), chap.description);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~XTECH DVENTURE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

	// EVENT DU JEU
	switch (chap.event->type_event)
	{

	case 0:
        WaitPress();
    	break;
	case 1:
		// combat contre un monstre

		fight(main_character, tab_fighter[chap.event->n_monster]);
		break;

	case 2:
		// modification de stat
		switch (chap.event->type_stat)
		{
		case 1:
			// fame
			if (chap.event->positive_or_negative == "1")
			{
				// c'est un malus de stat
				main_character.fame -= chap.event->n_stat;
				// Si une Stat inf à 0 alors remit à 0
				if (main_character.fame < 0)
				{
					main_character.fame = 0;
				}
			}
			else
			{
				// c'est un bonus de stat
				main_character.fame += chap.event->n_stat;
				// Si une Stat sup à 100 alors remit à 100
				if (main_character.fame > 100)
				{
					main_character.fame = 100;
				}
			}
			break;

		case 2:
			// intellect
			if (chap.event->positive_or_negative == "1")
			{
				// c'est un malus de stat
				main_character.intellect -= chap.event->n_stat;
				// Si une Stat inf à 0 alors remit à 0
				if (main_character.intellect < 0)
				{
					main_character.intellect = 0;
				}
			}
			else 
			{
				// c'est un bonus de stat
				main_character.intellect += chap.event->n_stat;
				// Si une Stat sup à 100 alors remit à 100
				if (main_character.fame > 100)
				{
					main_character.fame = 100;
				}
			}
			break;
		case 3:
			// power
			if (chap.event->positive_or_negative == "1")
			{
				// c'est un malus de stat
				main_character.power -= chap.event->n_stat;
				// Si une Stat inf à 0 alors remit à 0
				if (main_character.intellect < 0)
				{
					main_character.intellect = 0;
				}
			}
			else
			{
				// c'est un bonus de stat
				main_character.power += chap.event->n_stat;
				// Si une Stat sup à 100 alors remit à 100
				if (main_character.fame > 100)
				{
					main_character.fame = 100;
				}
			}
			break;
		case 4:
			if (chap.event->positive_or_negative == "1")
			{
				// c'est un malus de stat
				main_character.wellness -= chap.event->n_stat;
				// Si une Stat inf à 0 alors remit à 0
				if (main_character.intellect < 0)
				{
					main_character.intellect = 0;
				}
			}
			else
			{
				// c'est un bonus de stat
				main_character.wellness += chap.event->n_stat;
				// Si une Stat sup à 100 alors remit à 100
				if (main_character.fame > 100)
				{
					main_character.fame = 100;
				}
			}
		}
	case 3:
		// modification inventaire
		if (chap.event->add_or_remove_bag == "1")
		{
			// c'est un malus de stat
			main_character.power -= chap.event->n_stat;
		}
		else
		{
			// c'est un bonus de stat
			main_character.power += chap.event->n_stat;
		}
		break;
	}

	if (chap.choice_count != 1)
	{
		for (int i = 0; i < chap.choice_count; i++)
		{
			printf("\n%s", chap.choices[i].text);
		}
		// CHOIX DU JEU
		do
		{
			printf("Choix :\n");
			lu = scanf("%d", &user_choice);
			fflush(stdin);
			if (user_choice < 1 || user_choice > chap.choice_count)
			{
				printf("Veuillez saisir une reponse valide : ");
			}
			else
			{
				count = 1;
			}
		} while (lu == 0 || count == 0);

		system("clear");
		displayTxt(strlen(chap.after_description), chap.after_description);
		return chap.choices[user_choice - 1].nextChapter;
	}
	else
	{
    	WaitPress();
		return chap.choices[0].nextChapter;
	}
	

}
