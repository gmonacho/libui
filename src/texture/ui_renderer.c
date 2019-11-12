#include "ui_texture.h"

void				ui_set_rend_target(SDL_Renderer *rend, SDL_Texture *texture)
{
	SDL_SetRenderTarget(rend, texture);
}
