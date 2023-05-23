
#ifndef STRUCTURES_H
#define STRUCTURES_H

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
    chapter saveEvent;//stocke l'option de choix sélectionnée par l'utilisateur
} SaveData;

#endif
