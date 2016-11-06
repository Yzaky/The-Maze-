#ifndef _BALL_H
#define _BALL_H

#include "Field.h"

/** @brief Structure Ball definition , which is about taking 2 positions x and y.*/

typedef struct
{   /** The abscissa coordinate of the ball */
	int x;
    /** The ordinate coordinate of the ball */
	int y;
} Ball;

/** @brief   This procedure will initialize the ball at the beginning of the map level
    @param ballP pointer on structure Ball
*/

void ballInit(Ball * ballP);
/** @brief ballUp verifies that the case above the ball is valid and the ball can step in
    @param ballP pointer on Ball
    @param fieldP pointer on Field
    */

void ballUp(Ball * ballP, const Field * fieldP);
/** @brief ballDown verifies that the case beneath the ball is valid and the ball can step in
     @param ballP pointer on Ball
    @param fieldP pointer on Field
    */

void ballDown(Ball * ballP, const Field * fieldP);
/** @brief ballLeft verifies that the case on the left of the ball is valid and the ball can step in
    @param ballP pointer on Ball
    @param fieldP pointer on Field
    */
void ballLeft(Ball * ballP, const Field * fieldP);
/** @brief ballRight verifies that the case on the right of the ball is valid and the ball can step in
    @param ballP pointer on Ball
    @param fieldP pointer on Field
    */

void ballRight(Ball * ballP, const Field * fieldP);
/** @brief This function returns the ball's position on the abscissa axe
    @param ballP pointer on Ball
    @return ballP->x
    */

int ballGetX(const Ball * ballP);
/** @brief This function returns the ball's position on the ordinate axe
    @param ballP pointer on Ball
    @return ballP->y
    */
int ballGetY(const Ball * ballP);


#endif
