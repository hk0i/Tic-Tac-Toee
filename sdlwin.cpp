#include "sdlwin.h"

SDLWin::SDLWin(void)
	   : isRunning(true),
	   	 isResetting(false),
	   	 myDisplay(NULL),
		 mySuGrid(NULL),
		 mySuX(NULL),
		 mySuO(NULL)
{
	myOffset_XWin.x = 0;
	myOffset_XWin.y = 0;
	myOffset_XWin.h = 100;
	myOffset_XWin.w = 600;

	myOffset_OWin.x = 0;
	myOffset_OWin.y = 100;
	myOffset_OWin.h = 100;
	myOffset_OWin.w = 600;

	myOffset_Draw.x = 0;
	myOffset_Draw.y = 200;
	myOffset_Draw.h = 100;
	myOffset_Draw.w = 600;


}

int SDLWin::run(void)
{
	if (init() == false)
		return -1;

	SDL_ShowCursor(0);

	SDL_Event event;
	while (isRunning)
	{
		myFps.start();

		while (SDL_PollEvent(&event))
			this->onEvent(&event);
		loop();
		render();
	}

	cleanup();
	return 0;
}

bool SDLWin::init(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;
	if ((myDisplay = SDL_SetVideoMode(600,600,32, SDL_HWSURFACE
					| SDL_DOUBLEBUF)) == NULL)
		return false;

	SDL_WM_SetCaption("TIC TAC TOOOOOOOOOEEEEEEEE", NULL);

	if ((mySuX = GSurface::loadImageAlpha("x.png")) == NULL)
		return false;
	if ((mySuO = GSurface::loadImageAlpha("o.png")) == NULL)
		return false;
	if ((mySuGrid = GSurface::loadImage("grid.png")) == NULL)
		return false;
	if ((mySuWins = GSurface::loadImageAlpha("wins.png")) == NULL)
		return false;	

	myCursor.w = mySuX->w;
	myCursor.h = mySuX->h;

	/*GSurface::setAlphaColor(mySuX, 0xFF, 0, 0xFF);
	GSurface::setAlphaColor(mySuO, 0xFF, 0, 0xFF);*/
	//GSurface::setAlphaColor(mySuWins, 0xFF, 0, 0xFF);
	//SDL_SetColorKey(mySuWins, SDL_RLEACCEL, mySuWins->format->colorkey);

	return true;
}

void SDLWin::onEvent(SDL_Event *event)
{
	GEvent::onEvent(event);
	if (event->type == SDL_MOUSEMOTION)
	{
		myCursor.x = event->motion.x - (myCursor.w / 2);
		myCursor.y = event->motion.y - (myCursor.h / 2);
	}
}

void SDLWin::onExit(void)
{
	isRunning = false;
}

void SDLWin::render(void)
{
	// blit surfaces
	GSurface::blitSurface(0, 0, mySuGrid, myDisplay);

	for (int i = 0; i < 9; ++i)
	{
		int X = (i % 3) * 200;
		int Y = (i / 3) * 200;

		if (myGame.getCell(i) == TTTBoard::GRID_TYPE_X)
			GSurface::blitSurface(X, Y, mySuX, myDisplay);
		else if (myGame.getCell(i) == TTTBoard::GRID_TYPE_O)
			GSurface::blitSurface(X, Y, mySuO, myDisplay);
	}

	// draw cursor
	if (myGame.getCurrentPlayer() == TTTBoard::PLAYER_X)
		GSurface::blitSurface(myCursor.x, myCursor.y, mySuX, myDisplay);
	else
		GSurface::blitSurface(myCursor.x, myCursor.y, mySuO, myDisplay);

	if (!isResetting && myGame.gameOver())
		showGameOver();


	// flip screen
	SDL_Flip(myDisplay);

	// cap fps
	if (myFps.getTicks() < 1000 / MAX_FPS)
		SDL_Delay((1000 / MAX_FPS) - myFps.getTicks());
}

void SDLWin::cleanup(void)
{
	SDL_FreeSurface(mySuGrid);
	SDL_FreeSurface(mySuX);
	SDL_FreeSurface(mySuO);

	SDL_Quit();
}

void SDLWin::loop(void)
{
}

void SDLWin::onLButtonDown(int mX, int mY)
{
	int id = mX / 200;
	id += (mY / 200) * 3;

	if (myGame.getCell(id) != TTTBoard::GRID_TYPE_NONE)
		return;

	myGame.turn(id);
}

void SDLWin::showGameOver(void)
{
	if (myGame.gameOver() == TTTBoard::PLAYER_X)
		GSurface::blitSurface(0, (600 / 2) - 50, mySuWins, myDisplay,
			   				  &myOffset_XWin);
	else if (myGame.gameOver() == TTTBoard::PLAYER_O)
		GSurface::blitSurface(0, (600 / 2) - 50, mySuWins, myDisplay,
							  &myOffset_OWin);
	else if (myGame.gameOver() == TTTBoard::PLAYER_NOBODY)
		GSurface::blitSurface(0, (600/2) - 50, mySuWins, myDisplay,
							  &myOffset_Draw);
}


void SDLWin::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	if (sym == SDLK_r)
	{
		// fancy reset animation
		isResetting = true;
		for (int i = 0; i < 9; ++i)
		{
			myGame.setCell(i, TTTBoard::GRID_TYPE_X);
			render();
			SDL_Delay(50);
		}

		for (int i = 0; i < 9; ++i)
		{
			myGame.setCell(i, TTTBoard::GRID_TYPE_O);
			render();
			SDL_Delay(50);
		}
		myGame.reset();
		isResetting = false;
	}
}
