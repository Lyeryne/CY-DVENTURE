
#ifndef STRUCTURES_H
#define STRUCTURES_H

#define SIZE_NAMES 100
#define MAX_BAG_SIZE 8
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
	char Bag[MAX_BAG_SIZE][SIZE_NAMES];
	int bag_size;
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
	char *id_object;
	char *add_or_remove_bag;
    char *positive_or_negative;
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
    int selected_choice;//stocke l'option de choix sélectionnée par l'utilisateur
} SaveData;


#endif
