#ifndef DRAW_H
# define DRAW_H

# include "SDL.h"
# include "ui_frame.h"
# include "ui_renderer.h"

void    ui_draw_point(SDL_Renderer *rend, int x, int y, t_frame *frame);

#endif