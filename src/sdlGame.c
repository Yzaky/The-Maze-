#include <assert.h>
#include <time.h>
#include "sdlGame.h"
#include "Game.h"
#include<SDL/SDL_mixer.h>




const int TAILLE_SPRITE=32;

SDL_Surface *SDL_load_image(const char* filename );
void SDL_apply_surface( SDL_Surface* source, SDL_Surface* destination, int x, int y );

void sdlGameInit(sdlGame *sdlGameP,const char *file)

{

	Game *gameP;
	int dimX, dimY;

	gameP = &(sdlGameP->game);
	gameInit(gameP,file);

	assert(   SDL_Init( SDL_INIT_EVERYTHING )!= -1 );

	dimX = fieldGetDimX( gameGetConstField(gameP) );
	dimY = fieldGetDimY( gameGetConstField(gameP)  );
	dimX = dimX * TAILLE_SPRITE;
	dimY = dimY * TAILLE_SPRITE;
	sdlGameP->surface_screen = SDL_SetVideoMode(   dimX, dimY, 32, SDL_SWSURFACE );
	assert( sdlGameP->surface_screen!=NULL);
	SDL_WM_SetCaption( "TheMaze", NULL );

	sdlGameP->surface_ball = SDL_load_image("data/ball.bmp");
	if (sdlGameP->surface_ball==NULL)
		sdlGameP->surface_ball = SDL_load_image("../data/ball.bmp");
	assert( sdlGameP->surface_ball!=NULL);


	sdlGameP->surface_wall = SDL_load_image("data/Wall.bmp");
	if (sdlGameP->surface_wall==NULL)
		sdlGameP->surface_wall = SDL_load_image("../data/Wall.bmp");
	assert( sdlGameP->surface_wall!=NULL);

    sdlGameP->surface_end = SDL_load_image("data/door.bmp");
	if (sdlGameP->surface_end==NULL)
		sdlGameP->surface_end = SDL_load_image("../data/door.bmp");
	assert( sdlGameP->surface_end!=NULL);

    sdlGameP->surface_menu = SDL_load_image("data/menu.bmp");
	if (sdlGameP->surface_menu==NULL)
		sdlGameP->surface_menu = SDL_load_image("../data/menu.bmp");
	assert( sdlGameP->surface_menu!=NULL);

    sdlGameP->surface_about = SDL_load_image("data/about.bmp");
	if (sdlGameP->surface_about==NULL)
		sdlGameP->surface_about = SDL_load_image("../data/about.bmp");
	assert( sdlGameP->surface_about!=NULL);

	  sdlGameP->surface_close= SDL_load_image("data/exit1.bmp");
	if (sdlGameP->surface_close==NULL)
		sdlGameP->surface_close= SDL_load_image("../data/exit1.bmp");
	assert( sdlGameP->surface_close!=NULL);

    sdlGameP->surface_win1 = SDL_load_image("data/winner.bmp");
    SDL_SetColorKey(sdlGameP->surface_win1,SDL_SRCCOLORKEY,SDL_MapRGB(sdlGameP->surface_win1->format,0,249,0));
	if (sdlGameP->surface_win1==NULL){
		sdlGameP->surface_win1 = SDL_load_image("../data/winner.bmp");
        SDL_SetColorKey(sdlGameP->surface_win1,SDL_SRCCOLORKEY,SDL_MapRGB(sdlGameP->surface_win1->format,0,249,0));
    }
	assert( sdlGameP->surface_win1!=NULL);

    sdlGameP->surface_home = SDL_load_image("data/home.bmp");
    SDL_SetColorKey(sdlGameP->surface_home,SDL_SRCCOLORKEY,SDL_MapRGB(sdlGameP->surface_home->format,255,255,255));

	if (sdlGameP->surface_home==NULL){
		sdlGameP->surface_home = SDL_load_image("../data/home.bmp");
        SDL_SetColorKey(sdlGameP->surface_home,SDL_SRCCOLORKEY,SDL_MapRGB(sdlGameP->surface_home->format,255,255,255));
    }
	assert( sdlGameP->surface_close!=NULL);

    sdlGameP->surface_restart = SDL_load_image("data/restart.bmp");
    SDL_SetColorKey(sdlGameP->surface_restart,SDL_SRCCOLORKEY,SDL_MapRGB(sdlGameP->surface_restart->format,255,255,255));

	if (sdlGameP->surface_restart==NULL){
		sdlGameP->surface_restart = SDL_load_image("../data/restart.bmp");
        SDL_SetColorKey(sdlGameP->surface_restart,SDL_SRCCOLORKEY,SDL_MapRGB(sdlGameP->surface_restart->format,255,255,255));
    }
	assert( sdlGameP->surface_restart!=NULL);
}



void sdlGameMonitor(sdlGame *sdlGameP)
{
	int x,y;

    const Game *gameP = &(sdlGameP->game);
	const Field *fieldP = gameGetConstField(gameP);
	const Ball *ballP = gameGetConstBall(gameP);

	SDL_FillRect( sdlGameP->surface_screen, &sdlGameP->surface_screen->clip_rect, SDL_MapRGB( sdlGameP->surface_screen->format, 0x00, 0x00, 0x00 ) );

	for (x=0;x<fieldGetDimX(fieldP);x++)
		for (y=0;y<fieldGetDimY(fieldP);y++)
			if (fieldGetXY(fieldP,x,y)=='#')
				SDL_apply_surface(  sdlGameP->surface_wall, sdlGameP->surface_screen, x*TAILLE_SPRITE, y*TAILLE_SPRITE);

for (x=0;x<fieldGetDimX(fieldP);x++)
		for (y=0;y<fieldGetDimY(fieldP);y++)
			if (fieldGetXY(fieldP,x,y)=='?')
				SDL_apply_surface(  sdlGameP->surface_end, sdlGameP->surface_screen, x*TAILLE_SPRITE, y*TAILLE_SPRITE);

	SDL_apply_surface(  sdlGameP->surface_ball, sdlGameP->surface_screen, ballGetX(ballP)*TAILLE_SPRITE,  ballGetY(ballP)*TAILLE_SPRITE );
}

void sdlGameAbout(sdlGame* sdlGameP, int* refresh,int* continue_loop)
{
    int x,y;
    SDL_apply_surface( sdlGameP->surface_about, sdlGameP->surface_screen,0,0);
    SDL_apply_surface( sdlGameP->surface_close, sdlGameP->surface_screen,0,0);
    SDL_Flip( sdlGameP->surface_screen );
    SDL_GetMouseState(&x,&y);
    SDL_PumpEvents();
        SDL_GetMouseState(&x,&y);
    if (x>0 && x<70 && y>548     && y<607 && (SDL_GetMouseState(NULL,NULL)&SDL_BUTTON(1)))
    {
        *continue_loop = 2;
        sdlGameLoopMenu(sdlGameP);

     }

     	     if (x>0 && x<31 && y>0 && y<33 && (SDL_GetMouseState(NULL,NULL)&SDL_BUTTON(1)))
    {
        *continue_loop = 0;
    }


    *refresh=0;
}

void sdlGameMenu(sdlGame* sdlGameP, int* refresh,int* continue_loop)
{
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,2,1024);
    Mix_Music* music;
    music=Mix_LoadMUS("data/music.wav");
    Mix_PlayMusic(music,-1);

    int x,y;
    SDL_apply_surface( sdlGameP->surface_menu, sdlGameP->surface_screen,0,0);
    SDL_apply_surface( sdlGameP->surface_close, sdlGameP->surface_screen,0,0);

    SDL_Flip( sdlGameP->surface_screen );
    SDL_GetMouseState(&x,&y);
    SDL_PumpEvents();
        SDL_GetMouseState(&x,&y);

    SDL_PumpEvents();

    if (x>361 && x<576 && y>211 && y<254 && (SDL_GetMouseState(NULL,NULL)&SDL_BUTTON(1)))
    {
        const char* file="src/map1.txt";
        sdlGameInit(sdlGameP,file);
        *continue_loop=1;
        sdlGameLoopLevel1( sdlGameP );
     }


    if (x>364 && x<587 && y>299 && y<339 && (SDL_GetMouseState(NULL,NULL)&SDL_BUTTON(1)))
    {
        const char* file="src/map2.txt";
        sdlGameInit(sdlGameP,file);
        *continue_loop=1;
        sdlGameLoopLevel2( sdlGameP );

	 }

    if (x>360 && x<582 && y>385 && y<425 && (SDL_GetMouseState(NULL,NULL)&SDL_BUTTON(1)))
    {
        const char* file="src/map3.txt";
        sdlGameInit(sdlGameP,file);
        *continue_loop=1;
        sdlGameLoopLevel3( sdlGameP );

	 }

	     if (x>313 && x<617 && y>470 && y<514 && (SDL_GetMouseState(NULL,NULL)&SDL_BUTTON(1)))
    {

        *continue_loop=3;
        sdlGameLoopAbout(sdlGameP);

	 }

	     if (x>0 && x<31 && y>0 && y<33 && (SDL_GetMouseState(NULL,NULL)&SDL_BUTTON(1)))
    {
        *continue_loop = 0;
    }

    Mix_FreeMusic(music);
        *refresh=0;

}
void sdlGameLoopAbout(sdlGame *sdlGameP)
{

	int continue_loop = 3;

    int refresh;


	sdlGameMonitor(sdlGameP);
	assert( SDL_Flip( sdlGameP->surface_screen )!=-1 );



        while (continue_loop == 3)
    {
        refresh = 0;
        sdlGameAbout(sdlGameP,&refresh,&continue_loop);

    }


}

void sdlGameLoopMenu(sdlGame *sdlGameP)
{
    const char* file="src/map0.txt";
    sdlGameInit(sdlGameP,file);
	int continue_loop = 2;

    int refresh;


	sdlGameMonitor(sdlGameP);
	assert( SDL_Flip( sdlGameP->surface_screen )!=-1 );



        while (continue_loop == 2)
    {
        refresh = 0;
        sdlGameMenu(sdlGameP,&refresh,&continue_loop);

    }


}


void sdlGameLoopLevel3(sdlGame *sdlGameP)
{

	int continue_loop = 1;

    float horloge_courante_carre, horloge_precedente_carre;

    float intervalle_horloge_carre = 0.07f;
    int refresh;


	sdlGameMonitor(sdlGameP);
	assert( SDL_Flip( sdlGameP->surface_screen )!=-1 );


    horloge_precedente_carre = (float)clock()/(float)CLOCKS_PER_SEC;


	while ( continue_loop == 1 )
	{

                refresh = 0;


                horloge_courante_carre = (float)clock()/(float)CLOCKS_PER_SEC;

                        if (horloge_courante_carre-horloge_precedente_carre>=intervalle_horloge_carre)
                        {
                            sdlKeymove(&continue_loop,sdlGameP);
                            horloge_precedente_carre = horloge_courante_carre;
                            refresh = 1;
                        }



                        if (horloge_courante_carre-horloge_precedente_carre>=intervalle_horloge_carre)
                        {
                            sdlKeymove(&continue_loop,sdlGameP);


                            horloge_precedente_carre = horloge_courante_carre;
                            refresh = 1;
                        }

                    if(sdlGameP->game.ball.x==28 && sdlGameP->game.ball.y==1)
                    {

                        sdlGameEnd(sdlGameP,&refresh,&continue_loop);

                    }


                    if (refresh==1)
                        {

                            sdlGameMonitor(sdlGameP);


                            SDL_Flip( sdlGameP->surface_screen );
                        }

	}

}

void sdlGameLoopLevel2(sdlGame *sdlGameP)
{

	int continue_loop = 1;

    float horloge_courante_carre, horloge_precedente_carre;

    float intervalle_horloge_carre = 0.07f;
    int refresh;


	sdlGameMonitor(sdlGameP);
	assert( SDL_Flip( sdlGameP->surface_screen )!=-1 );


    horloge_precedente_carre = (float)clock()/(float)CLOCKS_PER_SEC;


	while ( continue_loop == 1 )
	{

                refresh = 0;


                horloge_courante_carre = (float)clock()/(float)CLOCKS_PER_SEC;

                        if (horloge_courante_carre-horloge_precedente_carre>=intervalle_horloge_carre)
                        {
                            sdlKeymove(&continue_loop,sdlGameP);
                            horloge_precedente_carre = horloge_courante_carre;
                            refresh = 1;
                        }



                        if (horloge_courante_carre-horloge_precedente_carre>=intervalle_horloge_carre)
                        {
                            sdlKeymove(&continue_loop,sdlGameP);


                            horloge_precedente_carre = horloge_courante_carre;
                            refresh = 1;
                        }

                    if(sdlGameP->game.ball.x==28 && sdlGameP->game.ball.y==1)
                    sdlGameEnd(sdlGameP,&refresh,&continue_loop);

                    if (refresh==1)
                        {

                            sdlGameMonitor(sdlGameP);


                            SDL_Flip( sdlGameP->surface_screen );
                        }

	}

}


void sdlGameLoopLevel1(sdlGame *sdlGameP)
{

	int continue_loop = 1;


    float horloge_courante_carre, horloge_precedente_carre;


    float intervalle_horloge_carre = 0.07f;
    int refresh;

	sdlGameMonitor(sdlGameP);
	assert( SDL_Flip( sdlGameP->surface_screen )!=-1 );


    horloge_precedente_carre = (float)clock()/(float)CLOCKS_PER_SEC;






	while ( continue_loop == 1 )
	{

                refresh = 0;


                horloge_courante_carre = (float)clock()/(float)CLOCKS_PER_SEC;

                        if (horloge_courante_carre-horloge_precedente_carre>=intervalle_horloge_carre)
                        {
                            sdlKeymove(&continue_loop,sdlGameP);
                            horloge_precedente_carre = horloge_courante_carre;
                            refresh = 1;
                        }


                        if (horloge_courante_carre-horloge_precedente_carre>=intervalle_horloge_carre)
                        {
                            sdlKeymove(&continue_loop,sdlGameP);


                            horloge_precedente_carre = horloge_courante_carre;
                            refresh = 1;
                        }

                    if(sdlGameP->game.ball.x==28 && sdlGameP->game.ball.y==1)
                    sdlGameEnd(sdlGameP,&refresh,&continue_loop);

                    if (refresh==1)
                        {

                            sdlGameMonitor(sdlGameP);


                            SDL_Flip( sdlGameP->surface_screen );
                        }
	}

}


int sdlKeymove(int *continue_loop, sdlGame *sdlGameP)
{
	SDL_Event event;


	Uint8* keystate = SDL_GetKeyState(NULL);


	if(keystate[SDLK_LEFT])
	{gameKeyboard( &(sdlGameP->game), 'g');
	}
	if(keystate[SDLK_RIGHT])
	{gameKeyboard( &(sdlGameP->game), 'd');
	}
	if(keystate[SDLK_UP])
	{gameKeyboard( &(sdlGameP->game), 'h');
	}
    if(keystate[SDLK_DOWN])
    { gameKeyboard( &(sdlGameP->game), 'b');
    }
    while(SDL_PollEvent(&event))
     {
     switch (event.type)
     {

    case SDL_QUIT:
        *continue_loop = 0;

    case SDL_KEYDOWN:
       if(event.key.keysym.sym == SDLK_ESCAPE)
       *continue_loop = 0;

    break;

    }
}
return *continue_loop;

}

void sdlGameEnd(sdlGame* sdlGameP, int* refresh,int* continue_loop)
{

    Mix_Chunk* effect1;
    effect1 = Mix_LoadWAV("data/effect1.wav");
    Mix_PlayChannel(-1,effect1,0);
    int x,y;
    SDL_apply_surface( sdlGameP->surface_win1, sdlGameP->surface_screen,0,0);
    SDL_apply_surface( sdlGameP->surface_restart, sdlGameP->surface_screen,928,576);
    SDL_apply_surface( sdlGameP->surface_home, sdlGameP->surface_screen,0,576);
    SDL_Flip( sdlGameP->surface_screen );
    SDL_GetMouseState(&x,&y);
      SDL_PumpEvents();

    if (x>928 && x<959 && y>575 && y<607 && (SDL_GetMouseState(NULL,NULL)&SDL_BUTTON(1)))
    {   Mix_FreeChunk(effect1);
        sdlGameP->game.ball.x=1; sdlGameP->game.ball.y=17;
    }
    if (x>0 && x<31 && y>576 && y<607 && (SDL_GetMouseState(NULL,NULL)&SDL_BUTTON(1)))
    {
      Mix_FreeChunk(effect1);

        *continue_loop = 2;
        sdlGameLoopMenu(sdlGameP);
    }

    *refresh=0;

}


void sdlGameFree( sdlGame *sdlGameP)
{
	SDL_FreeSurface( sdlGameP->surface_ball );
	SDL_FreeSurface( sdlGameP->surface_wall );
    SDL_FreeSurface( sdlGameP->surface_menu );
	SDL_FreeSurface( sdlGameP->surface_win1 );
	SDL_FreeSurface( sdlGameP->surface_close);
    SDL_FreeSurface( sdlGameP->surface_restart);
	SDL_FreeSurface( sdlGameP->surface_about);
	SDL_FreeSurface( sdlGameP->surface_end);
    SDL_FreeSurface( sdlGameP->surface_screen);
	gameFree(&(sdlGameP->game));

	SDL_Quit();
}



SDL_Surface *SDL_load_image(const char* filename )
{

	SDL_Surface* loadedImage = NULL;


	SDL_Surface* optimizedImage = NULL;


	loadedImage = SDL_LoadBMP( filename );

	if ( loadedImage != NULL )
	{

		optimizedImage = SDL_DisplayFormat( loadedImage );


		SDL_FreeSurface( loadedImage );
	}


	return optimizedImage;
}


void SDL_apply_surface( SDL_Surface* source, SDL_Surface* destination, int x, int y )
{

	SDL_Rect offset;


	offset.x = x;
	offset.y = y;


	SDL_BlitSurface( source, NULL, destination, &offset );
}

