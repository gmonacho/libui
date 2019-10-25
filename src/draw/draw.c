#include "ui_draw.h"

void	ui_set_draw_color(SDL_Renderer *rend, const SDL_Color *color)
{
	SDL_SetRenderDrawColor(rend, color->r, color->g, color->b, color->a);
}