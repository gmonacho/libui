#include "SDL.h"
#include "ui_shape.h"
#include "ui_error.h"
#include "ui_frame.h"
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
	return (texture);
}

SDL_Texture		*ui_create_bloc_texture(SDL_Renderer *rend, t_len size, int background_color, int border_color)
{
	SDL_Texture	*texture;
	SDL_Point	points[5];
	SDL_Rect	sdl_rect;

	if (!(texture = SDL_CreateTexture(rend, SDL_PIXELFORMAT_RGBA8888,
							SDL_TEXTUREACCESS_TARGET,
							size.x,
							size.y)))
		return (ui_null_error(SDL_GetError()));
	SDL_SetRenderTarget(rend, texture);
	sdl_rect = (SDL_Rect){0, 0, size.x, size.y};
	SDL_SetRenderDrawColor(rend, (background_color >> 16) & 0xFF,
								(background_color >> 8) & 0xFF,
								background_color & 0xFF,
								(background_color >> 24) & 0xFF);
	SDL_RenderFillRect(rend, &sdl_rect);
	points[0] = (SDL_Point){0, 0};
	points[1] = (SDL_Point){size.x - 1, 0};
	points[2] = (SDL_Point){size.x - 1, size.y - 1};
	points[3] = (SDL_Point){0, size.y - 1};
	points[4] = (SDL_Point){0, 0};
	SDL_SetRenderDrawColor(rend, (border_color >> 16) & 0xFF,
								(border_color >> 8) & 0xFF,
								border_color & 0xFF,
								(border_color >> 24) & 0xFF);
	SDL_RenderDrawLines(rend, points, 5);
	SDL_SetRenderTarget(rend, NULL);
	return (texture);
}
