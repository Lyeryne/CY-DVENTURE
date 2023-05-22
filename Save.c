#include "Save.h"
void SaveGame(SaveData* data){
    FILE* fp = fopen("txt/save.txt", "w");
    if(fp == NULL){
        printf("Erreur fopen (file Save)\n");
        exit(11);
    }

    //STAT
    fprintf(fp, "%d\n", data->main_character.fame);
    fprintf(fp, "%d\n", data->main_character.power);
    fprintf(fp, "%d\n", data->main_character.intellect);
    fprintf(fp, "%d\n", data->main_character.wellness);
    fprintf(fp, "%d\n", data->main_character.health);
    fprintf(fp, "%d\n", data->main_character.dodge);
    fprintf(fp, "%d\n", data->main_character.defence);
    
    //BAG
    fprintf(fp, "%d\n", data->main_character.bag_size);
    for (int i = 0; data->main_character.bag_size; i++)
    {
    	fprintf(fp, "Votre Sac : %s\n", data->main_character.Bag[i]);
    } 

    //CHOICES
    fprintf(fp, "selected_choice:%d\n", data->saveEvent.choice_count);

    fclose(fp);
}

SaveData loadGame() {
	SaveData data;
    FILE* fp = fopen("txt/save.txt", "r");
    if (fp == NULL) {
        printf("Erreur fopen (file LoadGame)\n");
        exit(111);
    }

    //STAT
    if (fscanf(fp, "%d", &(data.main_character.fame)) != 1 ||
        fscanf(fp, "%d", &(data.main_character.power)) != 1 ||
        fscanf(fp, "%d", &(data.main_character.intellect)) != 1 ||
        fscanf(fp, "%d", &(data.main_character.wellness)) != 1 || 
        fscanf(fp, "%d", &(data.main_character.health)) != 1 ||
        fscanf(fp, "%d", &(data.main_character.dodge)) != 1 ||
        fscanf(fp, "%d", &(data.main_character.defence)) != 1) {
        printf("Erreur de lecture des données de stat\n");
        fclose(fp);
        exit(1);
    }

	fclose(fp);
    //BAG
    return data;
}

