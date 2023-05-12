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
} Stdt; // Main character

typedef enum
{
  //intellect stuff
  Pencil, Book, Computer,
  //power stuff
  Knife, Knuckles, 
  //fame stuff
  Sunglasses, Jacket,
  //wellness stuff
  Girlfriend,
  //empty
  Vide  
} Bag; // Items

typedef struct
{
	char *text;
	char *nextChapter;
} Choice;

typedef struct
{
	char *type_event;
	char *fighter;
	char *stat;
	char* statation;
} Event;

typedef struct
{
    char *description;
    Event *event;
    Choice *choices;
    int choice_count;
} chapter;



typedef struct 
{
    Stdt a;
    Bag b;
    int selected_choice;//stocke l'option de choix sélectionnée par l'utilisateur
} SaveData;

