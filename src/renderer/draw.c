#include "SDL.h"
#include "ui_error.h"
#include "ui_frame.h"
#include "ui_draw.h"

void	ui_draw_texture(SDL_Renderer *rend, SDL_Texture *texture, t_rect dst)
{
	if (SDL_RenderCopy(rend, texture, NULL, (SDL_Rect*)&dst) < 0)
		perror(SDL_GetError());
}

void	ui_draw_arc(SDL_Renderer *rend, t_circle circle, int flags_arc, int color)
{
    int		x;
    int		y;
    int		d;

	x = 0;
	y = circle.radius;
	d = circle.radius - 1;
	ui_set_draw_color(rend, color);
    while (y >= x)
    {
		if (circle.y + x != circle.y - x && flags_arc & ARC45)
			SDL_RenderDrawPoint(rend, circle.x + y, circle.y - x);
		if (circle.y - x != circle.y - y && flags_arc & ARC90)
			SDL_RenderDrawPoint(rend, circle.x + x, circle.y - y);
		if (circle.x + x != circle.x - x && flags_arc & ARC135)
			SDL_RenderDrawPoint(rend, circle.x - x, circle.y - y);
		if (circle.y - y != circle.y - x && flags_arc & ARC180)
			SDL_RenderDrawPoint(rend, circle.x - y, circle.y - x);
		if (circle.y - x != circle.y + x && flags_arc & ARC225)
			SDL_RenderDrawPoint(rend, circle.x - y, circle.y + x);
		if (circle.x - y != circle.x - x && flags_arc & ARC270)
       	 	SDL_RenderDrawPoint(rend, circle.x - x, circle.y + y);
		if (circle.x - x!= circle.x + x && flags_arc & ARC315)
       	 	SDL_RenderDrawPoint(rend, circle.x + x, circle.y + y);
		if (circle.x + x != circle.x - y && circle.y + y != circle.y + x && flags_arc & ARC360)
			SDL_RenderDrawPoint(rend, circle.x + y, circle.y + x);
        if (d >= 2 * x)
            d -= 2 * x++ + 1;
        else if (d < 2 * ((int)circle.radius - y))
            d += 2 * y-- - 1;
        else
            d += 2 * (y-- - x++ - 1);
    }
}

void	ui_fill_arc(SDL_Renderer *rend, t_circle circle, int arc, int color)
{
	while (circle.radius)
	{
		ui_draw_arc(rend, circle, arc, color);
		circle.radius--;
	}
}

//void	ui_draw_line(SDL_renderer *rend, t_line line, int width, int color)

void	ui_draw_rect(SDL_Renderer *rend, t_rect rect, int border_width, int color)
{
	SDL_Rect	sdl_rect;
	int			i;

	ui_set_draw_color(rend, color);
	if (border_width == 1)
		SDL_RenderDrawRect(rend, (SDL_Rect*)&rect);
	else
	{
		i = 0;
		while (i < border_width)
		{
			//sdl_rect = (SDL_Rect){rect.x - i, rect.y - i, rect.w + i * 2, rect.h + i * 2};
			//SDL_RenderDrawRect(rend, (SDL_Rect*)&sdl_rect);
			sdl_rect = (SDL_Rect){rect.x + i, rect.y + i, rect.w - i * 2, rect.h - i * 2};
			SDL_RenderDrawRect(rend, (SDL_Rect*)&sdl_rect);
			i++;
		}
	}
}

void	ui_fill_rect(SDL_Renderer *rend, t_rect rect, int color)
{
	ui_set_draw_color(rend, color);
	SDL_RenderFillRect(rend, (SDL_Rect*)&rect);
}

void	ui_draw_curved_rect(SDL_Renderer *rend, t_curved_rect rect, int border_width, int color)
{
	int			i;
    SDL_Rect    sdl_rects[4];

	if (rect.radius * 2 > rect.w)
		rect.radius = rect.w / 2;
	if (rect.radius * 2 > rect.h)
		rect.radius = rect.h / 2;
    ui_set_draw_color(rend, color);
    sdl_rects[0] = (SDL_Rect){rect.x + rect.radius, rect.y, rect.w - 2 * rect.radius, border_width};
    sdl_rects[1] = (SDL_Rect){rect.x + rect.w - border_width, rect.y + rect.radius, border_width, rect.h - 2 * rect.radius};
    sdl_rects[2] = (SDL_Rect){rect.x + rect.radius, rect.y + rect.h - border_width, rect.w - 2 * rect.radius, border_width};
    sdl_rects[3] = (SDL_Rect){rect.x, rect.y + rect.radius + 1, border_width, rect.h - 2 * rect.radius};
	SDL_RenderFillRects(rend, sdl_rects, 4);
	i = 0;
	while (i < border_width)
	{
		ui_draw_arc(rend, (t_circle){rect.x + rect.w - rect.radius - 1, rect.y + rect.h - rect.radius, rect.radius - i}, ARC315 | ARC360, color);
		ui_draw_arc(rend, (t_circle){rect.x + rect.radius - 1, rect.y + rect.h - rect.radius, rect.radius - i}, ARC225 | ARC270, color);
		ui_draw_arc(rend, (t_circle){rect.x + rect.radius, rect.y + rect.radius, rect.radius - i}, ARC135 | ARC180, color);
		ui_draw_arc(rend, (t_circle){rect.x + rect.w - rect.radius, rect.y + rect.radius, rect.radius - i}, ARC45 | ARC90, color);
		i++;
	}
}

void	ui_fill_curved_rect(SDL_Renderer *rend, t_curved_rect rect, int color)
{
	if (rect.radius * 2 > rect.w)
		rect.radius = rect.w / 2;
	if (rect.radius * 2 > rect.h)
		rect.radius = rect.h / 2;

    ui_fill_arc(rend, (t_circle){rect.x + rect.w - rect.radius, rect.y + rect.radius, rect.radius - 1}, ARC45 | ARC90, color);
    ui_fill_arc(rend, (t_circle){rect.x + rect.radius, rect.y + rect.radius - 1, rect.radius - 1}, ARC135 | ARC180, color);
    ui_fill_arc(rend, (t_circle){rect.x + rect.radius - 1, rect.y + rect.h - rect.radius - 1, rect.radius - 1}, ARC225 | ARC270, color);
    ui_fill_arc(rend, (t_circle){rect.x + rect.w - rect.radius - 1, rect.y + rect.h - rect.radius, rect.radius - 1}, ARC315 | ARC360, color);
	ui_set_draw_color(rend, color);
	ui_fill_rect(rend, (t_rect){rect.x, rect.y + rect.radius, rect.radius, rect.h - rect.radius * 2}, color);
	ui_fill_rect(rend, (t_rect){rect.x + rect.w - rect.radius, rect.y + rect.radius, rect.radius, rect.h - rect.radius * 2}, color);
	ui_fill_rect(rend, (t_rect){rect.x + rect.radius, rect.y, rect.w - rect.radius * 2, rect.h}, color);
}
