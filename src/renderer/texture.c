#include "SDL.h"
#include "ui_shape.h"
#include "ui_error.h"
#include "ui_frame.h"
#include "ui_draw.h"
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

	if (!(texture = SDL_CreateTexture(rend, SDL_PIXELFORMAT_RGBA8888,
							SDL_TEXTUREACCESS_TARGET,
							size.x,
							size.y)))
		return (ui_null_error(SDL_GetError()));
	SDL_SetRenderTarget(rend, texture);
	ui_fill_rect(rend, (t_rect){0, 0, size.x - 1, size.y - 1}, background_color, border_color);
	SDL_SetRenderTarget(rend, NULL);
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	return (texture);
}

//nonfonctionnel
void		ui_blit_texture(SDL_Renderer *rend, SDL_Texture *src, SDL_Texture *dst, t_frect ratio)
{
	SDL_Rect	sdl_rect;
	int			w;
	int			h;

	SDL_QueryTexture(src, NULL, NULL, &w, &h);

	sdl_rect = (SDL_Rect){w * ratio.x,
						h * ratio.y,
						w * ratio.w,
						h * ratio.h};
	SDL_SetRenderTarget(rend, dst);
	SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
	SDL_RenderDrawLine(rend, 50, 0, 50, 100);
	SDL_RenderCopy(rend, src, NULL, &sdl_rect);
	SDL_SetRenderTarget(rend, NULL);
}