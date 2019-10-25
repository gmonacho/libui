#ifndef UI_DRAW_H
# define UI_DRAW_H

#include "ui_shape.h"
#include "SDL.h"


void	ui_set_draw_color(SDL_Renderer *rend, const SDL_Color *color);
void	ui_draw_point(SDL_Renderer *rend, const ui_dot *dot);
void	ui_draw_line(SDL_Renderer *rend, const ui_line *line);
void	ui_draw_rect(SDL_Renderer *rend, const ui_rect *rect);

#endif