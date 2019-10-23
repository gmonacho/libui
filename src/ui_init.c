#include "SDL.h"
#include "ui.h"
#include "ui_error.h"

int		ui_init(Uint32 sdl_flags)
{
	int		ret;

	if ((ret = SDL_Init(sdl_flags)) < 0)
		return (ui_ret_error("ui_init", SDL_GetError(), ret));
	return (1);
}