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

void	ui_draw_circle(SDL_Renderer *rend, t_dot p, int radius, int color, int corner_flag)
{
    int x = radius-1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

	ui_set_draw_color(rend, color);
    while (x >= y)
	{
		if ((corner_flag & UI_UPRIGHT_CORNER))
		{
			SDL_RenderDrawPoint(rend, p.x + y, p.y - x);
			SDL_RenderDrawPoint(rend, p.x + x, p.y - y);
		}
		if ((corner_flag & UI_DOWNRIGHT_CORNER))
		{
			SDL_RenderDrawPoint(rend, p.x + x, p.y + y);
			SDL_RenderDrawPoint(rend, p.x + y, p.y + x);
		}
		if ((corner_flag & UI_DOWNLEFT_CORNER))
		{
			SDL_RenderDrawPoint(rend, p.x - y, p.y + x);
			SDL_RenderDrawPoint(rend, p.x - x, p.y + y);
		}
		if ((corner_flag & UI_UPLEFT_CORNER))
		{
			SDL_RenderDrawPoint(rend, p.x - x, p.y - y);
			SDL_RenderDrawPoint(rend, p.x - y, p.y - x);
		}
		if (err <= 0)
        {
            y++;
            err += dy;
            dy += 2;
        }
        if (err > 0)
        {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}

void	ui_fill_circle(SDL_Renderer *rend, t_dot p, int radius, int bg_color, int border_color, int corner_flag)
{
	int		r;
	int		color;
	
	r = radius;
	color = border_color;
	while (r)
	{
		ui_draw_circle(rend, p, r--, color, corner_flag);
		color = bg_color;
	}
}

void	ui_draw_rect(SDL_Renderer *rend, t_rect rect, int color)
{
	ui_set_draw_color(rend, color);
	SDL_RenderDrawRect(rend, (SDL_Rect*)&rect);
}

void	ui_fill_rect(SDL_Renderer *rend, t_rect rect, int bg_color, int border_color)
{
	ui_set_draw_color(rend, bg_color);
	SDL_RenderFillRect(rend, (SDL_Rect*)&rect);
	ui_set_draw_color(rend, border_color);
	if (bg_color != border_color)
		SDL_RenderDrawRect(rend, (SDL_Rect*)&rect);
}

void	ui_draw_curved_rect(SDL_Renderer *rend, t_rect rect, int radius, int color)
{
	int		i;
	t_dot	points[8];

	points[0] = (t_dot){rect.x + radius, rect.y};
	points[1] = (t_dot){rect.x + rect.w - radius, rect.y};
	points[2] = (t_dot){rect.x + rect.w, rect.y + radius};
	points[3] = (t_dot){rect.x + rect.w, rect.y + rect.h - radius};
	points[4] = (t_dot){rect.x + rect.w - radius, rect.y + rect.h};
	points[5] = (t_dot){rect.x + radius, rect.y + rect.h};
	points[6] = (t_dot){rect.x, rect.y + rect.h - radius};
	points[7] = (t_dot){rect.x, rect.y + radius};
	ui_set_draw_color(rend, color);
	i = 0;
	while (i < 8)
	{
		SDL_RenderDrawLine(rend, points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
		i += 2;
	}
	ui_draw_circle(rend, (t_dot){points[1].x, points[2].y}, radius, color, UI_UPRIGHT_CORNER);
	ui_draw_circle(rend, (t_dot){points[4].x, points[3].y}, radius, color, UI_DOWNRIGHT_CORNER);
	ui_draw_circle(rend, (t_dot){points[5].x, points[6].y}, radius, color, UI_DOWNLEFT_CORNER);
	ui_draw_circle(rend, (t_dot){points[0].x, points[7].y}, radius, color, UI_UPLEFT_CORNER);
}

void	ui_fill_curved_rect(SDL_Renderer *rend, t_rect rect, int radius, int bg_color, int border_color)
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
	ui_fill_circle(rend, (t_dot){points[1].x, points[2].y}, radius, bg_color, border_color, UI_UPRIGHT_CORNER);
	ui_fill_circle(rend, (t_dot){points[4].x, points[3].y}, radius, bg_color, border_color, UI_DOWNRIGHT_CORNER);
	ui_fill_circle(rend, (t_dot){points[5].x, points[6].y}, radius, bg_color, border_color, UI_DOWNLEFT_CORNER);
	ui_fill_circle(rend, (t_dot){points[0].x, points[7].y}, radius, bg_color, border_color, UI_UPLEFT_CORNER);
	ui_set_draw_color(rend, border_color);
	i = 0;
	while (i < 8)
	{
		SDL_RenderDrawLine(rend, points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
		i += 2;
	}
	ui_fill_rect(rend, (t_rect){rect.x + 1, rect.y + radius + 1, radius, rect.h - radius * 2 - 1}, bg_color, bg_color);
	ui_fill_rect(rend, (t_rect){rect.x + rect.w - radius, rect.y + radius + 1, radius, rect.h - radius * 2 - 1}, bg_color, bg_color);
	ui_fill_rect(rend, (t_rect){rect.x + radius + 1, rect.y + 1, rect.w - radius * 2 - 1, rect.h - 1}, bg_color, bg_color);
}