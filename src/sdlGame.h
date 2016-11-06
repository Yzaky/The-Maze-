#ifndef _SDLGAME_H
#define _SDLGAME_H
#include<SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include "Game.h"
/** @brief defining the SDL structure used to display the game in graphics mode
  */

typedef struct
{   /** game pointer on Game*/
	Game game;
	/** an SDL surface to set the video mode */
	SDL_Surface* surface_screen;
	/** an SDL surface which takes an image and associate it to the ball */
	SDL_Surface* surface_ball;
    /** an SDL surface which takes an image and associate it to the wall */
	SDL_Surface* surface_wall;
    /** an SDL surface which takes an image and associate it to the end point */
    SDL_Surface* surface_end;
    /** an SDL surface which takes an image and associate it to the menu */
    SDL_Surface* surface_menu;
    /** an SDL surface which takes an image and associate it to the home button which appears when you win */
    SDL_Surface* surface_home;
    /** an SDL surface which takes an image and associate it to the winning image that appears when you win */
    SDL_Surface* surface_win1;
    /** an SDL surface which takes an image and associate it to the close button which appears when you win */
    SDL_Surface* surface_close;
    /** an SDL surface which takes an image and associate it to the restart button which appears when you win to restart the level */
    SDL_Surface* surface_restart;
    /** an SDL surface which takes an image and associate it to the about page which contains the developpers information*/
    SDL_Surface* surface_about;
} sdlGame;

/** @brief Procedure to initialize the game in graphics mode using SDL functions
    @param sdlGameP pointer on the Structure sdlGame
    @param file a pointer on the file that opens at the beginning
    */
void sdlGameInit(sdlGame *,const char* file);
/** @brief Procedure to set free the memory allocated for the game that was previously initialized
    @param sdlGameP pointer on the Structure sdlGame
    */
void sdlGameFree(sdlGame *);
/**  @brief Function used to move the ball according to the key taped , using the gameKeyboard function
    @param continue_loop int a boolean
    @param sdlGameP pointer on the Structure sdlGame
    */
int sdlKeymove(int *continue_loop, sdlGame *sdlGameP);
/** @brief Procedure which takes control of the menu loop using the private funciton sdlGameMenu which is the menu of the game with it's components
    @param sdlGame pointer on the Structure sdlGame
    */
void sdlGameLoopMenu(sdlGame *);
/** @brief Procedure which takes control of the third level of the Game
    @param sdlGameP pointer on the Structure sdlGame
    */
void sdlGameLoopLevel3(sdlGame *sdlGameP);
/** @brief Procedure which takes control of the second level of the Game
    @param sdlGameP pointer on the Structure sdlGame
    */
void sdlGameLoopLevel2(sdlGame *sdlGameP);
/** @brief Procedure which takes control of the first level of the Game
    @param sdlGameP pointer on the Structure sdlGame
    */
void sdlGameLoopLevel1(sdlGame *sdlGameP);
/** @brief Procedure which takes control of the about page using the sdlGameAbout private procedure
    @param sdlGameP pointer on the Structure sdlGame
    */
void sdlGameLoopAbout(sdlGame *sdlGameP);
/** @brief Procedure which display the winning image at the end when you win , with a return and restart button
    @param sdlGameP pointer on the Structure sdlGame
    @param refresh int for refreshment
    @param continue_loop int used as a boolean
    */
void sdlGameEnd(sdlGame* sdlGameP, int* refresh,int* continue_loop);

#endif
