#include "ui_draw.h"

void	ui_draw_point(SDL_Renderer *rend, const t_dot *dot)
{
	SDL_RenderDrawPoint(rend, dot->x, dot->y);
}

void	ui_draw_line(SDL_Renderer *rend, const t_line *line)
{
	SDL_RenderDrawLine(rend, line->d1.x, line->d1.y, line->d2.x, line->d2.y);
}

void	ui_draw_rect(SDL_Renderer *rend, const t_rect *rect)
{
	SDL_RenderDrawRect(rend, (SDL_Rect*)rect);
}
