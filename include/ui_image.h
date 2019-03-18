#ifndef UI_IMAGE_H
# define UI_IMAGE_H

enum	s_img_format
{
	UI_PNG = 1,
	UI_JPG = 2,
	UI_GIF = 3
};

SDL_Texture *ui_load_img(const char *path, Uint32 img_format, SDL_Renderer *rend);

#endif