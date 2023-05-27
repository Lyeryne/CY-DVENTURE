#include "main.h"

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
			free(next_chap);
			if(is_save_txt_null() != 0){
				printf("Sauvegarde chargée avec succès !\n");
				system("clear");

				SaveData loadedData = loadGame();
				mainCharacter = loadedData.main_character;
				next_chap = (char *)malloc(strlen(loadedData.nxt_chap) + 1);
				if(next_chap == NULL){
					printf("l'Allocation next_chap à échoué\n");
					exit(23);
				}
				strcpy(next_chap, loadedData.nxt_chap);
				ch = create_chapter(next_chap);
			} 
			else 
			{
				printf("Impossible de charger la sauvegarde!\n\n");
				start2 = no_game();

				//affichage de l'écran de départ 
				//libère l'espace du chapitre
				//retouve l'ancienne sauvegarde et la charge				
				//charge toutes les informations de la sauvegarde précédente//ROBUST
				//continue l'aventure là où elle était lancée	//sauvegarde inexistante				
 			if(start2 == 1){ //"Nouvelle Partie"
					displayLoading();
					//affichage de %tage en temps réelle
					system("clear");
					//CREATE STUDENTS
					char* txt1 = "Avant de commencer a jouer, vous allez saisir votre personnage principal\n\n";
					int size2 = strlen(txt1);
					displayTxt(size2, txt1);//Affichage de Txt1   

					mainCharacter = createMainCharacter(mainCharacter);//crée le personnage principal
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
			if(strcmp(next_chap, "F5") == 0){
				game = 0;
				break;
			}
			free(ch.description);
			free(ch.after_description);
			save.main_character = mainCharacter;//actualisation du fichier de sauvegarde
			if(save.nxt_chap == NULL){
				save.nxt_chap = (char *)malloc(strlen(next_chap) * sizeof(char));
				if(save.nxt_chap == NULL){
					printf("alocation de save.nxt_chap échouée(main.c)");
					exit(5);
				}
			}
			save.nxt_chap = next_chap;
			ch = create_chapter(next_chap);
			SaveGame(&save);
			free(save.nxt_chap);
		}
		return 0;
}

