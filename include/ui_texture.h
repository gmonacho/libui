#ifndef UI_TEXTURE_H
# define UI_TEXTURE_H

# include "SDL.h"

SDL_Texture     *ui_load_texture(const char *bmp_file, SDL_Renderer *rend);
SDL_Texture		*ui_create_bloc_texture(SDL_Renderer *rend, t_len size, int background_color, int border_color);
void    		ui_blit_texture( SDL_Renderer *rend, SDL_Texture *src, SDL_Texture *dst, t_frect ratio);

#endif