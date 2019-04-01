#ifndef SHAPE_H
# define SHAPE_H

#include "ui_struct_2d.h"

typedef struct		s_line
{
	t_dot			p1;
	t_dot			p2;
}					t_line;


typedef struct		s_rect
{
	int				x;
	int				y;
	int				w;
	int				h;
}					t_rect;

typedef struct		s_curved_rect
{
	int				x;
	int				y;
	int				w;
	int				h;
	int				radius;
}					t_curved_rect;

typedef struct		s_frect
{
	double			x;
	double			y;
	double			w;
	double			h;
}					t_frect;

typedef struct		s_circle
{
	int				x;
	int				y;
	unsigned int	radius;
}					t_circle;

typedef struct	s_triangle
{
	t_dot		p1;
	t_dot		p2;
	t_dot		p3;
}				t_triangle;

#endif
