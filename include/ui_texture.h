#ifndef UI_TEXTURE_H
# define UI_TEXTURE_H

SDL_Texture		*ui_load_image(SDL_Renderer *rend, const char *file);
void			ui_destroy_texture(SDL_Texture *texture);

#endif