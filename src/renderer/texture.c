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

t_len			ui_get_texture_resolution(SDL_Texture *texture)
{
	t_len	resolution;

	SDL_QueryTexture(texture, NULL, NULL, (int*)&(resolution.x), (int*)&(resolution.y));
	return (resolution);
}

SDL_Texture		*ui_create_empty_texture(SDL_Renderer *rend, t_len resolution)
{
	SDL_Texture 	*texture;
	if (!(texture = SDL_CreateTexture(rend,
										SDL_PIXELFORMAT_RGBA8888,
										SDL_TEXTUREACCESS_TARGET,
										resolution.x,
										resolution.y)))
		return (ui_null_error(SDL_GetError()));
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	return (texture);
}

//nonfonctionnel
/*void		ui_blit_texture(SDL_Renderer *rend, SDL_Texture *src, SDL_Texture *dst, t_frect ratio)
{
	SDL_Rect	sdl_rect;
	int			w;
	int			h;

	if (src)
		w = 0;
	SDL_QueryTexture(dst, NULL, NULL, &w, &h);
	printf("res.x = %d, res.y = %d\n", w, h);
	sdl_rect = (SDL_Rect){w * ratio.x,
						h * ratio.y,
						w * ratio.w,
						h * ratio.h};
	printf("x = %d, y = %d, w = %d, h = %d", sdl_rect.x, sdl_rect.y, sdl_rect.w, sdl_rect.h);
	SDL_SetRenderTarget(rend, dst);
	SDL_SetTextureBlendMode(dst, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
	SDL_RenderDrawLine(rend, 0, 0, 400, 400);
	//SDL_RenderCopy(rend, src, NULL, &sdl_rect);
	SDL_SetRenderTarget(rend, NULL);
}*/