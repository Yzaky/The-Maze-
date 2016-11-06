#include <stdio.h>
#include "sdlGame.h"
#include "ncursGame.h"
#include "menu.h"
#include <SDL/SDL.h>
#include<SDL/SDL_mixer.h>

/*This part is refered to the text mode
void GameLvl1()
{   const char* file="src/map1.txt";

    Game game2;
	 gameInit(&game2,file);
    ncursBoucle(&game2);
    gameFree(&game2);

    printf("End\n");

}

void GameLvl2()
{
    const char* file="src/map2.txt";
    Game game2;

    gameInit(&game2,file);
    ncursBoucle(&game2);
    gameFree(&game2);

    printf("End\n");
}

void GameLvl3()
{
    const char* file="src/map3.txt";

   Game game2;

    gameInit(&game2,file);
    ncursBoucle(&game2);
    gameFree(&game2);

    printf("End\n");
}


void Quit()
{
	printf("Game has ended\n");
	exit(0);
}

*/
int main ( int argc, char** argv )
{

/*
   	 Menu m;
	menuInit(&m);
	menuAjouterLigne(&m, "Play level 1", GameLvl1);
	menuAjouterLigne(&m, "Play level 2", GameLvl2);
	menuAjouterLigne(&m, "Play level 3", GameLvl3);
    menuAjouterLigne(&m, "Quit Game", Quit);
	menuLoop(&m);
	menuLibere(&m);*/

    sdlGame game;
	sdlGameLoopMenu( &game );
	sdlGameFree( &game );
	return 0;

}

