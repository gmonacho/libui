#include "SDL.h"
#include "ui_shape.h"
#include "ui_error.h"
#include "ui_texture.h"

SDL_Texture		*ui_load_texture(const char *bmp_file, SDL_Renderer *rend)
{
	SDL_Surface *tmp; 
	SDL_Texture *texture;

	if (!(tmp = SDL_LoadBMP(bmp_file)))
		return (ui_null_error(SDL_GetError()));
	if (!(texture = SDL_CreateTextureFromSurface(rend, tmp)))
		return (ui_null_error(SDL_GetError()));
	SDL_FreeSurface(tmp);
	printf("OK\n");
	return (texture);
}

void			ui_draw_texture(SDL_Renderer *rend,
									SDL_Texture *texture,
									t_rect *text_rect,
									t_rect *dst_rect)
{
	if (!SDL_RenderCopy(rend, texture, (SDL_Rect*)text_rect, (SDL_Rect*)dst_rect))
		perror("SDL_RenderCopy failed");
}