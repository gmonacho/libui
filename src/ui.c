#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "ui.h"

int		ui_init(Uint32 sdl_flags, Uint32 image_flags)
{
	Uint32		flags;

	flags = IMG_INIT_JPG | IMG_INIT_PNG |IMG_INIT_TIF;
	if (SDL_Init(sdl_flags) != 0)
		return (ui_error(SDL_GetError()));
	if (TTF_Init() == -1)
		return (ui_error(SDL_GetError()));
	if	(IMG_Init(image_flags)&flags != flags)
		return (ui_error(SDL_GetError()));
}
