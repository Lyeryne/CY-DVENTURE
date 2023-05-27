#include "Save.h"
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
    fclose(fp);
    fp = fopen("Save/save.txt", "w");
    if(fp == NULL){
        printf("Erreur fopen (file Save)\n");
        exit(11);
    }
    //STAT STDT

        fprintf(fp, "%s\n", data->main_character.sname);

        fprintf(fp, "%s\n", data->main_character.name);
    //QUE DE LA ROBUSTESSE
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
    {//ROBUST
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
    //ROBUST
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
        fscanf(fp, "%s\n", data.main_character.sname);

        fscanf(fp, "%s\n", data.main_character.name);

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
        fscanf(fp, "%[^\n]\n", buffer);
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
        data.nxt_chap = (char *)malloc((strlen(buffer) + 1)* sizeof(char));
        if(data.nxt_chap == NULL){
            printf("allocation échouée pour data.nxt_chap(loadGame)\n");
            exit(124);
        }
        strcpy(data.nxt_chap , buffer);
    }
    
    fclose(fp);

    return data;
}

