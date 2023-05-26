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
				
			char *file;
			file = (char *)malloc((strlen("Save") + strlen(".txt")) * sizeof(char) +1);
			strcpy(file, "Save");
			strcat(file, ".txt");
			if(is_txt_null(file) != 0){
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
			save.main_character = mainCharacter;//actualisation du fichier de sauvegarde
			if(save.nxt_chap == NULL){
				save.nxt_chap = (char *)malloc(strlen(next_chap) * sizeof(char));
			}
			save.nxt_chap = next_chap;
			ch = create_chapter(next_chap);
			printf("%d", save.main_character.fame);
			fflush(stdout);
			SaveGame(&save);
			free(save.nxt_chap);
			if(next_chap == "F1" || next_chap == "F2" || next_chap == "F3" || next_chap == "F4"){
				game = 0;
			}
		}


		return 0;
}
