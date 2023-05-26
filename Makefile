OBJ_DIR := fichiers_o

all: Projet

$(OBJ_DIR)/Robust.o: Robust.c Robust.h
	gcc -c Robust.c -o $(OBJ_DIR)/Robust.o

$(OBJ_DIR)/DisplayTXT.o: DisplayTXT.c DisplayTXT.h
	gcc -c DisplayTXT.c -o $(OBJ_DIR)/DisplayTXT.o

$(OBJ_DIR)/Game.o: Game.c Game.h
	gcc -c Game.c -o $(OBJ_DIR)/Game.o

$(OBJ_DIR)/Save.o: Save.c Save.h
	gcc -c Save.c -o $(OBJ_DIR)/Save.o

$(OBJ_DIR)/Stdtcreate.o: Stdtcreate.c Stdtcreate.h
	gcc -c Stdtcreate.c -o $(OBJ_DIR)/Stdtcreate.o

$(OBJ_DIR)/main.o: main.c main.h 
	gcc -c main.c -o $(OBJ_DIR)/main.o 

$(OBJ_DIR)/statPlayer.o: statPlayer.c statPlayer.h
	gcc -c statPlayer.c -o $(OBJ_DIR)/statPlayer.o

$(OBJ_DIR)/structures.o: structures.c structures.h
	gcc -c structures.c -o $(OBJ_DIR)/structures.o

Projet: $(OBJ_DIR)/Robust.o $(OBJ_DIR)/DisplayTXT.o $(OBJ_DIR)/Game.o $(OBJ_DIR)/Save.o $(OBJ_DIR)/Stdtcreate.o $(OBJ_DIR)/main.o $(OBJ_DIR)/statPlayer.o $(OBJ_DIR)/structures.o
	gcc $(OBJ_DIR)/Robust.o $(OBJ_DIR)/DisplayTXT.o $(OBJ_DIR)/Game.o $(OBJ_DIR)/Save.o $(OBJ_DIR)/Stdtcreate.o $(OBJ_DIR)/main.o $(OBJ_DIR)/statPlayer.o $(OBJ_DIR)/structures.o -o Projet 
