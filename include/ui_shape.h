#ifndef SHAPE_H
# define SHAPE_H

typedef struct	s_dot
{
	int			x;
	int			y;
}				t_dot;

typedef struct	s_line
{
	t_dot		d1;
	t_dot		d2;
}				t_line;

typedef struct	s_rect
{
	int			x;
	int			y;
	int			w;
	int			h;
}				t_rect;

typedef struct	s_frect
{
	double		x;
	double		y;
	double		w;
	double		h;
}				t_frect;


int				ui_is_dot_in_rect(t_dot dot, t_rect rect);

#endif