#ifndef UI_TEXTURE_H
# define UI_TEXTURE_H

# include "SDL.h"

SDL_Texture     *ui_load_texture(const char *bmp_file, SDL_Renderer *rend);
SDL_Texture		*ui_create_empty_texture(SDL_Renderer *rend, t_len resolution);
void    		ui_blit_texture( SDL_Renderer *rend, SDL_Texture *src, SDL_Texture *dst, t_frect ratio);
t_len			ui_get_texture_resolution(SDL_Texture *texture);
void	        ui_draw_texture(SDL_Renderer *rend, SDL_Texture *texture, t_rect dst);


#endif