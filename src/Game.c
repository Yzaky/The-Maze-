#include "Game.h"
#include <malloc.h>
#include <stdlib.h>


void gameInit(Game *gameP,const char file[])
{

	ballInit(&(gameP->ball));
	fieldInit(&(gameP->field),file);

}

void gameFree(Game *gameP)
{
	fieldFree(&(gameP->field));
}



const Field *gameGetConstField(const Game *gameP)
{
	return &(gameP->field);
}

const Ball *gameGetConstBall(const Game *gameP)
{
	return &(gameP->ball);
}


void gameKeyboard(Game * gameP, const char val)
{
	switch(val)
	{
		case 'g' :
				ballLeft(&(gameP->ball), &(gameP->field));
				break;
		case 'd' :
				ballRight(&(gameP->ball), &(gameP->field));
				break;
		case 'h' :
				ballUp(&(gameP->ball), &(gameP->field));
				break;
		case 'b' :
				ballDown(&(gameP->ball), &(gameP->field));
				break;
	}
}



