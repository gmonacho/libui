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
		if (x >= frame->rect.x && x <= frame->rect.x + (int)frame->rect.w
			&& y >= frame->rect.y && x <= frame->rect.y + (int)frame->rect.h)
		{
			if (SDL_RenderDrawPoint(rend, x + frame->rect.x, y + frame->rect.y) < 0)
				ui_error(SDL_GetError());
		}
	}
}

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
	int		i;
	int		mid;
	int		current;
	t_dot	points[8];

	if (rect.radius * 2 > rect.w)
		rect.radius = rect.w / 2;
	if (rect.radius * 2 > rect.h)
		rect.radius = rect.h / 2;
	points[0] = (t_dot){rect.x + rect.radius, rect.y};
	points[1] = (t_dot){rect.x + rect.w - rect.radius, rect.y};
	points[2] = (t_dot){rect.x + rect.w, rect.y + rect.radius};
	points[3] = (t_dot){rect.x + rect.w, rect.y + rect.h - rect.radius};
	points[4] = (t_dot){rect.x + rect.w - rect.radius, rect.y + rect.h};
	points[5] = (t_dot){rect.x + rect.radius, rect.y + rect.h};
	points[6] = (t_dot){rect.x, rect.y + rect.h - rect.radius};
	points[7] = (t_dot){rect.x, rect.y + rect.radius};
	i = 0;
	ui_set_draw_color(rend, color);
	mid = border_width / 2;
	current = 0;
	while (i < 8)
	{
		SDL_RenderDrawLine(rend, points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
		i += 2;
	}
	ui_draw_arc(rend, (t_circle){points[4].x, points[3].y, rect.radius}, ARC315 | ARC360, color);
	ui_draw_arc(rend, (t_circle){points[5].x, points[6].y, rect.radius}, ARC225 | ARC270, color);
	ui_draw_arc(rend, (t_circle){points[0].x, points[7].y, rect.radius}, ARC135 | ARC180, color);
	ui_draw_arc(rend, (t_circle){points[1].x, points[2].y, rect.radius}, ARC45 | ARC90, color);
}

void	ui_fill_curved_rect(SDL_Renderer *rend, t_rect rect, int radius, int color)
{
	int		i;
	t_dot	points[8];
	
	if (radius * 2 > rect.w)
		radius = rect.w / 2;
	if (radius * 2 > rect.h)
		radius = rect.h / 2;
	points[0] = (t_dot){rect.x + radius, rect.y};	
	points[1] = (t_dot){rect.x + rect.w - radius, rect.y};
	points[2] = (t_dot){rect.x + rect.w, rect.y + radius};
	points[3] = (t_dot){rect.x + rect.w, rect.y + rect.h - radius};
	points[4] = (t_dot){rect.x + rect.w - radius, rect.y + rect.h};
	points[5] = (t_dot){rect.x + radius, rect.y + rect.h};
	points[6] = (t_dot){rect.x, rect.y + rect.h - radius};
	points[7] = (t_dot){rect.x, rect.y + radius};
	ui_fill_arc(rend, (t_circle){points[4].x - 1, points[3].y, radius}, ARC315 | ARC360, color);
	ui_fill_arc(rend, (t_circle){points[5].x, points[6].y - 1, radius}, ARC225 | ARC270, color);
	ui_fill_arc(rend, (t_circle){points[0].x + 1, points[7].y, radius}, ARC135 | ARC180, color);
	ui_fill_arc(rend, (t_circle){points[1].x, points[2].y + 1, radius}, ARC45 | ARC90, color);
	ui_set_draw_color(rend, color);
	i = 0;
	while (i < 8)
	{
		SDL_RenderDrawLine(rend, points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
		i += 2;
	}
	ui_fill_rect(rend, (t_rect){rect.x + 1, rect.y + radius + 1, radius, rect.h - radius * 2 - 1}, color);
	ui_fill_rect(rend, (t_rect){rect.x + rect.w - radius, rect.y + radius + 1, radius, rect.h - radius * 2 - 1}, color);
	ui_fill_rect(rend, (t_rect){rect.x + radius + 1, rect.y + 1, rect.w - radius * 2 - 1, rect.h - 1}, color);
}
