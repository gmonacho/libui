#include "ui_draw.h"

/*void	ui_draw_full_texture_resp(SDL_Renderer *rend,
									SDL_Texture *texture,
									t_rect frame_r,
									t_frect resp_r)
{
	SDL_Rect	r;

	r = (SDL_Rect){frame_r.w * resp_r.x + frame_r.x,
					frame_r.h * resp_r.y + frame_r.y,
					frame_r.w * resp_r.w,
					frame_r.h * resp_r.h};
	if (SDL_RenderCopy(rend, texture, NULL, &r) < 0)
		perror(SDL_GetError());
}*/

void	ui_draw_texture_abs(SDL_Renderer *rend, SDL_Texture *texture, t_rect f_r, t_rect r)
{
	SDL_Rect	sdl_r;

	sdl_r = (SDL_Rect){r.x + f_r.x, r.y + f_r.y, r.w, r.h};
	if (SDL_RenderCopy(rend, texture, NULL, &sdl_r) < 0)
		perror(SDL_GetError());
}