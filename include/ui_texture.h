#ifndef UI_TEXTURE_H
# define UI_TEXTURE_H

# include "SDL.h"

SDL_Texture     *ui_load_texture(const char *bmp_file, SDL_Renderer *rend);
void			ui_draw_texture(SDL_Renderer *rend,
									SDL_Texture *texture,
									t_rect *text_rect,
									t_rect *dst_rect);

#endif