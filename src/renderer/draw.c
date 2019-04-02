#include "SDL.h"
#include "ui_error.h"
#include "ui_frame.h"
#include "libft.h"
#include "ui_texture.h"
#include "ui_struct_2d.h"
#include "ui_draw.h"

static void 	ui_sort_triangle(t_dot p[3])
{
	int		i;
	int		j;
	int		pos;
	int		tmp;

	i = 0;
	while (i < 3)
	{
		j = 0;
		pos = 0;
		tmp = p[i].x;
		while (j < 3)
		{
			if (tmp > p[j].x)
				pos++;
			j++;
		}
		ft_swap(&(p[i].x), &(p[pos].x));
		ft_swap(&(p[i].y), &(p[pos].y));
		i++;
	}
}

double	ui_get_slope(t_dot p1, t_dot p2)
{
	return ((double)(p2.y - p1.y) / (double)(p2.x - p1.x));
}

void	ui_draw_triangle(SDL_Renderer *rend, t_triangle	triangle, int color)
{
	double	a1;
	double	a2;
	double	a3;
	t_dot	p[3];
	int		x;
	double	y1;
	double	y2;

	p[0] = triangle.p1;
	p[1] = triangle.p2;
	p[2] = triangle.p3;
	ui_sort_triangle(p);
	a1 = ui_get_slope(p[0], p[1]);
	a2 = ui_get_slope(p[0], p[2]);
	a3 = ui_get_slope(p[1], p[2]);
	x = p[0].x;
	y1 = p[0].y;
	y2 = p[0].y;
	ui_set_draw_color(rend, color);
	while (x <= p[2].x)
	{
		SDL_RenderDrawLine(rend, x, y1, x, y2);
		x++;
		if (x > p[1].x)
			a1 = a3;
		y1 += a1;
		y2 += a2;
	}
}


t_dot	ui_translate_dx(t_dot dot, double a, int dx)
{
	t_dot	ndot;

	ndot.x = dot.x + dx;
	ndot.y = dot.y + dx * a;
	return (ndot);
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
