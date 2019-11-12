#include "ui_shape.h"

int		ui_is_dot_in_rect(t_dot dot, t_rect rect)
{
	return (dot.x >= rect.x
			&& dot.x < rect.x + rect.w
			&& dot.y >= rect.y
			&& dot.y < rect.y + rect.h);
}
