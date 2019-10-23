#ifndef SHAPE_H
# define SHAPE_H

typedef struct	s_dot
{
	int			x;
	int			y;
}				ui_dot;


typedef struct	s_rect
{
	int			x;
	int			y;
	int			w;
	int			h;
}				ui_rect;

typedef struct	s_frect
{
	double		x;
	double		y;
	double		w;
	double		h;
}				ui_frect;


int		ui_is_dot_in_rect(ui_dot dot, ui_rect rect);

#endif