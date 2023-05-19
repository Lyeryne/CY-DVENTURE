<<<<<<< HEAD
all : exec

Robust.o : Robust.c Robust.h
    gcc -c Robust.c -o Robust.o

DisplayTXT.o : DisplayTXT.c DisplayTXT.h
    gcc -c DisplayTXT.c -o DisplayTXT.o

Game.o : Game.c Game.h
    gcc -c Game.c -o Game.o

Save.o : Save.c Save.h
    gcc -c Save.c -o Save.o

Stdcreate.o : Stdcreate.c Stdcreate.h
    gcc -c Stdcreate.c -o Stdcreate.o

main.o : main.c main.h
    gcc -c main.c -o main.h

StatPlayer.o : StatPlayer.h StatPlayer.c
    gcc -c StatPlayer.c -o StatPlayer.o

structures.o : structures.c structures.h
    gcc -c structures.c -o structures.o

exec : Robust.o DisplayTXT.o Game.o Save.o Stdcreate.o main.o StatPlayer.o structures.o
    gcc Robust.o DisplayTXT.o Game.o Save.o Stdcreate.o main.o StatPlayer.o structures.o -o exec
=======
OBJ_DIR := fichiers.o

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
>>>>>>> a4478b96ea9464db03bfd293e53d51f5c4dd41e0
