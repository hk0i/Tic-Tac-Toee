#ifndef _SDLWIN_H
#define _SDLWIN_H

#include "SDL.h"
#include "gsurface.h"
#include "gevent.h"
#include "gtimer.h"
#include "tttboard.h"

#define MAX_FPS 60

class SDLWin : public GEvent
{
	public:
		SDLWin(void);
		int run(void);

		bool init(void);
		void loop(void);
		void render(void);
		void cleanup(void);

	public:

		void onEvent(SDL_Event *event);
		void onExit(void);
		void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
		void onLButtonDown(int mX, int mY);

	private:
		bool isRunning;
		bool isResetting;

		// surfaces
		SDL_Surface *myDisplay;
		SDL_Surface *mySuGrid;
		SDL_Surface *mySuX;
		SDL_Surface *mySuO;
		SDL_Surface *mySuWins;

		SDL_Rect myOffset_XWin;
		SDL_Rect myOffset_OWin;
		SDL_Rect myOffset_Draw;

		SDL_Rect myCursor;

		// game board
		TTTBoard myGame;

		// timer for fps limiting
		GTimer myFps;

	private:

		// functions
		
		// show a game over screen.
		void showGameOver(void);
};

#endif
