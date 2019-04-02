#include "ui_shape.h"
#include "ui_struct_2d.h"
#include "ui_renderer.h"
#include "SDL.h"
#include "ui_draw.h"

void	ui_draw_line(SDL_Renderer *rend, t_line line, int width, int color)
{
	int		x;
	double	y1;
	double	y2;
	t_dot	dot[4];
	t_dot	tmp;
	double	a1;
	double	a2;
	double	dx;
	double	curr_m1;
	double	curr_m2;

	if (line.p2.x < line.p1.x)
	{
		tmp = line.p1;
		line.p1 = line.p2;
		line.p2 = tmp;
	}
	a1 = ui_get_slope(line.p1, line.p2);
	a2 = -1 / a1;
	dx = cos(atan(a2)) * width;
	dot[0] = line.p1;
	dot[1] = ui_translate_dx(dot[0], a2, dx);
	dot[2] = line.p2;
	dot[3] = ui_translate_dx(dot[2], a2, dx);
	ui_set_draw_color(rend, color);
	if (a1 == 0)
		SDL_RenderFillRect(rend, &(SDL_Rect){line.p1.x, line.p1.y, line.p2.x - line.p1.x, width});
	else
	{
		x = dot[0].x;
		y1 = dot[0].y;
		y2 = dot[0].y;
		curr_m1 = a2;
		curr_m2 = a1;
		while (x < dot[3].x - 1)
		{
			SDL_RenderDrawLine(rend, x, y1, x, y2);
			x++;
			if (x == dot[1].x)
				curr_m1 = (curr_m1 == a1) ? a2 : a1;
			else if (x == dot[2].x)
				curr_m2 = (curr_m2 == a1) ? a2 : a1;
			y1 += curr_m1;
			y2 += curr_m2;
		}
	}
}
