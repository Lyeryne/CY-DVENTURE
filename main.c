#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "Process.h"

int main()
{
    system("clear");
    int game = 1;
    char* next_chap;
    chapter ch = create_chapter("Event1");
    while (game == 1)
    {

        //strcpy(next_chap, displayChapter(ch));

        next_chap= displayChapter(ch);
        ch = create_chapter(next_chap);
    }
    return 0;
}


