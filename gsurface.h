#ifndef _GSURFACE_H
#define _GSURFACE_H

#include "SDL.h"
#include "SDL_image.h"

class GSurface
{
	public:
		GSurface(void);

		static SDL_Surface *loadImage(const char *filename);
		static SDL_Surface *loadImageAlpha(const char *filename);
		static bool blitSurface(int x, int y, SDL_Surface *src,
							    SDL_Surface *dest, SDL_Rect *clip=NULL);
		static bool setAlphaColor(SDL_Surface *surf, int r, int g, int b);
};

#endif
