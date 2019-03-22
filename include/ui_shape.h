#ifndef SHAPE_H
# define SHAPE_H

typedef struct		s_rect
{
	int				x;
	int				y;
	int				w;
	int				h;
}					t_rect;

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

#endif
