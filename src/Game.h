#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "Ball.h"
#include "Field.h"

/** @brief defining the Game structure , which takes a field and a ball */
typedef struct
{   /** a Field which is a structure pre defined */
	Field field;
	/** a Ball which is a structure pre defined */
	Ball ball;

} Game ;
/** @brief This Procedure initialize the game by allocating the ball and the field in the memory using ballInit and fieldInit
    @param gameP pointer on Game
    @param file that contains the map to draw
    */
void gameInit(Game *gameP,const char file[]);
/** @brief This Procedure set free the memory allocated for the game initialisation used by the previous Procedure
    @param gameP pointer on Game
    */
void gameFree(Game *gameP);
/** @brief Function to return the field used in the game
    @param gameP a pointer on the Game
    @return Field
    */
const Field *gameGetConstField(const Game *gameP);
/** @brief Function to return the Ball used in the game
    @param gameP a pointer on the Game
    @return Ball
    */
const Ball *gameGetConstBall(const Game *gameP);
/** @brief Procedure to move the Ball on the field according to the key pressed after veryfing the validity of the case we need to step on
    @param gameP pointer on Game
    @param val char the value used in the switch condition in order to define the movement position
    */
void gameKeyboard(Game * gameP, const char val);




#endif
