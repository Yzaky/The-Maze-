#include <stdio.h>
#ifdef WIN32
#else
#include <ncurses.h>
#include "ncursGame.h"
#endif
#include <assert.h>
#include <time.h>
#include "Game.h"

void ncursAff( WINDOW* win, const Game *gameP)
{
	int x,y;

	const Field *fieldP = gameGetConstField(gameP);
    const Ball *ballP = gameGetConstBall(gameP);


	wclear(win);


	for(x=0;x<fieldGetDimX(fieldP);++x)
		for(y=0;y<fieldGetDimY(fieldP);++y)
			mvwprintw( win, y, x, "%c", fieldGetXY(fieldP,x,y) );

	mvwprintw( win, ballGetY(ballP), ballGetX(ballP), "*");
	wmove( win, ballGetY(ballP), ballGetX(ballP));
}

void ncursBoucle(Game *gameP)
{
	WINDOW *win;
	int c;
	int continue_boucle;

	initscr();
	clear();
	noecho();
	cbreak();

	win = newwin( fieldGetDimY(gameGetConstField(gameP)), fieldGetDimX(gameGetConstField(gameP)), 10, 5 );
	keypad(win, TRUE);
	nodelay(win,true);

	continue_boucle = 1;

    ncursAff( win, gameP);

	do
	{
		c = wgetch(win);

		switch(c)
		{
			case KEY_LEFT:
				gameKeyboard( gameP, 'g');
				ncursAff( win, gameP);
				break;
			case KEY_RIGHT:
				gameKeyboard( gameP, 'd');
				ncursAff( win, gameP);
				break;
			case KEY_UP:
				gameKeyboard( gameP, 'h');
				ncursAff( win, gameP);
				break;
			case KEY_DOWN:
				gameKeyboard( gameP, 'b');
				ncursAff( win, gameP);
				break;
			case 27:
				continue_boucle = 0;
				break;
		}
	} while (continue_boucle==1);



	endwin();
}
