all : Projet

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

structures.o : structures.h
    gcc -o structures.o

Projet : Robust.o DisplayTXT.o Game.o Save.o Stdcreate.o main.o StatPlayer.o structures.o
    gcc Robust.o DisplayTXT.o Game.o Save.o Stdcreate.o main.o StatPlayer.o structures.o -o Projet