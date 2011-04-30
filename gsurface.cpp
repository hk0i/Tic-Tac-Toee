#include "gsurface.h"

GSurface::GSurface(void) { }

SDL_Surface *GSurface::loadImage(const char *filename)
{
	SDL_Surface *tmp = NULL;
	SDL_Surface *opt = NULL;

	tmp = IMG_Load(filename);

	if (tmp)
	{
		opt = SDL_DisplayFormat(tmp);
		SDL_FreeSurface(tmp);
	}

	return opt;
}

SDL_Surface *GSurface::loadImageAlpha(const char* filename)
{
	SDL_Surface *tmp = NULL;
	SDL_Surface *opt = NULL;

	tmp = IMG_Load(filename);

	if (tmp)
	{
		opt = SDL_DisplayFormatAlpha(tmp);
		SDL_FreeSurface(tmp);
	}

	return opt;
}

bool GSurface::blitSurface(int x, int y, SDL_Surface *src, SDL_Surface *dest, 
							SDL_Rect *clip)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(src, clip, dest, &offset);
	return true;
}

bool GSurface::setAlphaColor(SDL_Surface *surf, int r, int g, int b)
{
	if (!surf)
		return false;
	SDL_SetColorKey(surf, SDL_SRCCOLORKEY,
					SDL_MapRGB(surf->format, r, g, b));
	return true;
}
