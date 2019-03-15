#ifndef RENDERER_H
# define RENDERER_H

# include "renderer_flag.h"

SDL_Renderer    *create_renderer(SDL_Window *win, int index, Uint32 flags);
void		    draw_rend(SDL_Renderer *rend);
void			clear_rend(SDL_Renderer *rend);
void			destroy_rend(SDL_Renderer *rend);
void			set_draw_color(SDL_Renderer *rend, Uint32 color);

#endif