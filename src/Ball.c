#include "Ball.h"

void ballInit(Ball * ballP)
{
	ballP->x = 1;
	ballP->y = 17;
}
void ballLeft(Ball * ballP, const Field * fieldP)
{
	if (fieldPosValid( fieldP, ballP->x-1, ballP->y))
		ballP->x--;
}

void ballRight(Ball * ballP, const Field * fieldP)
{
	if (fieldPosValid( fieldP, ballP->x+1, ballP->y))
		ballP->x++;
}


void ballUp(Ball * ballP, const Field * fieldP)
{
	if (fieldPosValid( fieldP, ballP->x, ballP->y-1))
		ballP->y--;
}

void ballDown(Ball * ballP, const Field * fieldP)
{
	if (fieldPosValid( fieldP, ballP->x, ballP->y+1))
		ballP->y++;
}
int ballGetX(const Ball * ballP)
{
	return ballP->x;
}

int ballGetY(const Ball * ballP)
{
	return ballP->y;
}
