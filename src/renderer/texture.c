#include "SDL.h"
#include "ui_error.h"
#include "ui_texture.h"

SDL_Texture		*ui_load_texture(const char *bmp_file, SDL_Renderer *rend)
{
	SDL_Surface *tmp; 
	SDL_Texture *texture;

	if (!(tmp = SDL_LoadBMP(bmp_file)))
		return (ui_null_error("LoadBMPFailed"));
	if (!(texture = SDL_CreateTextureFromSurface(rend, tmp)))
		return (ui_null_error("Texture Creation Failed"));
	SDL_FreeSurface(tmp);
	return (texture);
}