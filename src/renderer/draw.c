#include "SDL.h"
#include "ui_error.h"
#include "ui_frame.h"
#include "ui_draw.h"

void	ui_draw_point(SDL_Renderer *rend, int x, int y, t_frame *frame)
{
	if (!frame)
	{
		if (SDL_RenderDrawPoint(rend, x, y) < 0)
			ui_error(SDL_GetError());
	}
	else
	{
		if (x >= frame->r.x && x <= frame->r.x + (int)frame->r.w
			&& y >= frame->r.y && x <= frame->r.y + (int)frame->r.h)
		{
			if (SDL_RenderDrawPoint(rend, x + frame->r.x, y + frame->r.y) < 0)
				ui_error(SDL_GetError());
		}
	}
}

void	ui_draw_texture(SDL_Renderer *rend, SDL_Texture *texture, Uint32 type_draw, t_frame_dep f_d)
{
	if (type_draw & UI_ABSOLUTE)
		ui_draw_texture_abs(rend, texture, f_d.f_r, f_d.r);
}
