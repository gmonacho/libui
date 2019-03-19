#ifndef UI_TEXTURE_H
# define UI_TEXTURE_H

# include "SDL.h"

SDL_Texture     *ui_load_texture(const char *bmp_file, SDL_Renderer *rend);

#endif