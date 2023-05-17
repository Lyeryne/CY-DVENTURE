all : Projet

Robust.o : Robust.c Robust.h
	gcc -c Robust.c -o Robust.o

DisplayTXT.o : DisplayTXT.c DisplayTXT.h
	gcc -c DisplayTXT.c -o DisplayTXT.o

Game.o : Game.c Game.h
	gcc -c Game.c -o Game.o

Save.o : Save.c Save.h
	gcc -c Save.c -o Save.o

Stdtcreate.o : Stdtcreate.c Stdtcreate.h
	gcc -c Stdtcreate.c -o Stdtcreate.o

main.o : main.c main.h
	gcc -c main.c -o main.o

statPlayer.o : statPlayer.h statPlayer.c
	gcc -c statPlayer.c -o statPlayer.o

structures.o : structures.h structures.c
	gcc -c structures.c -o structures.o

Projet : Robust.o DisplayTXT.o Game.o Save.o Stdtcreate.o main.o statPlayer.o structures.o
	gcc Robust.o DisplayTXT.o Game.o Save.o Stdtcreate.o main.o statPlayer.o structures.o -o Projet -lSDL2
