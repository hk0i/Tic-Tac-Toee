#ifndef _GEVENT_H
#define _GEVENT_H
#include "SDL.h"

class GEvent {

	public:
		GEvent();
		virtual ~GEvent();

		virtual void onEvent(SDL_Event *event);
		virtual void onInputFocus(void);
		virtual void onInputBlur(void);
		virtual void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
		virtual void onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

		virtual void onMouseFocus(void);
		virtual void onMouseBlur(void);
		virtual void onMouseMove(int mX, int mY, int relX, int relY, bool left,
								 bool right, bool middle);
		virtual void onMouseWheel(bool up, bool down);
		virtual void onLButtonDown(int mX, int mY);
		virtual void onLButtonUp(int mX, int mY);
		virtual void onRButtonDown(int mX, int mY);
		virtual void onRButtonUp(int mX, int mY);
		virtual void onMButtonDown(int mX, int mY);
		virtual void onMButtonUp(int mX, int mY);

		virtual void onJoyAxis(Uint8 which, Uint8 axis, Sint16 value);
		virtual void onJoyButtonDown(Uint8 which, Uint8 button);
		virtual void onJoyButtonUp(Uint8 which, Uint8 button);
		virtual void onJoyHat(Uint8 which, Uint8 hat, Uint8 value);
		virtual void onJoyBall(Uint8 which, Uint8 ball, Sint16 xrel,
							  Sint16 yrel);

		virtual void onMinimize(void);
		virtual void onRestore(void);
		virtual void onResize(int w, int h);
		virtual void onExpose(void);
		virtual void onExit(void);

		virtual void onUser(Uint8 type, int code, void *data1, void *data2);
};

#endif
