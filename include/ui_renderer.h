#ifndef RENDERER_H
# define RENDERER_H

# include "SDL.h"
# include "ui_draw.h"
# include "ui_renderer_flag.h"

SDL_Renderer    *ui_create_renderer(SDL_Window *win, int index, Uint32 flags);
void		    ui_draw_rend(SDL_Renderer *rend);
void			ui_clear_rend(SDL_Renderer *rend);
void			ui_destroy_rend(SDL_Renderer *rend);
void			ui_set_draw_color(SDL_Renderer *rend, Uint32 color);

#endif